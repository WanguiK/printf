#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: Character string
 *
 * Return: number of characters printed (excluding the null byte)
 */
int _printf(const char * const format, ...)
{
	convert_match m[] = {
		{"%s", printf_string}, {"%c", printf_char},
		{"%%", printf_37},
		{"%i", printf_int}, {"%d", printf_dec}, {"%r", printf_srev},
		{"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
		{"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
		{"%S", printf_exclusive_string}, {"%p", printf_pointer}
	};

	va_list args;
	int i = 0, j, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			j = 0;
			while (j < 14)
			{
				if (format[i + 1] == m[j].id[1])
				{
					len += m[j].f(args);
					i += 2;
					break;
				}
				j++;
			}
			if (j == 14)
				len += _putchar(format[i++]);
		}
		else
			len += _putchar(format[i++]);
	}

	va_end(args);
	return (len);
}
/**
 * handle_conversion_specifier - handles conversion specifier and associated flags
 * @format: Character string
 * @index: Pointer to the current index in the format string
 * @args: Arguments list
 * @m: Array of conversion specifiers and their corresponding functions
 *
 * Return: Number of characters printed for the conversion specifier
 */
int handle_conversion_specifier(const char *format, int *index, va_list args, convert_match *m)
{
	int j;

	for (j = 0; j < 14; j++)
	{
		if (format[*index + 1] == m[j].id[1])
		{
			int len = m[j].f(args);
			*index += 2;
			return len;
		}
	}

	/* Check for flag characters */
	if (j == 14) {
		return handle_flag_characters(format, index, args);
	}

	return 0;
}
