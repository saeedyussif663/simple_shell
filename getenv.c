#include "shell.h"

/**
 * get_environ - get environ
 * @info: parameter
 * Return: Always 0
 */
char **get_environ(info_t *info)
{
if (!info->environ || info->env_changed)
{
info->environ = list_to_strings(info->env);
info->env_changed = 0;
}

return (info->environ);
}

/**
 * _unsetenv - unset environ
 * @info: parameter
 *  Return: 1
 * @var: parameter
 */
int _unsetenv(info_t *info, char *var)
{
list_t *node = info->env;
size_t j = 0;
char *p;

if (!node || !var)
return (0);

while (node)
{
p = starts_with(node->str, var);
if (p && *p == '=')
{
info->env_changed = delete_node_at_index(&(info->env), j);
j = 0;
node = info->env;
continue;
}
node = node->next;
j++;
}
return (info->env_changed);
}

/**
 * _setenv - set environ
 * @info: parameter
 * @var: parameter
 * @value: parameter
 *  Return: Always 0
 */
int _setenv(info_t *info, char *var, char *value)
{
char *buffer = NULL;
list_t *node;
char *q;

if (!var || !value)
return (0);

buffer = malloc(_strlen(var) + _strlen(value) + 2);
if (!buffer)
return (1);
_strcpy(buffer, var);
_strcat(buffer, "=");
_strcat(buffer, value);
node = info->env;
while (node)
{
q = starts_with(node->str, var);
if (q && *q == '=')
{
free(node->str);
node->str = buffer;
info->env_changed = 1;
return (0);
}
node = node->next;
}
add_node_end(&(info->env), buffer, 0);
free(buffer);
info->env_changed = 1;
return (0);
}
