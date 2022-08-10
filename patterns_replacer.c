#include "general.h"
#include "text.h"
#include "commands.h"

/**
* replacement - replaces
* @info:info
* @index:index
* @string:str
* Return: tmp
*/

char *replacement(general_t *info, int *index, char *string)
{
	char *tmp;
	char symbol;

	(void) index;

	symbol = *string;
	if (symbol != '?' && symbol != '$')
	{
		tmp = replace_env(info, string);
		return (tmp);
	}

	tmp = (symbol == '$') ? to_string(info->pid) :
		to_string(info->status_code);

	return (tmp);
}

/**
* replace_env - replaces env
* @info:info
* @environment:env
* Return: NULL
*/
char *replace_env(general_t *info, char *environment)
{
	char *env;

	(void) info;

	env = _getenv(environment);
	if (env != NULL)
		return (env);

	return (NULL);
}

