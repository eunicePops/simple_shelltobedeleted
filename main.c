#include "main.h"

int main(int argc, char **argv)
{
	int i;
	int status;
	/*char *command = (char *) malloc(MAX_COMMAND_LENGTH * sizeof(char));*/
	char **arguments = (char **) malloc(MAX_ARGUMENTS * sizeof(char *));

	for (i = 0; i < MAX_ARGUMENTS; i++)
	{
		arguments[i] = (char *) malloc(MAX_COMMAND_LENGTH * sizeof(char));
	}

	if (argc > 1)
	{
		for (i = 1; i < argc; i++)
		{
			parse_command(argv[i], arguments);
			execute(arguments);
			if (i < argc - 1)
				free(arguments);
		}
	}
	else
	{
		char *command = (char *) malloc(MAX_COMMAND_LENGTH * sizeof(char));
		do {
			printf("#cisfun$ ");
			fget(command, MAX_COMMAND_LENGTH, stdin);
			parse_command(command, arguments);
			status = execute(arguments);
			free(command);
		} while (status);
		free(command);
	}
	for (i = 0; i < MAX_ARGUMENTS; i++)
	{
		free(arguments[i]);
	}
	free(arguments);

	return (0);
}
