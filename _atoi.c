#include "shell.h"

/**
 * interactive - interactive?
 * @info: parameter
 * Return: 1
 */
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - delimeter?
 * @c: parameter
 * @delim: parameter
 * Return: 1.
 */
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);

return (0);
}

/**
 *_isalpha - alphabet?
 *@c: parameter
 *Return: 1
 */

int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
 *_atoi - string
 *@s: parameter
 *Return: 1
 */

int _atoi(char *s)
{
int q, c_sig = 1, flag = 0, display;
unsigned int c_rslt = 0;

for (q = 0; s[q] != '\0' && flag != 2; q++)
{
if (s[q] == '-')
c_sig *= -1;

if (s[q] >= '0' && s[q] <= '9')
{
flag = 1;
c_rslt *= 10;
c_rslt += (s[q] - '0');
}
else if (flag == 1)
flag = 2;
}

if (c_sig == -1)

display = -c_rslt;
else
display = c_rslt;

return (display);
}

