#pragma once

#include "stackmachine.h"
#include "parser.h"

_Bool exec_add(SM_t* sm);
_Bool exec_sub(SM_t* sm);
_Bool exec_mul(SM_t* sm);
_Bool exec_div(SM_t* sm);
_Bool exec_mod(SM_t* sm);
_Bool exec_not(SM_t* sm);
_Bool exec_or(SM_t* sm);
_Bool exec_and(SM_t* sm);
_Bool exec_mir(SM_t* sm);
_Bool exec_push_arg(SM_t* sm, word_t arg);
_Bool exec_push_reg(SM_t* sm);
_Bool exec_pop(SM_t* sm);
_Bool exec_out(SM_t* sm);
_Bool exec_clear(SM_t* sm);

_Bool exec_statement(SM_t* sm, struct statement stmt);