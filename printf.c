#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	char c;
	const char *s;
	va_list(ap);

	va_start(ap, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
				c = va_arg(ap, int);
				_putchar(c);
				count++;
				break;

				case 's':
				s = va_arg(ap, const char *);
				while (*s != '\0')
				{
					_putchar(*s);
					s++;
					count++;
				}
				break;

				case '%':
				_putchar('%');
				count++;
				break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(ap);
	return (count);
}
