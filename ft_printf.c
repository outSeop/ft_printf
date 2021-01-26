#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	char	*buffer;
	char	*detail_format;

	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			//i += check_type(format[i], detail_format);

		}
		else
		{
			write(1, format[i], 1);
		}
	}
}

