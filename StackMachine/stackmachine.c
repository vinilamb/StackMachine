#include "stackmachine.h"

void sm_init(struct stack_machine* sm)
{
	for (int i = 0; i < STACK_MAX; i++)
		sm->stack[i] = 0;
	sm->$r = 0;
	sm->pc = -1;
}

_Bool sm_push(struct stack_machine* sm, word_t w)
{
	if (sm->pc < STACK_MAX - 1)
	{
		sm->pc = sm->pc + 1;
		sm->stack[sm->pc] = w;
		return true;
	}
	else
	{
		return false;
	}
}

_Bool sm_pop(struct stack_machine* sm)
{
	if (sm->pc >= 0)
	{
		sm->pc = sm->pc - 1;
		return true;
	}
	else
	{
		return false;
	}
}

void sm_print_stack(struct stack_machine* sm)
{
	printf("$R = %d\n", sm->$r);
	if (sm->pc == -1)
	{
		printf("Stack empty!\n");
	}
	else
	{
		for (int i = 0; i <= sm->pc; i++)
		{
			printf("%3d: %d\n", i, sm->stack[i]);
		}
	}
}