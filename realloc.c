#include "shell.h"

/**
 **_memset - memset
 *@s: parameter
 *@b: parameter
 *@n: parameter
 *Return: pointer
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int j;

for (j = 0; j < n; j++)
s[j] = b;
return (s);
}

/**
 * ffree - free str
 * @pp: strings
 */
void ffree(char **pp)
{
char **b = pp;

if (!pp)
return;
while (*pp)
free(*pp++);
free(b);
}

/**
 * _realloc - reallocate mem
 * @ptr: parameter
 * @old_size: parameter
 * @new_size: parameter
 * Return: pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *q;

if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);

q = malloc(new_size);
if (!q)
return (NULL);

old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
q[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (q);
}
