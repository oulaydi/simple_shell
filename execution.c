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

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("FORK_ERR:");
		exit(1);
	}

	if (child_pid == 0)
	{
		if (execve(command[0], command, NULL) == -1)
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
}
