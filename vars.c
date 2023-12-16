#include "shell.h"

/**
 * is_chain - chain delinmeter?
 * @info: parameter
 * @buf: parameter
 * @p: parameter
 * Return: 1 - chain, else 0
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
size_t a = *p;

if (buf[a] == '|' && buf[a + 1] == '|')
{
buf[a] = 0;
a++;
info->cmd_buf_type = CMD_OR;
}
else if (buf[a] == '&' && buf[a + 1] == '&')
{
buf[a] = 0;
a++;
info->cmd_buf_type = CMD_AND;
}
else if (buf[a] == ';')
{
buf[a] = 0;
info->cmd_buf_type = CMD_CHAIN;
}
else
return (0);

*p = a;
return (1);
}


/**
 * check_chain - checks chaining?
 * @info: parameter
 * @buf: parameter
 * @p: parameter
 * @i: parameter
 * @len: parameter
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
size_t a = *p;

if (info->cmd_buf_type == CMD_AND)
{
if (info->status)
{
buf[i] = 0;
a = len;
}
}
if (info->cmd_buf_type == CMD_OR)
{
if (!info->status)
{
buf[i] = 0;
a = len;
}
}

*p = a;
}


/**
 * replace_alias - replaces alais
 * @info: parameter
 * Return: 1replaced, 0
 */
int replace_alias(info_t *info)
{
int j;
list_t *node;
char *q;

for (j = 0; j < 10; j++)
{
node = node_starts_with(info->alias, info->argv[0], '=');
if (!node)
return (0);
free(info->argv[0]);
q = _strchr(node->str, '=');
if (!q)
return (0);
q = _strdup(q + 1);
if (!q)
return (0);
info->argv[0] = q;
}
return (1);
}

/**
 * replace_vars - replace vars
 * @info: parameter
 * Return: 1 replaced, 0
 */
int replace_vars(info_t *info)
{
int j = 0;
list_t *node;

for (j = 0; info->argv[j]; j++)
{
if (info->argv[j][0] != '$' || !info->argv[j][1])
continue;

if (!_strcmp(info->argv[j], "$?"))
{
replace_string(&(info->argv[j]), _strdup(convert_number(info->status, 10, 0)));
continue;
}
if (!_strcmp(info->argv[j], "$$"))
{
replace_string(&(info->argv[j]), _strdup(convert_number(getpid(), 10, 0)));
continue;
}
node = node_starts_with(info->env, &info->argv[j][1], '=');
if (node)
{
replace_string(&(info->argv[j]), _strdup(_strchr(node->str, '=') + 1));
continue;
}
replace_string(&info->argv[j], _strdup(""));
}
return (0);
}

/**
 * replace_string - replace str
 * @old: parameter
 * @new: parameter
 * Return: 1 Always
 */
int replace_string(char **old, char *new)
{
free(*old);
*old = new;
return (1);
}
