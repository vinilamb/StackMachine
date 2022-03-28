#pragma once

typedef enum E_OPCODE
{
	BAD_OP,
	ADD,
	SUB,
	MUL,
	DIV,
	MOD,
	NOT,
	OR,
	AND,
	MIR,
	PUSH,
	POP,
	OUT,
	CLEAR,
} opcode_t;

opcode_t str_to_op(char* opNameStr);
opcode_t substr_to_op(char* opNameStr, size_t nLen);
void op_to_str(char* buffer, opcode_t opcode);
