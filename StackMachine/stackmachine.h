#pragma once

#include <stdbool.h>
#include <stdio.h>
#include "opcodes.h"

#define STACK_MAX 128

typedef int word_t;

struct stack_machine_s
{
	word_t stack[STACK_MAX];
	word_t $r;
	short pc;
};

typedef struct stack_machine_s SM_t;

void sm_init(SM_t* sm);
_Bool sm_push(SM_t* sm, word_t w);
_Bool sm_pop(SM_t* sm);

void sm_print_stack(SM_t* sm);