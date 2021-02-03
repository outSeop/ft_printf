#include "ft_printf.h"


int			ft_printf(const char *format, ...)
{
	int		i;

	va_start(g_ap, format);
	check(format);
	va_end(g_ap);
	return (1);
}

int				check(char **format, t_tag *tag)
{

	while (**format)
	{
		if (**format == '%')
			check_type(format, tag);
		else
			write(1, *format, 1);
		(*format)++;
	}
	return (1);
}
