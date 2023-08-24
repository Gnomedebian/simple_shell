#include "shell.h"
/**
*_werror - puts char.
*@c: character
*Return: int
*/
int _werror(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}
/**
*print_num - function that print a num with function write
*@count: the number of times you have done a command
*/
void print_num(int count)
{
	int mylen = 1, pow = 1, cnt2;

	cnt2 = count;

	while (cnt2 >= 10)
	{
		cnt2 /= 10;
		pow *= 10;
		++mylen;
	}
	while (mylen >= 1)
	{
		if ((count / pow) < 10)
			_werror(count / pow + '0');
		else
			_werror(((count / pow) % 10 + '0'));
		--mylen;
		pow /= 10;
	}
}
/**
*_error - prints error
*@argv: argv
*@fr: command to print
*@count: number of commands
*@exit_st: exit st
*/
void _error(char **argv, char *fr, int count, int **exit_st)
{
	struct stat st;

	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ":", 2);
	print_num(count);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, fr, _strlen(fr));
	write(STDERR_FILENO, ": ", 2);
	if (stat(fr, &st) == 0 && S_ISDIR(st.st_mode))
	{
		**exit_st = 126;
		if (_strcmp(fr, "..") == 0)
			**exit_st = 127;
		perror("");
	}
	else
	{
		**exit_st = 127;
		write(STDERR_FILENO, "not found\n", 10);
	}
}
