#include "shell.h"

/**
 * _erratoi - convert str
 * @s: string
 * Return: 0
 */
int _erratoi(char *s)
{
int j = 0;
unsigned long int result = 0;

if (*s == '+')
s++;

for (j = 0; s[j] != '\0'; j++)
{
if (s[j] >= '0' && s[j] <= '9')
{
result *= 10;
result += (s[j] - '0');

if (result > INT_MAX)
return (-1);
}
else
{
return (-1);
}
}

return (result);
}

/**
 * print_error - print err
 * @info: parameter
 * @estr: parameter
 * Return: 0
 */
void print_error(info_t *info, char *estr)
{
_eputs(info->fname);
_eputs(": ");
print_d(info->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(info->argv[0]);
_eputs(": ");
_eputs(estr);
}

/**
 * print_d - print decimal
 * @input: parameter
 * @fd: parameter
 * Return: num of chars
 */
int print_d(int input, int fd)
{
int (*__putchar)(char) = _putchar;
int j, count = 0;
unsigned int _abs_, curr;

if (fd == STDERR_FILENO)
__putchar = _eputchar;

if (input < 0)
{
_abs_ = -input;
__putchar('-');
count++;
}
else
_abs_ = input;

curr = _abs_;
for (j = 1000000000; j > 1; j /= 10)
{
if (_abs_ / j)
{
__putchar('0' + curr / j);
count++;
}
curr %= j;
}

__putchar('0' + curr);
count++;

return (count);
}

/**
 * convert_number - convert func
 * @num: parameter
 * @base: parameter
 * @flags: parameter
 * Return: str
 */
char *convert_number(long int num, int base, int flags)
{
static char *arr;
static char buff[50];
char sign = 0;
char *ptr;
unsigned long number = num;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
number = -num;
sign = '-';
}

arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buff[49];
*ptr = '\0';

do {
*--ptr = arr[number % base];
number /= base;
} while (number != 0);

if (sign)
*--ptr = sign;

return (ptr);
}

/**
 * remove_comments - func to replace
 * @buf: address
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
int j;

for (j = 0; buf[j] != '\0'; j++)
if (buf[j] == '#' && (!j || buf[j - 1] == ' '))
{
buf[j] = '\0';
break;
}
}
