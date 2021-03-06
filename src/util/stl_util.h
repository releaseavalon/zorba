/*
 * Copyright 2006-2016 zorba.io
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once
#ifndef ZORBA_STL_UTIL_H
#define ZORBA_STL_UTIL_H

#include <algorithm>
#include <cassert>
#include <cstring>
#include <functional>
#include <iterator>
#include <limits>
#include <set>
#include <stack>

#include <zorba/config.h>
#include <zorba/internal/cxx_util.h>
#include <zorba/internal/ztd.h>

namespace zorba {
namespace ztd {

using internal::ztd::destroy_delete;
using internal::ztd::has_insertion_operator;
using internal::ztd::less;

///////////////////////////////////////////////////////////////////////////////

/**
 * A less-verbose way to iterate over a constant sequence.
 */
#define FOR_EACH(TYPE,IT,SEQ) \
  for ( TYPE::const_iterator IT = (SEQ).begin(); IT != (SEQ).end(); ++IT )

/**
 * A less-verbose way to iterate over a mutable sequence.
 */
#define MUTATE_EACH(TYPE,IT,SEQ) \
  for ( TYPE::iterator IT = (SEQ).begin(); IT != (SEQ).end(); ++IT )

///////////////////////////////////////////////////////////////////////////////

/**
 * A version of std::back_insert_iterator that's suitable as a base-class (the
 * standard one is not).
 *
 * @tparam ContainerType The type of the container to insert into.
 * @tparam DerivedType The type of the class deriving from this.
 */
template<class ContainerType,class DerivedType>
class back_insert_iterator_base :
  public std::iterator<std::output_iterator_tag,void,void,void,void> {
public:
  typedef ContainerType container_type;

  DerivedType& operator*() {
    return *static_cast<DerivedType*>( this );
  }

  DerivedType& operator++() {
    return *static_cast<DerivedType*>( this );
  }

  DerivedType& operator++(int) {
    return *static_cast<DerivedType*>( this );
  }

protected:
  back_insert_iterator_base( ContainerType *c ) : container( c ) {
  }

  /**
   * A pointer is used (rather than a reference) so this class can be copy
   * constructed.
   */
  ContainerType *container;
};

///////////////////////////////////////////////////////////////////////////////

/**
 * Copy of std::equal_to in this namespace so we can specialize it below.
 */
template<typename T>
struct equal_to : std::binary_function<T,T,bool> {
  bool operator()( T const &a, T const &b ) const {
    return a == b;
  }
};

/**
 * Specialization of ztd::equal_to for C strings.
 */
template<>
struct equal_to<char const*> :
  std::binary_function<char const*,char const*,bool>
{
  bool operator()( char const *s1, char const *s2 ) const {
    return std::strcmp( s1, s2 ) == 0;
  }
};

/**
 * Implementation of SGI's %identity extension.
 * See: http://www.sgi.com/tech/stl/identity.html
 */
template<typename T>
struct identity : std::unary_function<T,T> {
  T const& operator()( T const &a ) const {
    return a;
  }
};

/**
 * Implementation of SGI's %select1st extension.
 * See: http://www.sgi.com/tech/stl/select1st.html
 */
template<typename PairType>
struct select1st : std::unary_function<PairType,typename PairType::first_type> {
  typename PairType::first_type const& operator()( PairType const &a ) const {
    return a.first;
  }
};

///////////////////////////////////////////////////////////////////////////////

/**
 * Determines whether the given type \c T is efficiently passed by value.
 */
template<typename T>
struct is_passable_by_value {
  static bool const value =
        ZORBA_TR1_NS::is_arithmetic<T>::value
    ||  ZORBA_TR1_NS::is_enum<T>::value
    ||  ZORBA_TR1_NS::is_pointer<T>::value
    ||  ZORBA_TR1_NS::is_reference<T>::value
    ||  ZORBA_TR1_NS::is_member_function_pointer<T>::value;
};

/**
 * Useful traits when declaring functions.
 * This class is similar to boost::call_traits.
 *
 * @tparam T A type that is used for a function formal argument or return type.
 */
template<typename T,bool = is_passable_by_value<T>::value>
struct call_traits {
  /**
   * A type that is guaranteed to be the most efficient to use as a formal
   * argument.
   */
  typedef T const arg_type;
};

/**
 * Partial specialization for when \c T is not efficiently passed by value.
 */
template<typename T>
struct call_traits<T,false> {
  typedef T const& arg_type;
};

