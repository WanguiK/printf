#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;

	va_list(ap);

	if (format == NULL)
	{
		return (-1);
	}

	va_start(ap, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			_putchar(*format);
			count++;
		}
		else
		{
			format++;
			if (*format == '%')
			{
				_putchar('%');
				count++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(ap, int);

				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				const char *s = va_arg(ap, const char *);

				while (*s != '\0')
				{
					_putchar(*s);
					s++;
					count++;
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(ap, int);

				if (num < 0)
				{
					_putchar('-');
					count++;
					num = -num;
				}
			}
		}
		format++;
	}
	va_end(ap);
	return (count);
}
