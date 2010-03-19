/*
 * Copyright 2006-2008 The FLWOR Foundation.
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

#include "system/globalenv.h"

#include "types/root_typemanager.h"
#include "types/typeops.h"

#include "compiler/expression/flwor_expr.h"
#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/rewriter/tools/expr_tools.h"

#include "context/static_context.h"

#include "functions/function.h"
#include "functions/library.h"

#include "util/properties.h"

#include "zorbaerrors/Assert.h"


using namespace std;

namespace zorba 
{

static void inferWinCondVarTypes(const flwor_wincond* cond, xqtref_t domainType);

static expr_t wrap_in_num_promotion(expr* arg, xqtref_t oldt, xqtref_t t);

static xqtref_t specialize_numeric(fo_expr* fo, static_context* sctx);

static function* flip_value_cmp(FunctionConsts::FunctionKind kind);


/*******************************************************************************
  Set the type of variables defined in flwor expressions.
********************************************************************************/
RULE_REWRITE_PRE(InferVarTypes) 
{
  return NULL;
}


RULE_REWRITE_POST(InferVarTypes) 
{
  static_context* sctx = rCtx.getStaticContext(node);

  if (node->get_expr_kind() == flwor_expr_kind ||
      node->get_expr_kind() == gflwor_expr_kind) 
  {
    flwor_expr* flwor = dynamic_cast<flwor_expr *>(node);

    // Node: The translator has already set the type of pos_vars, count_vars,
    // wincond_out_pos_vars, and wincond_in_pos_vars to xs:positiveInteger.

    for (ulong i = 0; i < flwor->num_clauses(); ++i) 
    {
      const flwor_clause& c = *(*flwor)[i];

      if (c.get_kind() == flwor_clause::for_clause)
      {
        const for_clause* fc = static_cast<const for_clause *>(&c);

        varref_t var = fc->get_var();
        xqtref_t explicitType = var->get_type();
        xqtref_t domainType = fc->get_expr()->return_type(sctx);
        domainType = TypeOps::prime_type(*domainType);

        if (explicitType == NULL || TypeOps::is_subtype(*domainType, *explicitType))
          var->set_type(domainType);
      }
      else if (c.get_kind() == flwor_clause::let_clause)
      {
        const let_clause* lc = static_cast<const let_clause *>(&c);

        varref_t var = lc->get_var();
        xqtref_t explicitType = var->get_type();
        xqtref_t domainType = lc->get_expr()->return_type(sctx);

        if (explicitType == NULL || TypeOps::is_subtype(*domainType, *explicitType))
          var->set_type(domainType);
      }
      else if (c.get_kind() == flwor_clause::window_clause)
      {
        const window_clause* wc = static_cast<const window_clause *>(&c);

        varref_t var = wc->get_var();
        xqtref_t explicitType = var->get_type();
        xqtref_t domainType = wc->get_expr()->return_type(sctx);

        if (explicitType == NULL || TypeOps::is_subtype(*domainType, *explicitType))
          var->set_type(domainType);

        flwor_wincond* startCond = wc->get_win_start();
        flwor_wincond* stopCond = wc->get_win_stop();

        if (startCond != NULL)
          inferWinCondVarTypes(startCond, domainType);

        if (stopCond != NULL)
          inferWinCondVarTypes(stopCond, domainType);
      }
      else if (c.get_kind() == flwor_clause::group_clause)
      {
        const group_clause* gc = static_cast<const group_clause *>(&c);

        const flwor_clause::rebind_list_t& gvars = gc->get_grouping_vars();
        ulong numGroupVars = gvars.size();

        for (ulong i = 0; i < numGroupVars; ++i)
        {
          gvars[i].second->set_type(gvars[i].first->return_type(sctx));
        }

        const flwor_clause::rebind_list_t& ngvars = gc->get_nongrouping_vars();
        ulong numNonGroupVars = ngvars.size();
        
        for (ulong i = 0; i < numNonGroupVars; ++i)
        {
          xqtref_t domainType = ngvars[i].first->return_type(sctx);
          xqtref_t type = GENV_TYPESYSTEM.create_type(*domainType,
                                                      TypeConstants::QUANT_STAR);
          ngvars[i].second->set_type(type);
        }
      }
    }
  }
  return NULL;
}


