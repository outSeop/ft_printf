#include "ft_printf.h"

int				check_type(char **format, t_tag *tag)
{
	(*format)++;
	check_flag(format, tag);
	check_width(format, tag);
	check_precision(format, tag);
	check_specifier(format, tag);
	tag->argument = refine(tag);
	tag->argument = algin(tag);
	write(1, tag->argument, tag->arg_len);
	free(tag->argument);
	return (tag->arg_len);
}

int				check_flag(char **format, t_tag *tag)
{
	while (**format)
	{
		if (**format == '-')
			tag->fill = '-';
		else if (**format == '0')
		{
			if (tag->fill != '-')
				tag->fill = '0';
		}
		else if (ft_isdigit(**format) && !tag->fill)
		{
			tag->fill = ' ';
			return (1);
		}
		else
			return (1);
		(*format)++;
	}
	return (1);
}

int				check_width(char **format, t_tag *tag)
{
	int			width;

	if (**format == '*')
	{
		width = va_arg(g_ap, int);
		if (width < 0)
		{
			width *= -1;
			tag->fill = '-';
		}
		(*format)++;
	}
	else
	{
		width = 0;
		while (ft_isdigit(**format))
		{
			width *= 10;
			width += **format - '0';
			(*format)++;
		}
	}
	tag->width = width;
	return (1);
}

int				check_precision(char **format, t_tag *tag)
{
	if (**format == '.')
	{
		tag->precision = 1;
		(*format)++;
		if (**format == '*')
		{
			tag->prec_len = va_arg(g_ap, int);
			(*format)++;
		}
		else
		{
			while (ft_isdigit(**format))
			{
				tag->prec_len *= 10;
				tag->prec_len += **format - '0';
				(*format)++;
			}
		}
	}
	if (tag->prec_len < 0)
	{
		tag->prec_len = 0;
		tag->precision = 0;
	}
	return(1);
}

int				check_specifier(char **format, t_tag *tag)
{
	if ((tag->specifier = **format) == 'c')
		trance_c(va_arg(g_ap, int), tag);
	else if (**format == 's')
		trance_s(va_arg(g_ap, char*), tag);
	else if (**format == 'p')
		trance_p(va_arg(g_ap, void*), tag);
	else if (**format == 'd' || **format == 'i')
		trance_d(va_arg(g_ap, int), tag);
	else if (**format == 'u')
		trance_u(va_arg(g_ap, unsigned int), tag);
	else if (**format == 'x')
		trance_hex(va_arg(g_ap, int), "0123456789abcdef", tag);
	else if (**format == 'X')
		trance_hex(va_arg(g_ap, int), "0123456789ABCDEF", tag);
	else if (**format == '%')
	{
		trance_c('%', tag);
		tag->precision = 0;
		tag->prec_len = 0;
	}
	else
		trance_c(**format, tag);
		if (tag->prec_len < tag->width && tag->fill == '0' && tag->prec_len >= 0 && tag->precision == 1)
			tag->fill = ' ';
	return (1);
}
