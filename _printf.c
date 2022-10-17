#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int _printf(const char* format, ...)
{
    int i, j, k, strlen = 0;
    va_list args;

    char* p = NULL;
    char c;
    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        strlen++;
    }

    for (i = 0; i < strlen; i++)
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == 'c')
            {
                c = va_arg(args, int);
                _putchar(c);
            }
            else if (format[i + 1] == 's')
            {
                p = va_arg(args, char*);
                for (j = 0; p[j] != '\0'; j++)
                {
                   _putchar(p[j]);
                }
            }
        }
        else
        {
            if (format[i - 1] == '%') continue;
            _putchar(format[i]);
        }

    }
    va_end(args);
    return (0);
}


