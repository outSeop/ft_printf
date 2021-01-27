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
	char	*argument;

	if (*format == '*')
	{
		width = va_arg(g_ap, int);
		format++;
	}
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
	int		prec_len;

	precision = 0;
	if (*format == '.')
	{
		format++;
		if (*format == '*')
		{
			precision = va_arg(ap, int);
			format++;
		}
		else
		{
			while (ft_isdigit(*format))
			{
				precision *= 10;
				precision += (int)*format;
				format++;
			}
		}
	}
	prec_len = width > precision ? width : precision;
	check_specifier(format, prec_len);

	return(1);
}

char		*check_specifier(const char *format, int prec_len)
{
	char	*argument;
	char	*string;
	int		size;
	int		arg_len;

	if (*format == 'c')
		argument = va_arg(g_ap, char);
	else if (*format == 's')
		argument = va_arg(g_ap, char*);
	else if (*format == 'p')
		argument = va_arg(g_ap, double);
	else if (*format == 'd')
		argument = va_arg(g_ap, int);
	else if (*format == 'i')
		argument = va_arg(g_ap, int);
	else if (*format == 'u')
		argument = va_arg(g_ap, int);
	else if (*format == 'x')
		argument = va_arg(g_ap, int);
	else if (*format == 'X')
		argument = va_arg(g_ap, int);
	format++;
	arg_len = ft_strlen(argument);
	size = prec_len > size ? prec_len : size;
	string = malloc(size + 1);
	my_strbcpy(string, argument, size, arg_len);
	// cspdiuxX
}

void		my_strbcpy(char *dest, char *src, int size, int arg_len)
{
	while (arg_len + 1)
		dest[size--] = src[arg_len--];
}
