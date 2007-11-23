/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: plan_visitor.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "plan_visitor.h"
 	
#include "compiler/expression/expr.h"
#include "runtime/sequences/SequencesImpl.h"
#include "runtime/core/item_iterator.h"
#include "runtime/core/constructors.h"
#include "runtime/core/path_iterators.h"
#include "util/tracer.h"
#include "functions/function.h"

#include <iostream>
#include <vector>


using namespace std;
namespace xqp 
{

static uint32_t depth = 0;

/*..........................................
 :  begin visit                            :
 :.........................................*/
bool plan_visitor::begin_visit(expr& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(expr& v)
{
  cout << std::string(depth--, ' ') << TRACE << endl;
}

bool plan_visitor::begin_visit(enclosed_expr& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return true;
}

void plan_visitor::end_visit(enclosed_expr& v)
{
  cout << std::string(depth--, ' ') << TRACE << endl;
	PlanIter_t content = pop_itstack();
	PlanIter_t enclosed = new EnclosedIterator(v.get_loc(), content);
	itstack.push(&*enclosed);
}


bool plan_visitor::begin_visit(expr_list& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	itstack.push(NULL);
	return true;
}


void plan_visitor::end_visit(expr_list& v)
{
  cout << std::string(depth--, ' ') << TRACE << endl;
	vector<PlanIter_t> argv;
	while (true) {
		PlanIter_t it = pop_itstack();
		if (it==NULL) break;
		argv.insert(argv.begin(),it);
	}
	ConcatIterator *cit_h = new ConcatIterator(v.get_loc(), argv);
	itstack.push(cit_h);
}


bool plan_visitor::begin_visit(var_expr& v)
{
  cout << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(var_expr& v)
{
  if (v.kind == var_expr::for_var) {
    var_iterator *v_p = new var_iterator(v.get_varname ()->name (),v.get_loc(), (void *) &v);
    vector<var_iter_t> *map = NULL;
    
    Assert (fvar_iter_map.get ((uint64_t) &v, map));
    map->push_back (v_p);
    itstack.push(v_p);
  } else if (v.kind == var_expr::pos_var) {
    var_iterator *v_p = new var_iterator(v.get_varname ()->name (),v.get_loc(), (void *) &v);
    vector<var_iter_t> *map = NULL;
    Assert (pvar_iter_map.get ((uint64_t) &v, map));
    map->push_back (v_p);
    itstack.push(v_p);
  } else if (v.kind == var_expr::let_var) {
    RefIterator *v_p = new RefIterator(v.get_varname ()->name (),v.get_loc(), (void *) &v);
    vector<ref_iter_t> *map = NULL;
    
    Assert (lvar_iter_map.get ((uint64_t) &v, map));
    map->push_back (v_p);
    itstack.push(v_p);
  }
}

bool plan_visitor::begin_visit(order_modifier& v)
{
  cout << TRACE << endl;
	return true;
}

void plan_visitor::end_visit(order_modifier& v)
{
  cout << TRACE << endl;
}

bool plan_visitor::begin_visit(flwor_expr& v)
{
  cout << TRACE << endl;
  for (vector<rchandle<forlet_clause> >::const_iterator it = v.clause_begin ();
       it != v.clause_end();
       ++it) {
    rchandle<var_expr> vh = (*it)->var_h;
    uint64_t k = (uint64_t) &*vh;
    if (vh->kind == var_expr::for_var) {
      fvar_iter_map.put (k, new vector<var_iter_t>());
      var_expr *pos_vp = &*(*it)->get_pos_var ();
      if (pos_vp != NULL)
        pvar_iter_map.put ((uint64_t) pos_vp, new vector<var_iter_t>());
    } else if (vh->kind == var_expr::let_var)
      lvar_iter_map.put (k, new vector<ref_iter_t>());
  }
	return true;
}


void plan_visitor::end_visit(flwor_expr& v)
{
  cout << TRACE << endl;
  PlanIter_t ret = pop_itstack ();

  PlanIter_t where = NULL;
  if (v.get_where () != NULL)
    where = pop_itstack ();

  vector<FLWORIterator::OrderSpec> orderSpecs;
  for (vector<flwor_expr::orderspec_t>::const_iterator i = v.orderspec_begin ();
       i != v.orderspec_end ();
       i++) {
    flwor_expr::orderspec_t spec = *i;
    orderSpecs.push_back (FLWORIterator::OrderSpec (pop_itstack (), spec.second->empty_mode, spec.second->dir == dir_descending));
  }
  FLWORIterator::OrderByClause *orderby = new FLWORIterator::OrderByClause (orderSpecs, v.get_order_stable ());

  vector<FLWORIterator::ForLetClause> clauses;
  stack<PlanIter_t> inputs;
  for (vector<rchandle<forlet_clause> >::const_iterator it = v.clause_begin ();
       it != v.clause_end();
       ++it)
    inputs.push (pop_itstack ());
  for (vector<rchandle<forlet_clause> >::const_iterator it = v.clause_begin ();
       it != v.clause_end();
       ++it) {
    PlanIter_t input = inputs.top (); inputs.pop ();
    if ((*it)->type == forlet_clause::for_clause) {
      vector<var_iter_t> *var_iters = NULL, *pvar_iters = NULL;
      Assert (fvar_iter_map.get ((uint64_t) & *(*it)->var_h, var_iters));
      var_expr *pos_vp = &* (*it)->get_pos_var ();
      if (pos_vp == NULL)
        clauses.push_back (FLWORIterator::ForLetClause (*var_iters, input));
      else {
        Assert (pvar_iter_map.get ((uint64_t) pos_vp, pvar_iters));
        clauses.push_back (FLWORIterator::ForLetClause (*var_iters, *pvar_iters, input));
      }
    } else if ((*it)->type == forlet_clause::let_clause) {
      vector<ref_iter_t> *var_iters = NULL;
      Assert (lvar_iter_map.get ((uint64_t) & *(*it)->var_h, var_iters));
      clauses.push_back (FLWORIterator::ForLetClause (*var_iters, input, true));
    }
  }
  FLWORIterator *iter =
    new FLWORIterator (v.get_loc (), clauses, where, orderby, ret, false);
  itstack.push (iter);
}


bool plan_visitor::begin_visit(quantified_expr& v)
{
  cout << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(quantified_expr& v)
{
  cout << TRACE << endl;
}


bool plan_visitor::begin_visit(case_clause& v)
{
  cout << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(case_clause& v)
{
  cout << TRACE << endl;
}


bool plan_visitor::begin_visit(typeswitch_expr& v)
{
  cout << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(typeswitch_expr& v)
{
  cout << TRACE << endl;
}


bool plan_visitor::begin_visit(if_expr& v)
{
cout << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(if_expr& v)
{
  cout << TRACE << endl;
	PlanIter_t iterElse = pop_itstack();
	PlanIter_t iterThen = pop_itstack();
	PlanIter_t iterCond = pop_itstack();
	PlanIter_t iterIfThenElse = new IfThenElseIterator(v.get_loc(), iterCond, iterThen, iterElse);
	itstack.push(&*iterIfThenElse);
}


bool plan_visitor::begin_visit(fo_expr& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	itstack.push(NULL);
	return true;
}


void plan_visitor::end_visit(fo_expr& v) {
  cout << std::string(depth--, ' ') << TRACE << endl;

	const function* func_p = v.get_func();
	assert(func_p != NULL);
	const function& func = *func_p;

	vector<PlanIter_t> argv;
	while (true)
  {
		PlanIter_t it_h = pop_itstack();
		if (it_h == NULL)
      break;

		vector<PlanIter_t>::iterator begin = argv.begin();
 		argv.insert(begin, 1, it_h );
	}

  const yy::location& loc = v.get_loc ();
  if (func.validate_args (argv)) {
    PlanIter_t iter = func(loc, argv);
    assert (iter != NULL);
    itstack.push (iter);
  } else {
    ZorbaErrorAlerts::error_alert (error_messages::XPST0017_STATIC_FUNCTION_NOT_FOUND,
                                   error_messages::STATIC_ERROR,
                                   &loc);
  }
}


bool plan_visitor::begin_visit(ft_select_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(ft_contains_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(instanceof_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(treat_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(castable_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(cast_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(validate_expr& v)
{
cout << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(extension_expr& v)
{
cout << TRACE << endl;
	return true;
}


/*******************************************************************************


********************************************************************************/
bool plan_visitor::begin_visit(relpath_expr& v)
{
  cout << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(relpath_expr& v)
{
  cout << TRACE << endl;
}


bool plan_visitor::begin_visit(axis_step_expr& v)
{
  cout << TRACE << endl;

  bool result = true;

  PlanIter_t input = pop_itstack();

  // TODO ??? In this case the input should be the context node
  if (input == NULL)
  {
    input = new var_iterator("context_node", v.get_loc(), &v);
  }

  PlanIter_t axisIte;

  switch (v.getAxis())
  {
  case axis_kind_self:
  {
    axisIte = new SelfAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_child:
  {
    axisIte = new ChildAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_parent:
  {
    axisIte = new ParentAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_descendant:
  {
    axisIte = new DescendantAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_descendant_or_self:
  {
    axisIte = new DescendantSelfAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_ancestor:
  {
    axisIte = new AncestorAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_ancestor_or_self:
  {
    axisIte = new AncestorSelfAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_following_sibling:
  {
    axisIte = new RSiblingAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_following:
  {
    axisIte = new FollowingAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_preceding_sibling:
  {
    axisIte = new LSiblingAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_preceding:
  {
    axisIte = new PrecedingAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_attribute:
  {
    if (v.getTest()->getTestKind() == match_name_test ||
        v.getTest()->getTestKind() == match_attr_test ||
        v.getTest()->getTestKind() == match_xs_attr_test ||
        v.getTest()->getTestKind() == match_anykind_test)
    {
      axisIte = new AttributeAxisIterator(v.get_loc(), input);
    }
    else
    {
      axisIte = new EmptyIterator(v.get_loc());
      result = false;
    }

    break;
  }
  default:
  {
    ZORBA_ERROR_ALERT(
       error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
       error_messages::SYSTEM_ERROR,
       NULL,
       false,
       "Unknown axis kind");
    break;
  }
  }

  itstack.push(axisIte);

  return result;
}


void plan_visitor::end_visit(axis_step_expr& v)
{
  cout << TRACE << endl;
}


/*******************************************************************************


********************************************************************************/
bool plan_visitor::begin_visit(match_expr& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;

  PlanIter_t axisIte = pop_itstack();
  AxisIteratorHelper* axisItep = dynamic_cast<AxisIteratorHelper*>(&*axisIte);
  Assert(axisItep != NULL);

  PlanIter_t matchIte;
  QNameItem_t qname;
  QNameItem_t tname;

  ItemFactory& iFactory = Store::getInstance().getItemFactory();

  if (v.getTestKind() == match_name_test)
  {
    // Note: the attribute axis iterator does not do any filtering based on
    // the node kind, so it is ok to set the principal node kind to elementNode
    // in all cases.
    axisItep->setNodeKind(StoreConsts::elementNode);

    match_wild_t wildKind = v.getWildKind();

    if (wildKind == match_no_wild)
    {
      qname = iFactory.createQName("",
                                    v.getQName()->prefix().c_str(),
                                    v.getQName()->local().c_str());

      matchIte = new NameTestIterator(v.get_loc(), axisIte, qname, wildKind);
    }
    else if (wildKind == match_prefix_wild)
    {
      qname = iFactory.createQName("", "wildcard", v.getWildName().c_str());

      matchIte = new NameTestIterator(v.get_loc(), axisIte, qname, wildKind);
    }
    else if (wildKind == match_name_wild)
    {
      qname = iFactory.createQName("", v.getWildName().c_str(), "wildcard");

      matchIte = new NameTestIterator(v.get_loc(), axisIte, qname, wildKind);
    }
    else
    {
      matchIte = axisIte;
    }
  }
  else
  {
    axisItep->setNodeKind(v.getNodeKind());

    if (v.getQName() != NULL)
    {
      qname = iFactory.createQName("",
                                   v.getQName()->prefix().c_str(),
                                   v.getQName()->local().c_str());
    }

    if (v.getTypeName() != NULL)
    {
      tname = iFactory.createQName("",
                                   v.getTypeName()->prefix().c_str(),
                                   v.getTypeName()->local().c_str());
    }

    matchIte = new KindTestIterator(v.get_loc(), axisIte, qname, tname,
                                    v.getTestKind(), v.getDocTestKind(),
                                    v.getNilledAllowed());
  }

  itstack.push(matchIte);

	return true;
}


void plan_visitor::end_visit(match_expr& v)
{
  cout << TRACE << endl;
}


/*******************************************************************************


********************************************************************************/
bool plan_visitor::begin_visit(doc_expr& v)
{
  cout << TRACE  << endl;
	return true;
}


void plan_visitor::end_visit(doc_expr& v)
{
  cout << TRACE << endl;
}


bool plan_visitor::begin_visit(elem_expr& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(elem_expr& v)
{
  cout << std::string(--depth, ' ') << TRACE << endl;

	PlanIter_t contentIter = NULL;
	PlanIter_t attrIter = NULL;

  ItemFactory& iFactory = Store::getInstance().getItemFactory();

	if (v.get_attrs_expr() != NULL)
		attrIter = pop_itstack();

	if (v.get_content_expr() != NULL)
	{
		contentIter = pop_itstack();
		contentIter = new ElementContentIterator(v.get_loc(), contentIter);
	}

	rchandle<qname_expr> qname = v.get_qname();
  QNameItem_t itemQName = iFactory.createQName("",
                                               qname->prefix().c_str(),
                                               qname->local().c_str());

	PlanIter_t iter = new ElementIterator(v.get_loc(), itemQName, contentIter, attrIter);

	itstack.push(iter);
}


bool plan_visitor::begin_visit(compElem_expr& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(compElem_expr& v)
{
  cout << std::string(--depth, ' ') << TRACE << endl;
}


bool plan_visitor::begin_visit(attr_expr& v)
{
  cout << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(attr_expr& v)
{
  cout << TRACE << endl;

  ItemFactory& iFactory = Store::getInstance().getItemFactory();

	// TODO dynamic qname
	rchandle<qname_expr> qname = v.get_qname();
	QNameItem_t itemQName = iFactory.createQName("",
                                               qname->prefix().c_str(),
                                               qname->local().c_str());

	PlanIter_t valueIter = NULL;
	if (v.get_val_expr() != NULL)
		valueIter = pop_itstack();

	PlanIter_t attrIter = new AttributeIterator(v.get_loc(), itemQName, valueIter);

	itstack.push(&*attrIter);
}


bool plan_visitor::begin_visit(text_expr& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(text_expr& v)
{
  cout << std::string(--depth, ' ') << TRACE << endl;
  xqpStringStore_t content = new xqpStringStore(v.get_text());
	Item_t textNode = zorba::getItemFactory()->createTextNode(content);
	PlanIter_t text = new SingletonIterator(v.get_loc(), textNode);
	itstack.push(text);
}


bool plan_visitor::begin_visit(comment_expr& v)
{
  cout << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(comment_expr& v)
{  
  cout << TRACE << endl;
  PlanIter_t contentIter = NULL;
  
  if (v.get_comment_expr() != NULL )
  {
    
    contentIter = pop_itstack();
    // TODO: handle comment expressions    
  }
  
  PlanIter_t iter = new CommentIterator(v.get_loc(), contentIter);
  itstack.push(iter);  
}


bool plan_visitor::begin_visit(pi_expr& v)
{
  cout << TRACE << endl;
	return true;
}


void plan_visitor::end_visit(pi_expr& v)
{
  cout << TRACE << endl;
}




bool plan_visitor::begin_visit(const_expr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return true;
}

bool plan_visitor::begin_visit(order_expr& v)
{
cout << TRACE << endl;
	return true;
}


/*..........................................
 :  end visit                              :
 :.........................................*/

void plan_visitor::end_visit(ft_select_expr& v)
{
  cout << TRACE << endl;
}

void plan_visitor::end_visit(ft_contains_expr& v)
{
  cout << TRACE << endl;
}

void plan_visitor::end_visit(instanceof_expr& v)
{
  cout << TRACE << endl;
}

void plan_visitor::end_visit(treat_expr& v)
{
  cout << TRACE << endl;
}

void plan_visitor::end_visit(castable_expr& v)
{
  cout << TRACE << endl;
}

void plan_visitor::end_visit(cast_expr& v)
{
  cout << TRACE << endl;
}

void plan_visitor::end_visit(validate_expr& v)
{
  cout << TRACE << endl;
}

void plan_visitor::end_visit(extension_expr& v)
{
  cout << TRACE << endl;
}


void plan_visitor::end_visit(const_expr& v)
{
	cout << std::string(depth--, ' ') << TRACE << endl;
  PlanIter_t it = new SingletonIterator (v.get_loc (), v.get_val ());
  itstack.push (it);
}

void plan_visitor::end_visit(order_expr& v)
{
cout << TRACE << endl;
}



} /* namespace xqp */
