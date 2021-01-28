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
	char	*tag->argument;

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
	int		i;
	int		precision;
	int		prec_len;
	t_tag	*tag;

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
	tag = check_specifier(format, prec_len);
	my_str_cpy(tag->argument, '0', precision);
	return(1);
}

t_tag		*check_specifier(const char *format, int prec_len)
{
	t_tag	*tag;

	if (*format == 'c')
		tag->argument = va_arg(g_ap, char);
	else if (*format == 's')
		tag->argument = va_arg(g_ap, char*);
	else if (*format == 'p')
		tag->argument = va_arg(g_ap, double);
	else if (*format == 'd')
		tag->argument = va_arg(g_ap, int);
	else if (*format == 'i')
		tag->argument = va_arg(g_ap, int);
	else if (*format == 'u')
		tag->argument = va_arg(g_ap, int);
	else if (*format == 'x')
		tag->argument = va_arg(g_ap, int);
	else if (*format == 'X')
		tag->argument = va_arg(g_ap, int);
	format++;
	tag->arg_len = ft_strlen(tag->argument);
	size = prec_len > size ? prec_len : size;
	tag->print_out = malloc(size + 1);
	return (tag);
}

void		my_str_cpy(char *str, char c, int nbr)
{
	char	*temp;
	int		size;
	int		i;
	int		j;

	size = ft_strlen(str);
	if (size > nbr)
		return ;
	temp = malloc(nbr + 1);
	i = nbr - size;
	while (i + 1)
		temp[i++] = c;
	j = 0;
	while (str[j])
		temp[i + j] = str[j++];
	free(str);
	str = temp;
}
