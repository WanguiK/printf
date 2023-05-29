#include "main.h"
#include <stdarg.h>

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
				int c = va_arg(ap, int);

				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(ap, char *);
				int i = 0;

				while (s[i] != '\0')
				_putchar(s[i]);
				count++;
			}
			else if (*format == '%')
			{
				_putchar('%');
				count++;
			}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
		}
	}
	va_end(ap);
	return (count);
}
