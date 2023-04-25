#include "main.h"

int (*get_function(char *s))(char **args)
{
	builtin list[] = {
		{"cd", sh_cd},
		{"help", sh_help},
		{"exit", sh_exit},
		{"env", sh_env},
		{"setenv", sh_setenv},
		{"unsetenv", sh_unsetenv},
		{NULL, NULL}
	};
	int i = 0;

	while (list[i].builtin_str != NULL && strcmp(s, list[i].builtin_str) != 0)
	{
		i++;
	}

	return (list[i].builtin_func);
}

int execute(char **args)
{
	if (args[0] == NULL)
	{
		return (1);
	}
	if (get_function(args[0]) == NULL)
	{
		return (launch(args));
	}

	return (get_function(args[0])(args));
}
