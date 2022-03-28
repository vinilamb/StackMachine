#include "execution.h"
#include <stdio.h>
#include <stdlib.h>

//ADD
_Bool exec_add(SM_t* sm)
{
	word_t op1, op2;
	if (sm->pc < 1)
		return false;
	op1 = sm->stack[sm->pc];
	op2 = sm->stack[sm->pc - 1];
	sm->$r = op1 + op2;
	return true;
}

//SUB
_Bool exec_sub(SM_t* sm)
{
	word_t op1, op2;
	if (sm->pc < 1)
		return false;
	op2 = sm->stack[sm->pc];
	op1 = sm->stack[sm->pc - 1];
	sm->$r = op1 - op2;
	return true;
}

//MUL
_Bool exec_mul(SM_t* sm)
{
	word_t op1, op2;
	if (sm->pc < 1)
		return false;
	op2 = sm->stack[sm->pc];
	op1 = sm->stack[sm->pc - 1];
	sm->$r = op1 * op2;
	return true;
}

//DIV
_Bool exec_div(SM_t* sm)
{
	word_t op1, op2;
	if (sm->pc < 1)
		return false;
	op2 = sm->stack[sm->pc];
	op1 = sm->stack[sm->pc - 1];
	sm->$r = op1 / op2;
	return true;
}

//MOD
_Bool exec_mod(SM_t* sm)
{
	word_t op1, op2;
	if (sm->pc < 1)
		return false;
	op2 = sm->stack[sm->pc];
	op1 = sm->stack[sm->pc - 1];
	sm->$r = op1 % op2;
	return true;
}

//NOT
_Bool exec_not(SM_t* sm)
{
	word_t op;
	if (sm->pc == -1)
		return false;
	op = sm->stack[sm->pc];
	sm->$r = ~op;
}

//OR
_Bool exec_or(SM_t* sm)
{
	word_t op1, op2;
	if (sm->pc < 1)
		return false;
	op2 = sm->stack[sm->pc];
	op1 = sm->stack[sm->pc - 1];
	sm->$r = op1 | op2;
	return true;
}

//AND
_Bool exec_and(SM_t* sm)
{
	word_t op1, op2;
	if (sm->pc < 1)
		return false;
	op2 = sm->stack[sm->pc];
	op1 = sm->stack[sm->pc - 1];
	sm->$r = op1 & op2;
	return true;
}

//MIR
_Bool exec_mir(SM_t* sm)
{
	word_t op1, op2;
	if (sm->pc < 1)
		return false;
	op2 = sm->stack[sm->pc];
	op1 = sm->stack[sm->pc - 1];
	// não sei implementar então não vai fazer nada.
	// sm->$r = op1 & op2; 
	return true;
}

//PUSH WITH ARGUMENT
_Bool exec_push_arg(SM_t* sm, word_t arg)
{
	return sm_push(sm, arg);
}

// PUSH $R
_Bool exec_push_reg(SM_t* sm)
{
	return sm_push(sm, sm->$r);
}

//POP
_Bool exec_pop(SM_t* sm)
{
	return sm_pop(sm);
}

//OUT
_Bool exec_out(SM_t* sm)
{
	if (sm->pc == -1)
		return false;
	printf("%d", sm->stack[sm->pc]);
}

//CLEAR
_Bool exec_clear(SM_t* sm)
{
	sm->pc = -1;
}

_Bool exec_statement(SM_t* sm, struct statement stmt)
{
	switch (stmt.op)
	{
	case ADD: return exec_add(sm);
	case SUB: return exec_sub(sm);
	case MUL: return exec_mul(sm);
	case DIV: return exec_div(sm);
	case MOD: return exec_mod(sm);
	case NOT: return exec_not(sm);
	case AND: return exec_and(sm);
	case OR: return exec_or(sm);
	case MIR: return exec_mir(sm);
	case OUT: return exec_out(sm);
	case CLEAR: return exec_clear(sm);
	case POP: return exec_pop(sm);
	case PUSH: 
		if (stmt.push_$r)
			return exec_push_reg(sm);
		else
			return exec_push_arg(sm, stmt.push_number);
		
	default: return true;
	}
}