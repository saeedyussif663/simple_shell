#include "shell.h"

/**
 **_strncpy - copy str
 *@dest: parameter
 *@src: parameter
 *@n: parameter
 *Return: string
 */
char *_strncpy(char *dest, char *src, int n)
{
int a, be;
char *s = dest;

a = 0;
while (src[a] != '\0' && a < n - 1)
{
dest[a] = src[a];
a++;
}
if (a < n)
{
be = a;
while (be < n)
{
dest[be] = '\0';
be++;
}
}
return (s);
}

/**
 **_strncat - concat str
 *@dest: parameter
 *@src: parameter
 *@n: parameter
 *Return: concat str
 */
char *_strncat(char *dest, char *src, int n)
{
int a, b;
char *s = dest;

a = 0;
b = 0;
while (dest[a] != '\0')
a++;
while (src[b] != '\0' && b < n)
{
dest[a] = src[b];
a++;
b++;
}
if (b < n)
dest[a] = '\0';
return (s);
}

/**
 **_strchr - locate char
 *@s: parameter
 *@c: parameter
 *Return: string
 */
char *_strchr(char *s, char c)
{
do {
if (*s == c)
return (s);
} while (*s++ != '\0');

return (NULL);
}

