#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * _printf - Custom printf function that handles %c, %s, and %%
 * @format: The format string containing conversion specifiers
 * @...: Additional arguments based on the format string
 * Return: The number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
int count = 0;
va_list args;
va_start(args, format);

while (*format != '\0')
{
if (*format == '%' && *(format + 1) == '%')
{
write(1, "%", 1);
count++;
format += 2;
}
else if (*format == '%' && *(format + 1) != '%')
{
format++;
switch (*format)
{
case 'c':
handle_char(args, &count);
break;
case 's':
handle_string(args, &count);
break;
default:
write(1, "%", 1);
write(1, format, 1);
count += 2;
break;
}
format++;
}
else
{
write(1, format, 1);
count++;
format++;
}
}
va_end(args);
return count;
}
