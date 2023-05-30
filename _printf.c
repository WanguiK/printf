#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr;

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == 'c')
			{
				int c = va_arg(args, int);

				count += write(1, &c, 1);
			}
			else if (*ptr == 's')
			{
				char *s = va_arg(args, char *);

				int len = 0;

				while (s[len] != '\0')
					len++;
				count += write(1, s, len);
			}
			else if (*ptr == '%')
			{
				count += write(1, "%", 1);
			}
		}
		else
		{
			count += write(1, ptr, 1);
		}
	}
	va_end(args);
	return (count);
}
