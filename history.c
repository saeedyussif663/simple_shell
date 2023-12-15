#include "shell.h"

/**
 * get_history_file - get history
 * @info: parameter
 * Return: allocated string
 */

char *get_history_file(info_t *info)
{
char *buffer, *directory;

directory = _getenv(info, "HOME=");
if (!directory)
return (NULL);

buffer = malloc(sizeof(char) * (_strlen(directory) + _strlen(HIST_FILE) + 2));
if (!buffer)
return (NULL);

buffer[0] = 0;
_strcpy(buffer, directory);
_strcat(buffer, "/");
_strcat(buffer, HIST_FILE);
return (buffer);
}

/**
 * write_history - creates file
 * @info: parameter
 * Return: 1 on success
 */
int write_history(info_t *info)
{
ssize_t file_descriptor;
char *filename = get_history_file(info);
list_t *node = NULL;

if (!filename)
return (-1);

file_descriptor = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(filename);
if (file_descriptor == -1)
return (-1);

for (node = info->history; node; node = node->next)
{
_putsfd(node->str, file_descriptor);
_putfd('\n', file_descriptor);
}
_putfd(BUF_FLUSH, file_descriptor);
close(file_descriptor);
return (1);
}

/**
 * read_history - read history
 * @info: parameter
 * Return: histcount
 */
int read_history(info_t *info)
{
int j, last = 0, count = 0;
ssize_t fd, rdlen, fsize = 0;
struct stat st;
char *buffer = NULL, *filename = get_history_file(info);
if (!filename)
return (0);
fd = open(filename, O_RDONLY);
free(filename);
if (fd == -1)
return (0);
if (!fstat(fd, &st))
fsize = st.st_size;
if (fsize < 2)
return (0);
buffer = malloc(sizeof(char) * (fsize + 1));
if (!buffer)
return (0);
rdlen = read(fd, buffer, fsize);
buffer[fsize] = 0;
if (rdlen <= 0)
return (free(buffer), 0);
close(fd);
for (j = 0; j < fsize; j++)
{
if (buffer[j] == '\n')
{
buffer[j] = 0;
build_history_list(info, buffer + last, count++);
last = j + 1;
}
}
if (last != j)
build_history_list(info, buffer + last, count++);
free(buffer);
info->histcount = count;
while (info->histcount-- >= HIST_MAX)
delete_node_at_index(&(info->history), 0);
renumber_history(info);
return (info->histcount);
}

/**
 * build_history_list - entry
 * @info: parameter
 * @buf: parameter
 * @linecount: count
 * Return: Always 0
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
list_t *node = NULL;

if (info->history)
node = info->history;
add_node_end(&node, buf, linecount);

if (!info->history)
info->history = node;
return (0);
}

/**
 * renumber_history - renumber
 * @info: parameter
 * Return: the new histcount
 */
int renumber_history(info_t *info)
{
list_t *node = info->history;
int j = 0;

while (node)
{
node->num = j++;
node = node->next;
}
return (info->histcount = j);
}
