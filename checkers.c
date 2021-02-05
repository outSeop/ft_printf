#include "ft_printf.h"

int				check_type(char **format, t_tag *tag)
{
	(*format)++;
	check_flag(format, tag);
	printf("1: %d\n", tag->arg_len);
	check_width(format, tag);
	printf("2: %d\n", tag->arg_len);
	check_precision(format, tag);
	printf("3: %d\n", tag->arg_len);
	check_specifier(format, tag);
	printf("4: %d\n", tag->arg_len);
	tag->argument = combine_fill(tag, tag->prec_len, '0');
	printf("5: %d\n", tag->arg_len);
	tag->argument = algin(tag);
	printf("6: %d\n", tag->arg_len);
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
	return(1);
}

int				check_specifier(char **format, t_tag *tag)
{
	if (**format == 'c')
		tag->argument = trance_c(va_arg(g_ap, int));
	else if (**format == 's')
		tag->argument = trance_s(va_arg(g_ap, char*));
	else if (**format == 'p')
		tag->argument = trance_p(va_arg(g_ap, void*));
	else if (**format == 'd')
		tag->argument = trance_d(va_arg(g_ap, int));
	else if (**format == 'i')
		tag->argument = trance_d(va_arg(g_ap, int));
	else if (**format == 'u')
		tag->argument = trance_u(va_arg(g_ap, unsigned int));
	else if (**format == 'x')
		tag->argument = trance_hex(va_arg(g_ap, int), "0123456789abcdef");
	else if (**format == 'X')
		tag->argument = trance_hex(va_arg(g_ap, int), "0123456789ABCDEF");
	tag->specifier = **format;
	tag->arg_len = ft_strlen(tag->argument);
	return (1);
}
