#include "parser.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Intepreta um comand na assembly da máquina de pilha.
// Retorna um código que informa se o comando foi válido, ou o tipo
// de erro caso não for.
enum parse_result parse_statement(struct statement* statement, char* strToParse)
{
	// Percorremos a string linearmante letra por letra. p é o nosso ponteiro
	// para a letra atual.
	char* p = strToParse;

	// pula espaços
	while (*p == ' ') p++;

	// o statement tem apenas comentário, sem instrução
	if (*p == ';')
		return PARSE_COMMENTONLY;

	// procura a instrução (sequencia de letras)
	char* opNameStart = p;
	while (isalpha(*p)) p++;

	// não tinha instrução
	if (opNameStart == p)
		return PARSE_MISSING_OP;
	
	// descobre o código da operação
	opcode_t op = substr_to_op(opNameStart, p - opNameStart);
	if (op == BAD_OP)
		return PARSE_MISSING_OP;

	// instrução sem argumentos
	if (op != PUSH)
	{
		statement->op = op;
		statement->push_$r = false;
		goto check_comment;
	}

	// procura o argumento da PUSH
	while (*p == ' ') p++;
	if (!strncmp(p, "$r", 2) || !strncmp(p, "$R", 2))
	{
		// arg era registro
		statement->op = op;
		statement->push_$r = true;
		goto check_comment;
	}

	char* argNumStart = p;
	while (isdigit(*p)) p++;
	if (argNumStart == p)
		return PARSE_UNCOMMENTED;

	statement->op = op;
	statement->push_$r = false;
	statement->push_number = strtoul(argNumStart, NULL, 0);

check_comment:
	while (*p == ' ') p++;
	if (*p == '\0' || *p == ';' || *p == '\n')
		return PARSE_OK;
	else 
		return PARSE_UNCOMMENTED;
}