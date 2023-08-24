#include "shell.h"
/**
*_which - search for PATH.
*@commands:split args.
*@env: var env.
*Return: full_path or NULL.
*/
char *_which(char **commands, char **env)
{
	list_p *x;
	list_p *pop;

	char *full_path = NULL;
	char *final_path = NULL;
	char *first_part = NULL;
	struct stat st;

	pop = list_path(env);
	x = pop;

	while (x)
	{
		first_part = _strcat(x->dir, "/");
		full_path = _strcat(first_part, commands[0]);
		free(first_part);
		if (stat(full_path, &st) == 0)
		{
			final_path = full_path;
			break;
		}
		free(full_path);
		x = x->next;
	}
	free_list(pop);
	return (final_path);
}
