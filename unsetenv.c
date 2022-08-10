#include "builtins.h"
#include "general.h"

/**
* bin_unsetenv - unsets the environment variable
*@info:arguments
* Return:Status
*/

int bin_unsetenv(general_t *info)
{
	char **args = info->tokens + 1;

	if (*args)
	{
		while (*args)
			del_dict_node(&info->env, *args++);
		info->status = EXIT_SUCCESS;
	}
	else
	{
		perrorl("Too few arguments.", *info->tokens, NULL);
		info->status = EXIT_FAILURE;
	}
	return (info->status);
}
