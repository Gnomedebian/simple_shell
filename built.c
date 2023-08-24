#include "shell.h"
#include <ctype.h>
#include <string.h>
/**
*num_is_positive - function if # +===-
*@com: verify string
*Return: if success r 0 if fails or nut # r -1
*/
int num_is_positive(char *com)
{
	int k = 0;

	if (com[0] == '-')
		return (-1);
	for (k = 0; com[k]; k++)
	{
		if (com[k] < 48 || com[k] > 57)
		{
			return (-1);
		}
	}
	return (0);
}
/**
*_atoi - char to int
*@com: verify string
*Return: int
*/
int _atoi(char *com)
{
	int j = 0;
	int mark = 1;
	int result = 0;

	for (j = result = 0; com[j]; j++)
	{
		if (com[j] == '-')
			mark *= -1;
		if (com[j] >= '0' && com[j] <= '9')
			result = 10 * result - (com[j] - '0');
		if (result < 0 && (com[j] < '0' || com[j] > '9'))
			break;
	}
	if (mark > 0)
	{
		result *= -1;
	}
	return (result);
}
/**
*built_exit - exit func
*@line: buffer
*@commands: args split
*@exit_st: exit status
*@count: lines count
*/
void built_exit(char *line, char **commands, int *exit_st, int count)
{
	int number = 0;

	if (commands[1])
	{
		if (num_is_positive(commands[1]) == 0)
		{
			number = _atoi(commands[1]);
			*exit_st = number;
		}
		else
		{
			write(1, "./hsh: ", 7);
			print_num(count);
			write(1, ": ", 2);

			write(1, "exit: Illegal number: ", 22);
			write(1, commands[1], _strlen(commands[1]));

			write(1, "\n", 1);
			*exit_st = 2;
			free_loop(commands);
			return;
		}
	}
	free_loop(commands);
	free(line);
	exit(*exit_st);
}

/**
*built_env - env func
*@commands: args split
*@env: env
*@exit_st: exit status
*/
void built_env(char **commands, char **env, int *exit_st)
{
	char **x = env;

	while (*x != NULL)
	{
		write(1, *x, _strlen(*x));
		write(1, "\n", 1);

		x++;
	}

	free_loop(commands);
	*exit_st = 0;
}
