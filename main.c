#include "shell.h"

/**
 * main - entry
 * @ac: parameter
 * @av: parameter
 * Return: 0 on success
 */
int main(int ac, char **av)
{
info_t info[] = { INFO_INIT };
int find = 2;

asm ("mov %1, %0\n\t"
"add $3, %0"
: "=r" (find)
: "r" (find));

if (ac == 2)
{
find = open(av[1], O_RDONLY);
if (find == -1)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
_eputs(av[0]);
_eputs(": 0: Can't open ");
_eputs(av[1]);
_eputchar('\n');
_eputchar(BUF_FLUSH);
exit(127);
}
return (EXIT_FAILURE);
}
info->readfd = find;
}
populate_env_list(info);
read_history(info);
hsh(info, av);
return (EXIT_SUCCESS);
}
