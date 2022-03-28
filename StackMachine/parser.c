#include "parser.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

_Bool parse_statement(struct statement* statement, char* strToParse)
{
	char* p = strToParse;
	while (*p == ' ') p++;

	char* opNameStart = p;
	while (isalpha(*p)) p++;

	if (opNameStart == p)
		return false;

	opcode_t op = substr_to_op(opNameStart, p - opNameStart);
	if (op == BAD_OP)
		return false;

	if (op != PUSH)
	{
		while (*p == ' ') p++;
		if (*p == '\0' || *p == ';' || *p == '\n')
		{
			statement->op = op;
			statement->push_$r = false;
			return true;
		}
		else 
		{
			// uncommented text after statement
			return false;
		}
	}

	while (*p == ' ') p++;
	if (!strncmp(p, "$r", 2) || !strncmp(p, "$R", 2))
	{
		statement->op = op;
		statement->push_$r = true;
		return true;
	}

	char* argNumStart = p;
	while (isdigit(*p)) p++;
	if (argNumStart == p)
		return false;

	statement->op = op;
	statement->push_$r = false;
	statement->push_number = strtoul(argNumStart, NULL, 0);
	return true;
}