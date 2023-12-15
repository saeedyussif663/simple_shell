#include "shell.h"

/**
 * is_cmd - finds cmd
 * @info: parameter
 * @path: parameter
 * Return: 1 if true
 */
int is_cmd(info_t *info, char *path)
{
struct stat st;

(void)info;
if (!path || stat(path, &st))
return (0);

if (st.st_mode & S_IFREG)
{
return (1);
}
return (0);
}

/**
 * dup_chars - dupls char
 * @pathstr: parameter
 * @start: parameter
 * @stop: parameter
 * Return: pointer buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
static char buf[1024];
int a = 0, b = 0;

for (b = 0, a = start; a < stop; a++)
if (pathstr[a] != ':')
buf[b++] = pathstr[a];
buf[b] = 0;
return (buf);
}

/**
 * find_path - finds path
 * @info: parameter
 * @pathstr: parameter
 * @cmd: parameter
 * Return: path
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
int a = 0, current_position = 0;
char *path;

if (!pathstr)
return (NULL);
if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
{
if (is_cmd(info, cmd))
return (cmd);
}
while (1)
{
if (!pathstr[a] || pathstr[a] == ':')
{
path = dup_chars(pathstr, current_position, a);
if (!*path)
_strcat(path, cmd);
else
{
_strcat(path, "/");
_strcat(path, cmd);
}
if (is_cmd(info, path))
return (path);
if (!pathstr[a])
break;
current_position = a;
}
a++;
}
return (NULL);
}
