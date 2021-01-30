#include "ft_printf.h"


int			ft_printf(const char *format, ...)
{
	int		i;

	va_start(g_ap, format);
	check(format);
	va_end(g_ap);
	return (1);
}
