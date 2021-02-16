#include "ft_printf.h"

int				check_type(char **format, t_tag *tag)
{
	(*format)++;
	check_flag(format, tag);
	check_width(format, tag);
	check_precision(format, tag);
	check_specifier(format, tag);
	tag->argument = refine(tag);
	printf("test: %s\n", tag->argument);
	tag->arg_len = ft_strlen(tag->argument);
	tag->argument = algin(tag);
	tag->arg_len = ft_strlen(tag->argument);
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
		else if (**format == '0' && tag->fill != '-')
			tag->fill = '0';
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
			width *= -1;
		tag->fill = '-';
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
		if (tag->prec_len < tag->width && tag->fill == '0')
			tag->fill = ' ';
	}
	return(1);
}

int				check_specifier(char **format, t_tag *tag)
{
	if ((tag->specifier = **format) == 'c')
		tag->argument = trance_c(va_arg(g_ap, int));
	else if (**format == 's')
		tag->argument = trance_s(va_arg(g_ap, char*));
	else if (**format == 'p')
			tag->argument = trance_p(va_arg(g_ap, void*));
		else if (**format == 'd' || **format == 'i')
			tag->argument = trance_d(va_arg(g_ap, int), tag);
		else if (**format == 'u')
			tag->argument = trance_u(va_arg(g_ap, unsigned int));
		else if (**format == 'x')
			tag->argument = trance_hex(va_arg(g_ap, int), "0123456789abcdef");
		else if (**format == 'X')
			tag->argument = trance_hex(va_arg(g_ap, int), "0123456789ABCDEF");
		else if (**format == '%')
			tag->argument = trance_c('%');
		else
			tag->argument = trance_c(**format);
	tag->arg_len = ft_strlen(tag->argument);
	return (1);
}
