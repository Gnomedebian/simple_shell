#include "shell.h"
/**
*INThandler - fuction shows the prompt
*@sig_n: #signal
*/
void INThandler(int sig_n)
{
	(void)sig_n;
	write(STDOUT_FILENO, "\n($) ", 5);
}
/**
*main - simple shell
*@argc: ac
*@argv: av
*@env: env
*Return: zero
*/
int main(int argc, char **argv, char **env)
{
	char **cmd;
	char *str = NULL;
	size_t bufsize;
	ssize_t line_len;
	ssize_t count;

	int exit_st = 0;
	(void)argc;
	str = NULL;
	bufsize = 0;
	line_len = 0;
	count = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, "#cisfun$ ", 9);
		signal(SIGINT, INThandler);
		line_len = getline(&str, &bufsize, stdin);
		count++;

		if (special_case(str, line_len, &exit_st) == 3)
			continue;

		cmd = split_line(str);

		if (_strcmp("exit", *cmd) == 0)
			built_exit(str, cmd, &exit_st, count);

		else if (_strcmp("env", *cmd) == 0)
			built_env(cmd, env, &exit_st);

		else
			execute_line(argv, cmd, count, env, &exit_st, str);
		fflush(stdin);
	}

	free(str);
	return (0);
}
