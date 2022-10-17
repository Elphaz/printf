#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

/**
 * _printf - Write a function that produces output according to a format.
 * @format: array containing conversion specifiers:
 * Return:  the number of characters printed.
 */

int _printf(const char *format, ...)
{
int i, j, count = 0, count1 = 0, count2 = 0;
va_list args;
char *p = NULL;
char c;
va_start(args, format);
for (i = 0; format[i] != '\0'; i++)
{
count++;
}
for (i = 0; i < count; i++)
{
if (format[i] == '%')
{
count1++;
if (format[i + 1] == 'c')
{
count2++;
c = va_arg(args, int);
_putchar(c);
}
else if (format[i + 1] == 's')
{
p = va_arg(args, char *);
for (j = 0; p[j] != '\0'; j++)
{
count2 += j;
_putchar(p[j]);
}
}
}
else
{
if (format[i - 1] == '%')
continue;
_putchar(format[i]);
}
}
va_end(args);
return (count - count1 * 2 + count2);
}
