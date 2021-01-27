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
int			check(char *format)
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
}
int			check_type(char *format)
{
	return (check_flag(format));
}

int			check_flag(char *foramt)
{
	if (*format == '-')
		check_width(++format)

	else if (*format == '0')
		check_width(++format)

	else
		check_width(format);
}

int			check_width(char *format)
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
			width += ft_atoi(*format);
			format++;
		}
	}
	check_precision(format, width);
}

int			check_precision(char *format, int width)
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
	check_specifier(format);
}
