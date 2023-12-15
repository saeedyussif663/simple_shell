#include "shell.h"

/**
 *_eputs - print string
 * @str: str
 * Return: Nothing
 */
void _eputs(char *str)
{
int j = 0;

if (!str)
return;
while (str[j] != '\0')
{
_eputchar(str[j]);
j++;
}
}

/**
 * _eputchar - write char
 * @c: parameter
 * Return: 1
 */
int _eputchar(char c)
{
static int j;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)
{
write(2, buf, j);
j = 0;
}
if (c != BUF_FLUSH)
buf[j++] = c;
return (1);
}

/**
 * _putfd - writes char
 * @c: parameter
 * @fd: parameter
 * Return: 1
 */
int _putfd(char c, int fd)
{
static int j;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)
{
write(fd, buf, j);
j = 0;
}
if (c != BUF_FLUSH)
buf[j++] = c;
return (1);
}

/**
 *_putsfd - print str
 * @str: parameter
 * @fd: parameter
 * Return: num
 */
int _putsfd(char *str, int fd)
{
int j = 0;

if (!str)
return (0);
while (*str)
{
j += _putfd(*str++, fd);
}
return (j);
}
