#include "ft_printf.h"

va_list	g_ap;

int			ft_printf(const char *format, ...)
{
	int		i;

	va_start(g_ap, format);
	check(format);
	va_end(g_ap);
	return (1);
}
int			check(const char *format)
{
	while (*format)
	{
		if (*format == '%')
		{
			check_type(format);
		}
		else
		{
			write(1, format, 1);
		}
		format++;
	}
	return (1);
}

int			check_type(const char *format)
{
	return (check_flag(format));
}

int			check_flag(const char *format)
{
	if (*format == '-')
		check_width(++format);

	else if (*format == '0')
		check_width(++format);

	else
		check_width(format);
	return (1);
}

int			check_width(const char *format)
{
	int		width;
	int		input_width;
	char	*string;

	if (*format == '*')
		width = va_arg(g_ap, int);
	else
	{
		width = 0;
		while (ft_isdigit(*format))
		{
			width *= 10;
			width += (int)*format;
			format++;
		}
	}
	check_precision(format, width);
	return (1);
}

int			check_precision(const char *format, int width)
{
	int		precision;

	precision = 0;
	if (*format == '.')
	{
		format++;
		while (ft_isdigit(*format))
		{
			precision *= 10;
			precision += ft_atoi(*format);
			format++;
		}
	}
	//check_specifier(format);
	return(1);
}
