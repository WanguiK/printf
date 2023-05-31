#include "main.h"

/**
 * handle_coversion_specifier- specifies the conversion
 *
 * Return: 0 Always
 */
int handle_conversion_specifier(char specifier, va_list args)
{
	switch (specifier)
	{
		case 'p':
		return (printf_pointer(args));
		default:
		return (-1);
	}
}
