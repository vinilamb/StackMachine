#pragma once

#include <stdbool.h>
#include <stdio.h>
#include "opcodes.h"

#define STACK_MAX 128

typedef int word_t;

struct stack_machine
{
	word_t stack[STACK_MAX];
	word_t $r;
	short pc;
};

void sm_init(struct stack_machine* sm);
_Bool sm_push(struct stack_machine* sm, word_t w);
_Bool sm_pop(struct stack_machine* sm);

void sm_print_stack(struct stack_machine* sm);