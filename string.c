#include "shell.h"

/**
 * _strlen - return len str
 * @s: parameter
 * Return: len string
 */
int _strlen(char *s)
{
int j = 0;

if (!s)
return (0);

while (*s++)
j++;
return (j);
}

/**
 * _strcmp - compares string
 * @s1: parameter
 * @s2: parameter
 * Return: either negative, positive or zero
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks needle
 * @haystack: parameter
 * @needle: parameter
 * Return: address char
 */
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
 * _strcat - concats str
 * @dest: parameter
 * @src: parameter
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
char *retvalue = dest;

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (retvalue);
}
