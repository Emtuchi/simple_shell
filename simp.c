#include "shell.h"

/**
 * sigint_stop - stop ctrl c
 * @sig_num: there just to avoid errors
 */

void sigint_stop(int sig_num)
{
	(void)sig_num;

	write(1, "\n", 1);
	write(1, "($) ", 4);
}

/**
 * main - execution stage
 *
 * Return: 0 on success
 */

int main(void)
{
	char *input = NULL;
	size_t size = 1024;
	ssize_t outpt;
	char **argv = NULL;

	/*if ctrl c is typed, it ignores the SIGINT, which ctrl c sends as command and replaces it with our own function(sigint_stop)*/
	signal(SIGINT, sigint_stop);

	while (1)
	{
		if (isatty(STDIN_FILENO))/*check if file is in interactive mode*/
			write(1, "($) ", 4);

		fflush(stdout);
		outpt = getline(&input, &size, stdin);
		if (outpt == -1)/*ctrl d is typed(returns -1)*/
		{
			free(input);
			if (isatty(STDIN_FILENO))/*check if we are in interractive mode, if yes, output \n*/
				write(1, "\n", 1);

			exit(1);
		}

		if (*input == '\n' || *input == '\0')/*if enter key is hit without any string*/
			continue;

		argv = srt_input(input);/*tokenize strings with space as delimiter(function is in a different file*/
		if (!argv || !argv[0])/*if spaces only were inputed, strtok will return NULL cos no command*/
		{
			_free(argv);
			continue;
		}

		execpid(argv, input);/*where my excutions and child processes are*/

		_free(argv);
	}

	return (0);
}

/**
 * execpid - excecut a command
 * @input: inputed string
 * @argv: the command
 *
 * Return: 0 if success and 1 if not
 *
 */

int execpid(char *argv[], char *input)
{
	pid_t pid;
	int parent;
	char *cmd = NULL, *rubbish = argv[0];/*just incase you typed rubbish*/

	if (!*argv)
		exit(-1);

	pid = fork();/*create child process*/

	if (pid == -1)/*error in creation*/
	{
		perror("busted");
		return (1);
	}
	else if (pid == 0)/*if we are in the child process*/
	{
		cmd = get_path(argv[0]);/*check path.c file for this function, arrange a path for the first command i.e /bin/ which will to added to your ls to become /bin/ls*/
		if (cmd == NULL)/*if command isnt executable i.e, you typed rubbish in my shell lol*/
		{
			perror(rubbish);/*remember or variable*/
			free(input);
			_free(argv);
			exit(EXIT_FAILURE);
		}
		else
			execve(cmd, argv, environ);/*execute command if not rubbish*/
	}
	else
	{
		wait(&parent);/*make sure parent process doesnt interfere with child process so make it wait, you could also pass NULL*/
		fflush(stdout);
	}

	return (0);
}
