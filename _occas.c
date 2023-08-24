#include "shell.h"
/**
*special_case - handle special cases.
*@line: store stdin
*@line_len: line len
*@exit_st: exit st
*Return: 0 if does not match any special case
*or 3 if is \n
*/
int special_case(char *line, ssize_t line_len, int *exit_st)
{
	int lenth = 0;
	int j = 0;

	if (line_len == -1 && isatty(STDIN_FILENO) == 1)
	{
		write(1, "\n", 1);
		free(line);
		exit(*exit_st);
	}

	if (line_len == -1 && isatty(STDIN_FILENO) == 0)
	{
		free(line);
		exit(*exit_st);
	}

	if (_strcmp(line, "\n") == 0)
	{
		*exit_st = 0;
		return (3);
	}

	lenth = _strlen(line);

	while (j < lenth - 2)
	{
		if (line[j] != ' ' && line[j] != '\t')
			return (0);
		++j;
	}

	*exit_st = 0;

	if (line[0] == '/')
		return (0);
	return (3);
}
