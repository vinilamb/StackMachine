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

enum parse_result
{
	PARSE_OK,
	PARSE_MISSING_OP,
	PARSE_UNCOMMENTED,
	PARSE_BAD_ARG,
	PARSE_COMMENTONLY,
};

enum parse_result parse_statement(struct statement* statement, char* strToParse);