///////////////////////////////////////////////////////////////////////////////

/**
 * Clears the given stack.
 *
 * @tparam T The stack's \c value_type.
 * @param s The stack to clear.
 */
template<typename T> inline
void clear_stack( std::stack<T> &s ) {
  while ( !s.empty() )
    s.pop();
}

/**
 * A less-verbose way to determine whether the given map or set contains a
 * particular element.
 */
template<class ContainerType> inline
bool contains(
    ContainerType const &s,
    typename call_traits<typename ContainerType::key_type>::arg_type v ) {
  return s.find( v ) != s.end();
}

/**
 * Like std::copy(), but copy at most N elements.
 */
template<typename InputIterator, typename SizeType, typename OutputIterator>
inline OutputIterator copy_n( InputIterator first, SizeType count, 
                              OutputIterator result ) {
  for ( SizeType i = 0; i < count; ++i, *result++ = *first++ )
    ;
  return result;
}

/**
 * A less-verbose way to copy the given sequence.
 */
template<class FromSequenceType,class ToSequenceType> inline
void copy_seq( FromSequenceType const &from, ToSequenceType &to ) {
  std::copy( from.begin(), from.end(), std::back_inserter( to ) );
}

/**
 * A less-verbose way to copy the given set.
 */
template<class FromSequenceType,class ToSequenceType> inline
void copy_set( FromSequenceType const &from, ToSequenceType &to ) {
  std::copy( from.begin(), from.end(), std::inserter( to, to.begin() ) );
}

/**
 * Given a seq<T*>, deletes all the elements.
 */
template<class SequenceType> inline
void delete_ptr_seq( SequenceType &seq ) {
  MUTATE_EACH( typename SequenceType, i, seq )
    delete *i;
}

/**
 * Erases all elements in the given container for which the given predicate is
 * \c true.
 *
 * @tparam SequenceType The sequence type.
 * @tparam PredicateType The predicate type.
 * @param seq The sequence to modify.
 * @param pred The predicate to use.
 * @return Returns the number of elements erased.
 */
template<class SequenceType,class PredicateType> inline
typename SequenceType::size_type erase_if( SequenceType &seq,
                                           PredicateType pred ) {
  typename SequenceType::size_type erased = 0;
  for ( typename SequenceType::iterator i = seq.begin(); i != seq.end(); ) {
    if ( pred( *i ) ) {
      i = seq.erase( i );
      ++erased;
    } else
      ++i;
  }
  return erased;
}

/**
 * Erases only the first element in the given sequence for which the given
 * predicate is \c true.
 *
 * @tparam SequenceType The sequence type.
 * @tparam PredicateType The predicate type.
 * @param seq The sequence to modify.
 * @param pred The predicate to use.
 * @return Returns \c true only if an element was erased; \c false otherwise.
 */
template<class SequenceType,class PredicateType> inline
bool erase_1st_if( SequenceType &seq, PredicateType pred ) {
  MUTATE_EACH( typename SequenceType, i, seq ) {
    if ( pred( *i ) ) {
      seq.erase( i );
      return true;
    }
  }
  return false;
}

/**
 * Moves the first element of the first sequence to the back of the second.
 */
template<class FromSequenceType,class ToSequenceType> inline
void move_front_to_back( FromSequenceType &from, ToSequenceType &to ) {
  to.push_back( from.front() );
  from.pop_front();
}

/**
 * Same as std::strdup(3) except it uses C++'s \c new[] rather than malloc(3).
 *
 * @param s The C string to duplicate.
 * @return Returns a copy of \a s.  Deallocation via \c delete[] is the
 * responsibility of the caller.
 */
inline char* new_strdup( char const *s ) {
  return std::strcpy( new char[ std::strlen( s ) + 1 ], s );
}

/**
 * Peeks one iteration ahead of the given iterator.
 *
 * @tparam ContainerType A type that has the nested types of \c const_iterator
 * (which must at least be a forward iterator) and \c value_type.
 * @param i A pointer to the iterator to peek one ahead of.  It is assumed not
 * already to be at <code>c.end()</code>. It is incremented by 1.
 * @return Returns the value at the next iteration or \c value_type() if none.
 */
template<class ContainerType> inline
typename ContainerType::value_type
peek( ContainerType const &c, typename ContainerType::const_iterator *i ) {
  typedef typename ContainerType::value_type value_type;
  typename ContainerType::const_iterator &j = *i;
  return ++j != c.end() ? *j : value_type();
}

