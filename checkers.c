#include "ft_printf.h"


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
	t_tag	*tag;

	tag = initTag();
	check_flag(format++, tag);
	check_width(format++, tag);
	check_precision(format++, tag);
	check_specifier(format++, tag);
}

int			check_flag(const char *format, t_tag *tag)
{
	int		i;

	i = 0;
	while (*format)
	{
		if (*format == '-')
			tag->fill = '-';
		else if (*format == '0')
			tag->fill = '0';
		else if (*format == ' ')
			tag->sign = '+';
		else
			return (i);
		format++;
		i++;
	}
	return (i);
}

int			check_width(const char *format, t_tag *tag)
{
	int		width;

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
			width += *format - '0';
			format++;
		}
	}
	tag->width = width;
	return (1);
}

int			check_precision(const char *format, t_tag *tag)
{
	int		i;

	i = 0;
	if (*format == '.')
	{
		format++;
		i++;
		if (*format == '*')
		{
			tag->prec_len = va_arg(g_ap, int);
			format++;
			i++;
		}
		else
		{
			while (ft_isdigit(*format))
			{
				tag->prec_len *= 10;
				tag->prec_len += *format - '0';
				format++;
				i++;
			}
		}
	}
	return(i);
}

int			check_specifier(const char *format, t_tag *tag)
{
	if (*format == 'c')
	tag->specifier = *format;
	else if (*format == 's')
	tag->specifier = *format;
	else if (*format == 'p')
	tag->specifier = *format;
	else if (*format == 'd')
	tag->specifier = *format;
	else if (*format == 'i')
	tag->specifier = *format;
	else if (*format == 'u')
	tag->specifier = *format;
	else if (*format == 'x')
	tag->specifier = *format;
	else if (*format == 'X')
	tag->specifier = *format;

	format++;
	// tag->arg_len = ft_strlen(tag->argument);
	return (1);
}

char		*my_str_cpy(char *str, char c, int nbr)
{
	char	*temp;
	int		size;
	int		i;
	int		j;

	size = ft_strlen(str);
	if (size >= nbr)
		return (str);
	temp = malloc(nbr + 1);
	i = 0;
	while (i < nbr - size)
		temp[i++] = c;
	j = 0;
	while (str[j])
		temp[i + j - 1] = str[j++];
	temp[i + j] = '\0';
	free(str);
	str = temp;
	return (str);
}

t_tag		*initTag()
{
	t_tag	*tag;

	tag = malloc(sizeof(t_tag));
	tag->arg_len = 0;
	tag->argument = NULL;
	tag->fill = '\0';
	tag->print_out = NULL;
	tag->sign = '\0';
	tag->width = 0;
	return (tag);
}


/*
** 할 것
** 가변인자로 받은 값 문자열로 처리
*/
