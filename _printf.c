#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf- produces output according to a format
 * @format: character string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	char c;
	int i;
	const char *s;

	va_list ap;

	va_start(ap, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
				c = (char)va_arg(ap, int);
				putchar(c);
				count++;
				break;

				case 's':
				s = va_arg(ap, const char *);
				while (*s != '\0')
				{
					putchar(*s);
					s++;
					count++;
				}
				break;

				case '%':
				putchar('%');
				count++;
				break;
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