static void inferWinCondVarTypes(const flwor_wincond* cond, xqtref_t domainType)
{
  RootTypeManager& RTM = GENV_TYPESYSTEM;

  const flwor_wincond::vars& invars = cond->get_in_vars();
  const flwor_wincond::vars& outvars = cond->get_out_vars();

  TypeConstants::quantifier_t quant = domainType->get_quantifier();

  xqtref_t nextprevType;
  xqtref_t currType;

  if (quant == TypeConstants::QUANT_ONE)
  {
    currType = domainType;
    nextprevType = RTM.create_type(*domainType, TypeConstants::QUANT_QUESTION);
  }
  else if (quant == TypeConstants::QUANT_QUESTION)
  {
    currType = domainType;
    nextprevType = domainType;
  }
  else if (quant == TypeConstants::QUANT_PLUS)
  {
    currType = TypeOps::prime_type(*domainType.getp());
    nextprevType = RTM.create_type(*domainType, TypeConstants::QUANT_QUESTION);
  }
  else
  {
    nextprevType = RTM.create_type(*domainType, TypeConstants::QUANT_QUESTION);
    currType = nextprevType;
  }

  if (invars.curr)
    invars.curr->set_type(currType);

  if (invars.prev)
    invars.prev->set_type(nextprevType);

  if (invars.next)
    invars.next->set_type(nextprevType);

  if (outvars.curr)
    outvars.curr->set_type(currType);

  if (outvars.prev)
    outvars.prev->set_type(nextprevType);

  if (outvars.next)
    outvars.next->set_type(nextprevType);
}


/*******************************************************************************

********************************************************************************/
RULE_REWRITE_PRE(EliminateTypeEnforcingOperations)
{
  fo_expr* fo;

  if ((fo = dynamic_cast<fo_expr *>(node)) != NULL) 
  {
    if (fo->get_func()->getKind() == FunctionConsts::FN_BOOLEAN_1) 
    {
      expr_t arg = fo->get_arg(0, false);
      xqtref_t arg_type = arg->return_type(rCtx.getStaticContext(node));
      if (TypeOps::is_subtype(*arg_type, *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE))
        return arg;
      else
        return NULL;
    }

    if (fo->get_func()->getKind() == FunctionConsts::FN_DATA_1) 
    {
      expr_t arg = fo->get_arg(0, false);
      xqtref_t arg_type = arg->return_type(rCtx.getStaticContext(node));
      if (TypeOps::is_subtype(*arg_type, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR))
        return arg;
      else
        return NULL;
    }
  }

  cast_base_expr* pe;
  // Note: the if cond is true for promote_expr, treat_expr, and cast_expr
  if ((pe = dynamic_cast<cast_base_expr *>(node)) != NULL) 
  {
    expr_t arg = pe->get_input(true);
    xqtref_t arg_type = arg->return_type(rCtx.getStaticContext(node));
    xqtref_t target_type = pe->get_target_type();

    // If arg type is subtype of target type, we can eliminate treat and promote
    // (because they are noops in this case), but not cast (which will actually
    // create a new item with the target type).
    if (TypeOps::is_equal(*arg_type, *target_type) ||
        (node->get_expr_kind() != cast_expr_kind &&
         TypeOps::is_subtype(*arg_type, *target_type)))
      return arg;
    
    xqtref_t arg_ptype = TypeOps::prime_type(*arg_type);
    xqtref_t target_ptype = TypeOps::prime_type(*target_type);

    if (node->get_expr_kind() == cast_expr_kind &&
        TypeOps::is_equal(*arg_ptype, *target_ptype))
    {
      return new treat_expr(node->get_sctx_id(),
                            node->get_loc(),
                            arg,
                            target_type,
                            XPTY0004,
                            false);
    }

    if (node->get_expr_kind() == treat_expr_kind)
    {
      treat_expr* te = dynamic_cast<treat_expr *> (pe);
      if (te->get_check_prime() && TypeOps::is_subtype(*arg_ptype, *target_ptype))
      {
        te->set_check_prime(false);
        return node;
      }
    }
    return NULL;
  }

  return NULL;
}


RULE_REWRITE_POST(EliminateTypeEnforcingOperations)
{
  return NULL;
}


