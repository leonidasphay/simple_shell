#include "builtins.h"
#include "general.h"

/**
* bin_setenv - sets environment variable
* @info:arguments passed
* @arguments:arguments
* Return:status
*/

int bin_setenv(general_t *info, char **arguments)
{
env_t *var;
char **args = info->tokens + 1, *val;

if (args[0])
{
if (args[1])
{
if (args[2])
{
perrorl("Too many arguments.", *info->tokens, NULL);
info->status = EXIT_FAILURE;
return (info->status);
}
val = args[1];
}
else
{
val = "";
}
var = get_dict_node(info->env, args[0]);
if (var)
{
free(var->val);
var->val = _strdup(val);
}
else
{
add_dict_node_end(&info->env, args[0], val);
}
info->status = EXIT_SUCCESS;
}
else
{
bin_env(info);
}
return (info->status);
}
