#include "shell.h"

/**
* execution - execute the command with execve
* @command: command to be executed with args
* Return: Void
*/

void execution(char **command)
{
	pid_t child_pid;
	int stats;
	char *command_path;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("FORK_ERR:");
		exit(0);
	}

	if (child_pid == 0)
	{
		command_path = exec_path(command[0]);
		if (execve(command_path, command, environ) == -1)
		{
			perror("ERR:");
			exit(127);
		}
	}
	else
	{
		wait(&stats);
		if (WIFEXITED(stats))
		{
			stats = WEXITSTATUS(stats);
		}
	}

	free(command);
}
