#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;

	va_list(ap);

	va_start(ap, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(ap, int);

				printf("%d", num);
				count++;
			}
		else
		{
			putchar(*format);
			count++;
		}
		}
		format++;
	}
	va_end(ap);
	return (count);
}
