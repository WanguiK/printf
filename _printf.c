#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf-  produces output according to a format
 * @format: character string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list ap;

	va_start(ap, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(ap, int);

				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(ap, char *);

				while (*s != '\0')
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
