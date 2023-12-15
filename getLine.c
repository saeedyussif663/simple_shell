#include "shell.h"

/**
 * input_buf - buff cmd
 * @info: parameter
 * @buf: parameter
 * @len: parameter
 * Return: bytes
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
ssize_t i = 0;
size_t len_p = 0;

if (!*len)
{
/*bfree((void **)info->cmd_buf);*/
free(*buf);
*buf = NULL;
signal(SIGINT, sigintHandler);
#if USE_GETLINE
i = getline(buf, &len_p, stdin);
#else
i = _getline(info, buf, &len_p);
#endif
if (i > 0)
{
if ((*buf)[i - 1] == '\n')
{
(*buf)[i - 1] = '\0'; /* remove trailing newline */
i--;
}
info->linecount_flag = 1;
remove_comments(*buf);
build_history_list(info, *buf, info->histcount++);
/* if (_strchr(*buf, ';')) is this a command chain? */
{
*len = i;
info->cmd_buf = buf;
}
}
}
return (i);
}

/**
 * get_input - gets input
 * @info: parameter
 * Return: bytes
 */
ssize_t get_input(info_t *info)
{
static char *buffer;
static size_t a, b, length;
ssize_t r = 0;
char **buf_p = &(info->arg), *p;

_putchar(BUF_FLUSH);
r = input_buf(info, &buffer, &length);
if (r == -1)
return (-1);
if (length)
{
b = a;
p = buffer + a;

check_chain(info, buffer, &b, a, length);
while (b < length)
{
if (is_chain(info, buffer, &b))
break;
b++;
}

a = b + 1;
if (a >= length)
{
a = length = 0;
info->cmd_buf_type = CMD_NORM;
}

*buf_p = p;
return (_strlen(p));
}

*buf_p = buffer;
return (r);
}

/**
 * read_buf - read buff
 * @info: parameter
 * @buf: parameter
 * @i: parameter
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
ssize_t ri = 0;

if (*i)
return (0);
ri = read(info->readfd, buf, READ_BUF_SIZE);
if (ri >= 0)
*i = ri;
return (ri);
}

/**
 * _getline - get line
 * @info: parameter
 * @ptr: parameter
 * @length: parameter
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
static char buf[READ_BUF_SIZE];
static size_t a, length;
size_t b;
ssize_t r = 0, s = 0;
char *q = NULL, *new_q = NULL, *c;

q = *ptr;
if (q && length)
s = *length;
if (a == length)
a = length = 0;

r = read_buf(info, buf, &length);
if (r == -1 || (r == 0 && length == 0))
return (-1);

c = _strchr(buf + a, '\n');
b = c ? 1 + (unsigned int)(c - buf) : length;
new_q = _realloc(q, s, s ? s + b : b + 1);
if (!new_q) /* MALLOC FAILURE! */
return (q ? free(q), -1 : -1);

if (s)
_strncat(new_q, buf + a, b - a);
else
_strncpy(new_q, buf + a, b - a + 1);

s += b - a;
a = b;
q = new_q;

if (length)
*length = s;
*ptr = q;
return (s);
}

/**
 * sigintHandler - sign int
 * @sig_num: parameter
 * Return: nothing
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
_puts("\n");
_puts("$ ");
_putchar(BUF_FLUSH);
}
