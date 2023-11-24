#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
* print_char - Prints a character to the standard output.
* @c: The character to be printed.
* @count: Pointer to an integer count of printed characters.
*
* This function writes a single character @c to the standard output
* using the write system call. It increments the count of characters
* printed (@count) by 1.
*/
void print_char(char c, int *count)
{
write(1, &c, 1);
(*count)++;
}

/**
* print_string - Prints a string to the standard output.
* @str: Pointer to the string to be printed.
* @count: Pointer to an integer count of printed characters.
* This function iterates through the string @str and prints each
* character to the standard output using the write system call.
* It increments the count of characters printed (@count) accordingly.
*/
void print_string(const char *str, int *count)
{
while (*str != '\0')
{
write(1, str, 1);
str++;
(*count)++;
}
}

/**
* handle_char - Handles the %c specifier in format strings.
* @args: va_list containing the variable arguments.
* @count: Pointer to an integer count of printed characters.
* This function retrieves a character argument from the va_list @args
* using va_arg macro with int typecast. It then calls print_char
* to print the character to the standard output and increments
* the count of characters printed (@count) by 1.
*/
void handle_char(va_list args, int *count)
{
char c = (char)va_arg(args, int);
print_char(c, count);
}

/**
* handle_string - Handles the %s specifier in format strings.
* @args: va_list containing the variable arguments.
* @count: Pointer to an integer count of printed characters.
* This function retrieves a string argument from the va_list @args
* using va_arg macro with char * type. If the string is NULL,
* it assigns a default "(null)" string. It then calls print_string
* to print the string to the standard output and increments
* the count of characters printed (@count) accordingly.
*/
void handle_string(va_list args, int *count)
{
char *str = va_arg(args, char *);
if (str == NULL)
{
print_string("(null)", count);
}
else
{
print_string(str, count);
}
}
