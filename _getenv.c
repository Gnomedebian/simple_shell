#include "shell.h"

/**
 * _getenv - gets env path.
 * @name: name of env var.
 * @env: env.
 * Return: value of catched var.
 */
char *_getenv(const char *name, char **env)
{
	int k;
	char *cmp = NULL;

	if (env == NULL)
		return (NULL);

	for (k = 0; env[k]; k++)
	{
		cmp = strtok(env[k], "=");

		if (strcmp(cmp, name) == 0)
		{
			return (strtok(NULL, "\n"));
		}
	}
	return (NULL);
}
