#include "interactive.h"
#include "parser.h"
#include "stackmachine.h"
#include "execution.h"

#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 100

void launch_interactive_loop(SM_t* sm)
{
	char buffer[BUFF_SIZE];

	printf("Starting interactive!\n");
	printf("Type '!q' to exit the program.\n");

	while (true)
	{
		printf("> ");
		fgets(buffer, BUFF_SIZE, stdin);
		if (!strncmp(buffer, "!q", 2))
		{
			printf("Exiting...\n");
			break;
		}

		struct statement stmt;
		if (parse_statement(&stmt, buffer))
		{
			char opName[10];
			op_to_str(opName, stmt.op);
			_Bool success = exec_statement(sm, stmt);
			if (success)
			{
				sm_print_stack(sm);
			}
			else
			{
				printf("Execute fail\n");
			}
		}
		else
		{
			printf("Parse ERROR\n");
		}
	}

}