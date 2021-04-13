#include  "shell.h"

/**
  * readline - Reads the user input from standard input
  *
  * Return: The line that was read if succesful and NULL if it failed
  */

char *readline(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	int len = 0;

	len = getline(&line, &bufsize, stdin);
	if (len == -1)
	{
		/*
		 * feof is not allowed we will probably need to find another way
		 * to do this
		 */
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("readline");
			return (0);
		}
	}
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';

	return (line);
}
