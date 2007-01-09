/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: collection_resolver.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_COLLECTION_RESOLVER_H
#define XQP_COLLECTION_RESOLVER_H

#include "../context/context.h"
#include "../util/rchandle.h"
#include "../util/xqp_exception.h"

#include <string>

namespace xqp {

class collection_resolver
{
	/**
	 * Resolve a  collection URI.
	 *
	 * @param base - The base URI that should be used, typically
	 *   typically the URI of the query module 
	 * @param href - The relative URI of the collection. This 
	 *   corresponds to the argument supplied to the collection() 
	 *   function, or NULL.
	 * @param context - The dynamic execution context
	 *
	 * @return - an Iterator over the documents in the collection. 
	 *   The items returned by this iterator must be instances 
	 *   either of xs:anyURI, or of node().  If xs:anyURI values are 
	 *   returned, the corresponding document will be retrieved as 
	 *   if by a call to the doc() function.  This means that the 
	 *   system first checks to see if the document is already 
	 *   loaded, and if not, calls the registered uri_resolver to 
	 *   dereference the URI.  This is the recommended approach to 
	 *   ensure that the resulting collection is stable. However, 
	 *   it has the consequence that the documents will by default 
	 *   remain in memory for the duration of the query.
	 * 
	 *   If the URI is not recognized, the method may either return 
	 *   an empty iterator, in which case no error is reported, or 
	 *   it may throw an exception, in which case the query or 
	 *   transformation fails.  Returning NULL has the same effect 
	 *   as returning an empty iterator. 
   */
	item_iterator resolve(
		std::string const& base,
		std::string const& href,
		context& context)
	throw (xqp_exception);

};

} /* namespace xqp */
#endif /* XQP_COLLECTION_RESOLVER_H */

