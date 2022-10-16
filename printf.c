#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

int _printf(const char* format, ...)
{
    int i, j, k;
    va_list args;

    char* p = NULL;
    va_start(args, format);

    for (i = 0; i < strlen(format); i++)
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == 'c')
            {
                p = va_arg(args, char*);
                putchar(p);
            }
            else if (format[i + 1] == 's')
            {
                p = va_arg(args, char*);
                for (j = 0; j < strlen(p); j++)
                {
                    putchar(p[j]);
                }
            }
        }
        else
        {
            if (format[i - 1] == '%') continue;
            putchar(format[i]);
        }
        
    }
    va_end(args);
    return (0);
}
