
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

/**
* get_dict_node - retrieve a node by key
* @head:dict
* @key:entry key
* Return: node or NULL
*/

dict_t *get_dict_node(dict_t *head, const char *key)
{
if (!head)
return (NULL);

if (!_strcmp(head->key, key))
return (head);
return (get_dict_node(head->next, key));
}

/**
* add_dict_node_end - adds nodes
* @headptr:pointer
* @key:entry key
* @val: entry val
* Return:pointer
*/

dict_t *add_dict_node_end(dict_t **headptr, const char *key, const char *val)
{
dict_t *new;

if (!headptr)
return (NULL);

if (*headptr)
return (add_dict_node_end(&((*headptr)->next), key, val));

new = malloc(sizeof(dict_t));
if (!new)
return (NULL);

new->key = _strdup(key);
new->val = _strdup(val);
new->next = NULL;

*headptr = new;
return (new);
}

