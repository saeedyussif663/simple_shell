#include "shell.h"

/**
 * _strcpy - copies string
 * @dest: parameter
 * @src: parameter
 * Return: pointer dest
 */
char *_strcpy(char *dest, char *src)
{
int j = 0;

if (dest == src || src == 0)
return (dest);
while (src[j])
{
dest[j] = src[j];
j++;
}
dest[j] = 0;
return (dest);
}

/**
 * _strdup - dup string
 * @str: parameter
 * Return: pointer dup string
 */
char *_strdup(const char *str)
{
int len = 0;
char *ret;

if (str == NULL)
return (NULL);
while (*str++)
len++;
ret = malloc(sizeof(char) * (len + 1));
if (!ret)
return (NULL);
for (len++; len--;)
ret[len] = *--str;
return (ret);
}


/**
 *_puts - prints a str
 *@str: parameter
 * Return: void
 */
void _puts(char *str)
{
int j = 0;

if (!str)
return;
while (str[j] != '\0')
{
_putchar(str[j]);
j++;
}
}

/**
 * _putchar - writes a char
 * @c: parameter
 * Return: On success 1.
 */
int _putchar(char c)
{
static int j;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)
{
write(1, buf, j);
j = 0;
}
if (c != BUF_FLUSH)
buf[j++] = c;
return (1);
}
