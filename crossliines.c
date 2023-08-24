#include "shell.h"
/**
*split_line - create double pointer to each string
*@line: stores the stdin input
*Return: array of pointers
*/
char **split_line(char *line)
{
	int i = 0;
	char *token;
	char *token_sh;
	char **wordarr;
	int lenth;

	lenth = _strlen(line);

	wordarr = malloc(sizeof(char *) * (lenth + 1));
	if (wordarr == NULL)
		return (NULL);
	token_sh = strtok(line, "#");
	token = strtok(token_sh, TOK_DELIM);
	while (token != NULL)
	{
		wordarr[i] = malloc(_strlen(token) + 1);
		if (wordarr[i] == NULL)
		{
			free_loop(wordarr);
			return (NULL);
		}
		_strncpy(wordarr[i], token, _strlen(token) + 1);
		token = strtok(NULL, TOK_DELIM);
		i++;
	}
	wordarr[i] = NULL;
	return (wordarr);
}