/**
 * Peeks one iteration ahead of the given iterator.
 *
 * @tparam ContainerType A type that has the nested types of \c const_iterator
 * (which must at least be a forward iterator) and \c value_type.
 * @param i The iterator to peek one ahead of.  It is assumed not already to be
 * at <code>c.end()</code>.
 * @return Returns the value at the next iteration or \c value_type() if none.
 */
template<class ContainerType> inline
typename ContainerType::value_type
peek( ContainerType const &c, typename ContainerType::const_iterator i ) {
  return peek( c, &i );
}

/**
 * Peeks one iteration behind of the given iterator.
 *
 * @tparam ContainerType A type that has the nested types of \c const_iterator
 * (which must at least be a bidirectional iterator) and \c value_type.
 * @param i A pointer to the iterator to peek one behind.  It is decremented by
 * 1.
 * @return Returns the value at the previous iteration or \c value_type() if
 * none.
 */
template<class ContainerType> inline
typename ContainerType::value_type
peek_behind( ContainerType const &c,
             typename ContainerType::const_iterator *i ) {
  typedef typename ContainerType::value_type value_type;
  typename ContainerType::const_iterator &j = *i;
  return j != c.begin() ? *--j : value_type();
}

/**
 * Peeks one iteration behind of the given iterator.
 *
 * @tparam ContainerType A type that has the nested types of \c const_iterator
 * (which must at least be a bidirectional iterator) and \c value_type.
 * @param i The iterator to peek one behind.
 * @return Returns the value at the previous iteration or \c value_type() if
 * none.
 */
template<class ContainerType> inline
typename ContainerType::value_type
peek_behind( ContainerType const &c,
             typename ContainerType::const_iterator i ) {
  return peek_behind( c, &i );
}

/**
 * A less-verbose way to pop the first element from a sequence.
 */
template<class SequenceType> inline
typename SequenceType::value_type pop_front( SequenceType &seq ) {
  assert( !seq.empty() );
  typename SequenceType::value_type const value( seq.front() );
  seq.pop_front();
  return value;
}

/**
 * A less-verbose way to pop an element from a stack.
 */
template<class StackType> inline
typename StackType::value_type pop_stack( StackType &s ) {
  assert( !s.empty() );
  typename StackType::value_type const value( s.top() );
  s.pop();
  return value;
}

/**
 * A less verbose way to compare the top value of a stack for equality with a
 * given value.
 */
template<class StackType> inline
bool top_stack_equals(
    StackType const &s,
    typename call_traits<typename StackType::value_type>::arg_type v ) {
  return !s.empty() && s.top() == v;
}

///////////////////////////////////////////////////////////////////////////////

template<typename NumericType> inline
typename std::enable_if<ZORBA_TR1_NS::is_arithmetic<NumericType>::value,
                        bool>::type
gt0( NumericType n ) {                  // for completeness
  return n > 0;
}

template<typename NumericType> inline
typename std::enable_if<ZORBA_TR1_NS::is_signed<NumericType>::value,bool>::type
ge0( NumericType n ) {
  return n >= 0;
}

template<typename IntType> inline
typename std::enable_if<ZORBA_TR1_NS::is_unsigned<IntType>::value,bool>::type
ge0( IntType ) {
  return true;
}

inline bool ge0( char c ) {
  return c >= 0;
}

template<typename NumericType> inline
typename std::enable_if<ZORBA_TR1_NS::is_signed<NumericType>::value,bool>::type
lt0( NumericType n ) {
  return n < 0;
}

template<typename IntType> inline
typename std::enable_if<ZORBA_TR1_NS::is_unsigned<IntType>::value,bool>::type
lt0( IntType ) {
  return false;
}

inline bool lt0( char c ) {
  return c < 0;
}

template<typename NumericType> inline
typename std::enable_if<ZORBA_TR1_NS::is_signed<NumericType>::value,bool>::type
le0( NumericType n ) {
  return n <= 0;
}

template<typename IntType> inline
typename std::enable_if<ZORBA_TR1_NS::is_unsigned<IntType>::value,bool>::type
le0( IntType n ) {
  return n == 0;
}

inline bool le0( char c ) {
  return c <= 0;
}

///////////////////////////////////////////////////////////////////////////////