/*******************************************************************************

********************************************************************************/
RULE_REWRITE_PRE(SpecializeOperations)
{
  return NULL;
}


RULE_REWRITE_POST(SpecializeOperations)
{
  const Properties& props = *Properties::instance();

  RootTypeManager& rtm = GENV_TYPESYSTEM;

  static_context* sctx = rCtx.getStaticContext(node);

  if (node->get_expr_kind() == fo_expr_kind) 
  {
    fo_expr* fo = static_cast<fo_expr *>(node);
    const function* fn = fo->get_func();

    if (! fn->specializable())
      return NULL;

    if (fn->getKind() == FunctionConsts::FN_SUM_1 ||
        fn->getKind() == FunctionConsts::FN_SUM_2)
    {
      expr_t argExpr = fo->get_arg(0, false);
      xqtref_t argType = argExpr->return_type(sctx);
      std::vector<xqtref_t> argTypes;  
      argTypes.push_back(argType);

      function* replacement = fn->specialize(sctx, argTypes);
      if (replacement != NULL)
      {
        fo->set_func(replacement);

        if (TypeOps::is_subtype(*argType, *rtm.UNTYPED_ATOMIC_TYPE_STAR))
        {
          expr_t promoteExpr = new promote_expr(argExpr->get_sctx_id(),
                                                argExpr->get_loc(),
                                                argExpr,
                                                rtm.DOUBLE_TYPE_STAR);
          
          fo->set_arg(0, promoteExpr);
        }

        return node;
      }
    }
    else if (fn->getKind() == FunctionConsts::OP_UNARY_MINUS_1 ||
             fn->getKind() == FunctionConsts::OP_UNARY_PLUS_1)
    {
      expr_t argExpr = fo->get_arg(0, false);
      xqtref_t argType = argExpr->return_type(sctx);
      std::vector<xqtref_t> argTypes;  
      argTypes.push_back(argType);

      function* replacement = fn->specialize(sctx, argTypes);
      if (replacement != NULL)
      {
        fo->set_func(replacement);
        return node;
      }
    }
    else if (fo->num_args() == 2) 
    {
      expr* arg0 = fo->get_arg(0, false);
      expr* arg1 = fo->get_arg(1, false);

      xqtref_t t0 = arg0->return_type(sctx);
      xqtref_t t1 = arg1->return_type(sctx);

      if (TypeOps::type_max_cnt(*t0) > 1 || TypeOps::type_max_cnt(*t1) > 1)
        return NULL;

      if (props.specializeNum() && fn->isArithmeticFunction())
      {
        if (! TypeOps::is_numeric_or_untyped(*t0) ||
            ! TypeOps::is_numeric_or_untyped(*t1))
          return NULL;

        if (specialize_numeric(fo, sctx) != NULL)
          return node;
      }
      else if (props.specializeCmp() && fn->isComparisonFunction()) 
      {
        if (fn->isGeneralComparisonFunction())
        {
          std::vector<xqtref_t> argTypes;
          argTypes.push_back(t0);
          argTypes.push_back(t1);
          function* replacement = fn->specialize(sctx, argTypes);
          if (replacement != NULL) 
          {
            fo->set_func(replacement);
            return node;
          }
        }
        else if (fn->isValueComparisonFunction()) 
        {
          xqtref_t string_type = rtm.STRING_TYPE_QUESTION;
          bool string_cmp = true;
          expr_t nargs[2];

          for (int i = 0; i < 2; ++i) 
          {
            expr* arg = (i == 0 ? arg0 : arg1);
            xqtref_t type = (i == 0 ? t0 : t1);

            if (TypeOps::is_subtype(*type, *rtm.UNTYPED_ATOMIC_TYPE_QUESTION)) 
            {
              nargs[i] = new cast_expr(arg->get_sctx_id(),
                                       arg->get_loc(),
                                       arg,
                                       string_type);
            }
            else if (! TypeOps::is_subtype(*type, *string_type)) 
            {
              string_cmp = false;
              break;
            }
          }

          if (string_cmp) 
          {
            for (int i = 0; i < 2; i++)
            {
              if (nargs[i] != NULL)
                fo->set_arg(i, nargs[i]);
            }

            std::vector<xqtref_t> argTypes;
            argTypes.push_back(string_type);
            argTypes.push_back(string_type);
            function* replacement = fn->specialize(sctx, argTypes);
            if (replacement != NULL) 
            {
              fo->set_func(replacement);
              return node;
            } 
          }
          else if (TypeOps::is_numeric(*t0) && TypeOps::is_numeric(*t1)) 
          {
            xqtref_t aType = specialize_numeric(fo, sctx);
            if (aType != NULL)
            {
              if (TypeOps::is_equal(*TypeOps::prime_type(*aType), *rtm.DECIMAL_TYPE_ONE)
                  && TypeOps::is_subtype(*t0, *rtm.INTEGER_TYPE_ONE))
              {
                expr_t tmp = fo->get_arg(0, false);
                fo->set_arg(0, fo->get_arg(1, false));
                fo->set_arg(1, tmp);
                fo->set_func(flip_value_cmp(fo->get_func()->getKind()));
              }

              return node;
            }
          }
        }
      }
    }
  }
  else if (node->get_expr_kind() == flwor_expr_kind ||
           node->get_expr_kind() == gflwor_expr_kind)
  {
    flwor_expr* flworExpr = reinterpret_cast<flwor_expr*>(node);

    bool modified = false;

    ulong numClauses = flworExpr->num_clauses();
    for (ulong i = 0; i < numClauses; ++i)
    {
      if ((*flworExpr)[i]->get_kind() == flwor_clause::order_clause)
      {
        orderby_clause* obc = reinterpret_cast<orderby_clause*>
                              (flworExpr->get_clause(i, false));

        ulong numColumns = obc->num_columns();
        for (ulong j = 0; j < numColumns; ++j)
        {
          expr* colExpr = obc->get_column_expr(j);
          xqtref_t colType = colExpr->return_type(sctx);

          if (TypeOps::is_subtype(*colType, *rtm.UNTYPED_ATOMIC_TYPE_STAR))
          {
            expr_t castExpr = new cast_expr(colExpr->get_sctx_id(),
                                            colExpr->get_loc(),
                                            colExpr,
                                            rtm.STRING_TYPE_QUESTION);

            obc->set_column_expr(j, castExpr);
            modified = true;
          }
        }
      }
    }

    if (modified)
      return node;
  }

  return NULL;
}


