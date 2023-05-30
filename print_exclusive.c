#include "main.h"

/**
 * printf_exclusive_string - Print exclusive string
 * @val: Argument
 *
 * Return: The length of the string
 */
int printf_exclusive_string(va_list val)
{
	char *s = va_arg(val, char *);
	int len = 0;

	if (s == NULL)
		s = "(null)";

	for (; *s; s++)
	{
		if (*s < 32 || *s >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len += 2;

			if (*s < 16)
			{
				_putchar('0');
				len++;
			}

			len += printf_HEX_aux(*s);
		}
		else
		{
			_putchar(*s);
			len++;
		}
	}

	return (len);
}
