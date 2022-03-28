#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "stackmachine.h"

struct statement
{
	opcode_t op;
	word_t push_number;
	_Bool push_$r;
};

enum parse_error_code
{

};

typedef enum parse_error_code E_PARSE_ERROR;

_Bool parse_statement(struct statement* statement, char* strToParse);