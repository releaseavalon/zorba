/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: collation_resolver.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_COLLATION_RESOLVER_H
#define XQP_COLLATION_RESOLVER_H

#include <string>
#include "comparator.h"
#include "../util/rchandle.h"

namespace xqp {

class collation_resolver
{
	/**
	 * Resolve a collation URI (expressed as a string) and return 
	 * the corresponding collation. 
	 *
	 * @param uri - the collation URI
	 *
	 * @return - a comparator representing the collation to be used.
	 *   If the collation URI cannot be resolved, return NULL.
   */
	rchandle<comparator> resolve(
		std::string const& uri);
}

} /* namespace xqp */
#endif /* XQP_COLLATION_RESOLVER_H */


