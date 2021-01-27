#include "ft_printf.h"

va_list	g_ap;
int			ft_printf(const char *format, ...)
{
	int		i;
	char	*detail_format;

	va_start(g_ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			detail_format = check_type(format[i]);


		}
		else
		{
			write(1, &format[i], 1);
		}
		i++;
	}
}
