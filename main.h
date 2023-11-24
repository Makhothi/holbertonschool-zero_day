#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* Function prototypes */

/* File: printf_helpers.c */
void print_char(char c, int *count);
void print_string(const char *str, int *count);
void handle_char(va_list args, int *count);
void handle_string(va_list args, int *count);

/* File: _printf.c */
int _printf(const char *format, ...);

#endif /* MAIN_H */
