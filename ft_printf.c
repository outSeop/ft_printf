#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			check_and_print(++i);

	}

}

