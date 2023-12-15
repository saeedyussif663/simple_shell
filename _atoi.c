#include "shell.h"

/**
 * interactive - confirms interactiveness
 * @info: the location of the sturcture
 * Return: successfull 0 or 1.
 */
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - is it a  delimeter
 * @c: the characterk
 * @delim: the delim
 * Return: success.
 */
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);

return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
 *_atoi - string converter.
 *@s: the victim
 *Return: success.
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