//
// These functions are used to test whether a value of numeric type N1 is
// within the range of another numeric type N2.  It correctly handles the
// cases where the "signed-ness" of N1 and N2 differ such that the code is
// warning-free.
//
// Note: the use of "!!" is to work around a compiler problem on Windows;
// see http://stackoverflow.com/q/9285657
//

template<typename N1,typename N2> inline
typename std::enable_if<(ZORBA_TR1_NS::is_signed<N1>::value ||
                         ZORBA_TR1_NS::is_floating_point<N1>::value)
                     && (ZORBA_TR1_NS::is_signed<N2>::value ||
                         ZORBA_TR1_NS::is_floating_point<N2>::value),
                        bool>::type
ge_min( N1 n1, N2 ) {
  return n1 >= std::numeric_limits<N2>::min();
}

template<typename N1,typename N2> inline
typename std::enable_if<(ZORBA_TR1_NS::is_signed<N1>::value ||
                         ZORBA_TR1_NS::is_floating_point<N1>::value)
                     && !!ZORBA_TR1_NS::is_unsigned<N2>::value,
                         bool>::type
ge_min( N1 n1, N2 ) {
  return n1 >= 0;
}

template<typename N1,typename N2> inline
typename std::enable_if<!!ZORBA_TR1_NS::is_unsigned<N1>::value
                     && (ZORBA_TR1_NS::is_signed<N2>::value ||
                         ZORBA_TR1_NS::is_floating_point<N2>::value),
                        bool>::type
ge_min( N1, N2 ) {
  return true;
}

template<typename N1,typename N2> inline
typename std::enable_if<!!ZORBA_TR1_NS::is_unsigned<N1>::value
                     && !!ZORBA_TR1_NS::is_unsigned<N2>::value,bool>::type
ge_min( N1, N2 ) {
  return true;
}

template<typename N1,typename N2> inline
typename std::enable_if<(ZORBA_TR1_NS::is_signed<N1>::value ||
                         ZORBA_TR1_NS::is_floating_point<N1>::value)
                     && (ZORBA_TR1_NS::is_signed<N2>::value ||
                         ZORBA_TR1_NS::is_floating_point<N2>::value),
                        bool>::type
le_max( N1 n1, N2 ) {
  return n1 <= std::numeric_limits<N2>::max();
}

template<typename N1,typename N2> inline
typename std::enable_if<(ZORBA_TR1_NS::is_signed<N1>::value ||
                         ZORBA_TR1_NS::is_floating_point<N1>::value)
                     && !!ZORBA_TR1_NS::is_unsigned<N2>::value,
                        bool>::type
le_max( N1 n1, N2 ) {
  return n1 <= 0 || static_cast<N2>( n1 ) <= std::numeric_limits<N2>::max();
}

template<typename N1,typename N2> inline
typename std::enable_if<!!ZORBA_TR1_NS::is_unsigned<N1>::value
                     && (ZORBA_TR1_NS::is_signed<N2>::value ||
                         ZORBA_TR1_NS::is_floating_point<N2>::value),
                        bool>::type
le_max( N1 n1, N2 ) {
  return n1 <= static_cast<N1>( std::numeric_limits<N2>::max() );
}

template<typename N1,typename N2> inline
typename std::enable_if<!!ZORBA_TR1_NS::is_unsigned<N1>::value
                     && !!ZORBA_TR1_NS::is_unsigned<N2>::value,bool>::type
le_max( N1 n1, N2 ) {
  return n1 <= std::numeric_limits<N2>::max();
}

#define ZORBA_GE_MIN(N,T) \
  ::zorba::ztd::ge_min( N, static_cast<T>(0) )

#define ZORBA_LE_MAX(N,T) \
  ::zorba::ztd::le_max( N, static_cast<T>(0) )

#define ZORBA_IN_RANGE(N,T) \
  ( ZORBA_GE_MIN(N,T) && ZORBA_LE_MAX(N,T) )

///////////////////////////////////////////////////////////////////////////////

template<typename T> class stack_generator {
  std::stack<T> &stk;
public:
  stack_generator (std::stack<T> &stk_) : stk (stk_) { }
  T operator()() {
    assert( !stk.empty() );
    T const x = stk.top();
    stk.pop();
    return x;
  }
};

template<typename T> inline
stack_generator<T> stack_to_generator(std::stack<T> &stk) {
  return stack_generator<T>( stk );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ztd
} // namespace zorba
#endif  /* ZORBA_STL_UTIL_H */
/* vim:set et sw=2 ts=2: */
