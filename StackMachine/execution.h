#pragma once

#include "stackmachine.h"
#include "parser.h"

_Bool exec_add(struct stack_machine* sm);
_Bool exec_sub(struct stack_machine* sm);
_Bool exec_mul(struct stack_machine* sm);
_Bool exec_div(struct stack_machine* sm);
_Bool exec_mod(struct stack_machine* sm);
_Bool exec_not(struct stack_machine* sm);
_Bool exec_or(struct stack_machine* sm);
_Bool exec_and(struct stack_machine* sm);
_Bool exec_mir(struct stack_machine* sm);
_Bool exec_push_arg(struct stack_machine* sm, word_t arg);
_Bool exec_push_reg(struct stack_machine* sm);
_Bool exec_pop(struct stack_machine* sm);
_Bool exec_out(struct stack_machine* sm);
_Bool exec_clear(struct stack_machine* sm);

_Bool exec_statement(struct stack_machine* sm, struct statement stmt);