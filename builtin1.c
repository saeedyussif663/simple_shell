#include "shell.h"

/**
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
print_list(info->history);
return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
char *k, e;
int ter;

k = _strchr(str, '=');
if (!k)
return (1);
e = *k;
*k = 0;
ter = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*k = e;
return (ter);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
char *k;

k = _strchr(str, '=');
if (!k)
return (1);
if (!*++k)
return (unset_alias(info, str));

unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
char *k = NULL, *u = NULL;

if (node)
{
k = _strchr(node->str, '=');
for (u = node->str; u <= k; u++)
_putchar(*u);
_putchar('\'');
_puts(k + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
int h = 0;
char *k = NULL;
list_t *node = NULL;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}

for (h = 1; info->argv[h]; h++)
{
k = _strchr(info->argv[h], '=');
if (k)
set_alias(info, info->argv[h]);
else
print_alias(node_starts_with(info->alias, info->argv[h], '='));
}
return (0);
}
