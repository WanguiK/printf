#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
	int count = 0;
	va_list ap;

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			_putchar(*format);
			count++;
		}
		else
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(ap, int);

				if (num < 0)
				{
					_putchar('-');
					count++;
					num = -num;
				}
				count += _print_int(num);
			}
		}
		format++;
	}
	va_end(ap);
	return (count);
}
/**
 * _print_int -prints integers
 * @num: number
 * Return: 0 Always
 */
int _print_int(int num)
{
	int count = 0;

	if (num / 10)
		count += _print_int(num / 10);
	_putchar(num % 10 + '0');
	count++;
	return (count);
}
