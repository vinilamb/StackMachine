#pragma once

#include <stdlib.h>
#include <string.h>
#include "opcodes.h"

opcode_t str_to_op(char* opNameStr)
{
	int len = strnlen(opNameStr, 10);
	if (len > 5)
		return BAD_OP;

	if (!strcmp(opNameStr, "ADD"))
		return ADD;
	if (!strcmp(opNameStr, "SUB"))
		return SUB;
	if (!strcmp(opNameStr, "MUL"))
		return MUL;
	if (!strcmp(opNameStr, "DIV"))
		return DIV;
	if (!strcmp(opNameStr, "MOD"))
		return MOD;
	if (!strcmp(opNameStr, "NOT"))
		return NOT;
	if (!strcmp(opNameStr, "OR"))
		return OR;
	if (!strcmp(opNameStr, "AND"))
		return AND;
	if (!strcmp(opNameStr, "MIR"))
		return MIR;
	if (!strcmp(opNameStr, "PUSH"))
		return PUSH;
	if (!strcmp(opNameStr, "POP"))
		return POP;
	if (!strcmp(opNameStr, "OUT"))
		return OUT;
	if (!strcmp(opNameStr, "CLEAR"))
		return CLEAR;

	return BAD_OP;
}

opcode_t substr_to_op(char* opNameStr, size_t nLen)
{
	opcode_t op = BAD_OP;
	char* buffer = malloc((nLen+1) + sizeof(char));
	memcpy(buffer, opNameStr, nLen);
	buffer[nLen] = '\0';
	op = str_to_op(buffer);
	free(buffer);
	return op;
}

void op_to_str(char* dest, opcode_t opcode)
{
	switch (opcode)
	{
	case   ADD: strcpy(dest, "ADD");		break;
	case   SUB: strcpy(dest, "SUB");		break;
	case   MUL: strcpy(dest, "MUL");		break;
	case   DIV: strcpy(dest, "DIV");		break;
	case   MOD: strcpy(dest, "MOD");		break;
	case   NOT: strcpy(dest, "NOT");		break;
	case    OR: strcpy(dest, "OR");			break;
	case   AND: strcpy(dest, "AND");		break;
	case   MIR: strcpy(dest, "AND");		break;
	case  PUSH: strcpy(dest, "PUSH");		break;
	case   POP: strcpy(dest, "POP");		break;
	case   OUT: strcpy(dest, "OUT");		break;
	case CLEAR: strcpy(dest, "CLEAR");		break;
	   default: strcpy(dest, "BAD_OP");		break;
	}
}