static xqtref_t specialize_numeric(fo_expr* fo, static_context* sctx)
{
  const function* fn = fo->get_func();
  expr* arg0 = fo->get_arg(0, false);
  expr* arg1 = fo->get_arg(1, false);
  xqtref_t t0 = arg0->return_type(sctx);
  xqtref_t t1 = arg1->return_type(sctx);

  xqtref_t aType = 
  TypeOps::arithmetic_type(*t0,
                           *t1,
                           fn->arithmeticKind() == ArithmeticConsts::DIVISION);
  
  if (!TypeOps::is_numeric(*aType))
  {
    return NULL;
  }

  std::vector<xqtref_t> argTypes;  
  argTypes.push_back(aType);
  argTypes.push_back(aType);
  
  function* replacement = fn->specialize(sctx, argTypes);
  if (replacement != NULL) 
  {
    fo->set_func(replacement);

    expr_t newArg0 = wrap_in_num_promotion(arg0, t0, aType);
    expr_t newArg1 = wrap_in_num_promotion(arg1, t1, aType);

    if (newArg0 != NULL)
      fo->set_arg(0, newArg0);

    if (newArg1 != NULL)
      fo->set_arg(1, newArg1);
 
    return aType;
  }

  return NULL;
}


static expr_t wrap_in_num_promotion(expr* arg, xqtref_t oldt, xqtref_t t) 
{
  if (TypeOps::is_subtype(*oldt, *t))
    return NULL;

  if (arg->get_expr_kind() == promote_expr_kind && TypeOps::type_max_cnt(*t) <= 1)
  {
    promote_expr* pe = static_cast<promote_expr*>(arg);
    xqtref_t peType = pe->get_target_type();
    if (TypeOps::is_equal(*peType, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION))
      arg = pe->get_input(false);
  }

  return new promote_expr(arg->get_sctx_id(), arg->get_loc(), arg, t);
}


