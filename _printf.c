#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf-  produces output according to a format
 * @format: character string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...);
{
	va_list ap;

	va_start(ap, format);

	int count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char val = va_arg(ap, int);

				putchar(val);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(ap, char *);

				putchar(*s);
				s++;
				count++;
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(ap);
	return (count);
}
