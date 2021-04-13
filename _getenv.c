#include "shell.h"

/**
 * _getenv - finds the environment variable requested by user
 * Return: value of the environment variable
 */

extern char **environ;

char *_getenv( char *name)
{
	int i, len;
	len = _strlen(name);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], name, len) == 0)
			return (environ[i] + len + 1);
	}
	return (NULL);
}