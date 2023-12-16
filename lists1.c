#include "shell.h"

/**
 * list_len - length
 * @h:parameter
 * Return: size
 */
size_t list_len(const list_t *h)
{
size_t j = 0;

while (h)
{
h = h->next;
j++;
}
return (j);
}

/**
 * list_to_strings - returns an array
 * @head: parameter
 * Return: array
 */
char **list_to_strings(list_t *head)
{
list_t *node = head;
size_t a = list_len(head), b;
char **strs;
char *str;

if (!head || !a)
return (NULL);

strs = malloc(sizeof(char *) * (a + 1));
if (!strs)
return (NULL);

for (a = 0; node; node = node->next, a++)
{
str = malloc(_strlen(node->str) + 1);
if (!str)
{
for (b = 0; b < a; b++)
free(strs[b]);
free(strs);
return (NULL);
}

str = _strcpy(str, node->str);
strs[a] = str;
}

strs[a] = NULL;
return (strs);
}


/**
 * print_list - print llist
 * @h: parameter
 * Return: size
 */
size_t print_list(const list_t *h)
{
size_t j = 0;

while (h)
{
_puts(convert_number(h->num, 10, 0));
_putchar(':');
_putchar(' ');
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
j++;
}
return (j);
}

/**
 * node_starts_with - return node
 * @node: parameter
 * @prefix: paramter
 * @c: parameter
 * Return: node
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
char *q = NULL;

while (node)
{
q = starts_with(node->str, prefix);
if (q && ((c == -1) || (*q == c)))
return (node);
node = node->next;
}
return (NULL);
}

/**
 * get_node_index - get index
 * @head: parameter
 * @node: parameter
 * Return: node
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
size_t j = 0;

while (head)
{
if (head == node)
return (j);
head = head->next;
j++;
}
return (-1);
}
