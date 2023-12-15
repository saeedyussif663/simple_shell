#include "shell.h"

/**
 * _myexit - my exit
 * @info: parameter
 *  Return: `
 */
int _myexit(info_t *info)
{
int exit_check;

if (info->argv[1])
{
exit_check = _erratoi(info->argv[1]);
if (exit_check == -1)
{
info->status = 2;
print_error(info, "Illegal number: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}
info->err_num = _erratoi(info->argv[1]);
return (-2);
}
info->err_num = -1;
return (-2);
}

/**
 * _mycd - change dir
 * @info: parameter
 *  Return: 1
 */
int _mycd(info_t *info)
{
char *s, *directory, buffer[1024];
int children_return;

s = getcwd(buffer, 1024);
if (!s)
_puts("TODO: >>getcwd failure emsg here<<\n");
    
if (!info->argv[1])
{
directory = _getenv(info, "HOME=");
if (!directory)
children_return = /* TODO: what should this be? */
chdir((directory = _getenv(info, "PWD=")) ? directory : "/");
        else
children_return = chdir(directory);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(s);
_putchar('\n');
return (1);
}
_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
children_return = /* TODO: what should this be? */
chdir((directory = _getenv(info, "OLDPWD=")) ? directory : "/");
}
else
children_return = chdir(info->argv[1]);

if (children_return == -1)
{
print_error(info, "can't cd to ");
_eputs(info->argv[1]), _eputchar('\n');
}
else
{
_setenv(info, "OLDPWD", _getenv(info, "PWD="));
_setenv(info, "PWD", getcwd(buffer, 1024));
}

    return (0);
}

/**
 * _myhelp - my help
 * @info: parameter
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
char **arg_array;

arg_array = info->argv;
_puts("help call works. Function not yet implemented \n");
if (0)
_puts(*arg_array); /* temp att_unused workaround */
return (0);
}

