#include "shell.h"
/**
*_execute - execute the main shell
*@argv: argv
*@commands: split args
*@count: number of commands
*@env: env
*@exit_st: exit st
*@line: getline buffer
*/
void execute_line(char **argv, char **commands, int count,
		  char **env, int *exit_st, char *line)
{
	pid_t childpid;
	int sts;
	char *fullpath = NULL;
	(void)line;
	childpid = fork();
	if (childpid < 0)
		perror("Error:");
	if (childpid == 0)
	{
		fullpath = commands[0];
		if (**commands != '/' && _strcmp(commands[0], "..") != 0)
			fullpath = _which(commands, env);
		if (fullpath)
		{
			if (access(fullpath, X_OK) == 0)
				execve(fullpath, commands, env);
		}
		_error(argv, commands[0], count, &exit_st);
		free_loop(commands);
		free(line);
		exit(*exit_st);
	}
	else
	{
		wait(&sts);
		free_loop(commands);
		*exit_st = WEXITSTATUS(sts);
	}
}