static function* flip_value_cmp(FunctionConsts::FunctionKind kind) 
{
  FunctionConsts::FunctionKind newKind;

  switch (kind)
  {
  case FunctionConsts::OP_VALUE_EQUAL_DOUBLE_2:
  case FunctionConsts::OP_VALUE_EQUAL_FLOAT_2:
  case FunctionConsts::OP_VALUE_EQUAL_DECIMAL_2:
  case FunctionConsts::OP_VALUE_EQUAL_INTEGER_2:
    newKind = kind;
    break;

  case FunctionConsts::OP_VALUE_NOT_EQUAL_DOUBLE_2:
  case FunctionConsts::OP_VALUE_NOT_EQUAL_FLOAT_2:
  case FunctionConsts::OP_VALUE_NOT_EQUAL_DECIMAL_2:
  case FunctionConsts::OP_VALUE_NOT_EQUAL_INTEGER_2:
    newKind = kind;
    break;

  case FunctionConsts::OP_VALUE_LESS_EQUAL_DOUBLE_2:
    newKind = FunctionConsts::OP_VALUE_GREATER_EQUAL_DOUBLE_2;
    break;
  case FunctionConsts::OP_VALUE_LESS_EQUAL_FLOAT_2:
    newKind = FunctionConsts::OP_VALUE_GREATER_EQUAL_FLOAT_2;
    break;
  case FunctionConsts::OP_VALUE_LESS_EQUAL_DECIMAL_2:
    newKind = FunctionConsts::OP_VALUE_GREATER_EQUAL_DECIMAL_2;
    break;
  case FunctionConsts::OP_VALUE_LESS_EQUAL_INTEGER_2:
    newKind = FunctionConsts::OP_VALUE_GREATER_EQUAL_INTEGER_2;
    break;

  case FunctionConsts::OP_VALUE_LESS_DOUBLE_2:
    newKind = FunctionConsts::OP_VALUE_GREATER_DOUBLE_2;
    break;
  case FunctionConsts::OP_VALUE_LESS_FLOAT_2:
    newKind = FunctionConsts::OP_VALUE_GREATER_FLOAT_2;
    break;
  case FunctionConsts::OP_VALUE_LESS_DECIMAL_2:
    newKind = FunctionConsts::OP_VALUE_GREATER_DECIMAL_2;
    break;
  case FunctionConsts::OP_VALUE_LESS_INTEGER_2:
    newKind = FunctionConsts::OP_VALUE_GREATER_INTEGER_2;
    break;

  case FunctionConsts::OP_VALUE_GREATER_EQUAL_DOUBLE_2:
    newKind = FunctionConsts::OP_VALUE_LESS_EQUAL_DOUBLE_2;
    break;
  case FunctionConsts::OP_VALUE_GREATER_EQUAL_FLOAT_2:
    newKind = FunctionConsts::OP_VALUE_LESS_EQUAL_FLOAT_2;
    break;
  case FunctionConsts::OP_VALUE_GREATER_EQUAL_DECIMAL_2:
    newKind = FunctionConsts::OP_VALUE_LESS_EQUAL_DECIMAL_2;
    break;
  case FunctionConsts::OP_VALUE_GREATER_EQUAL_INTEGER_2:
    newKind = FunctionConsts::OP_VALUE_LESS_EQUAL_INTEGER_2;
    break;

  case FunctionConsts::OP_VALUE_GREATER_DOUBLE_2:
    newKind = FunctionConsts::OP_VALUE_LESS_DOUBLE_2;
    break;
  case FunctionConsts::OP_VALUE_GREATER_FLOAT_2:
    newKind = FunctionConsts::OP_VALUE_LESS_FLOAT_2;
    break;
  case FunctionConsts::OP_VALUE_GREATER_DECIMAL_2:
    newKind = FunctionConsts::OP_VALUE_LESS_DECIMAL_2;
    break;
  case FunctionConsts::OP_VALUE_GREATER_INTEGER_2:
    newKind = FunctionConsts::OP_VALUE_LESS_INTEGER_2;
    break;

  default:
    ZORBA_ASSERT(false);
  }

  return BuiltinFunctionLibrary::getFunction(newKind);
}


}
/* vim:set ts=2 sw=2: */
