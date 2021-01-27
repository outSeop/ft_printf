#include "ft_printf.h"

va_list	g_ap;

int			ft_printf(const char *format, ...)
{
	int		i;

	va_start(g_ap, format);
	i = 0;
	while (*format)
	{
		if (format[i] == '%')
		{
		//	check_type(format);
		}
		else
		{
			write(1, format, 1);
		}
		format++;
	}
	return (1);
}
/*
int			check_type(char *format, int *idx)
{
	return (check_flag(format, idx));
}

int			check_flag(char *foramt, int *idx)
{
	if (format[0] == '-')
		check_width(format, )

	else if (format[0] == '0')
		check_width(format, ++(*idx))

	else
		check_width(format, idx);

}

int			check_width(char *format, int *idx)
{
	int		width;
	int		input_width;
	char	*string;

	if (format[0] == '*')
		width = va_arg(g_ap, int);
	else
	{
		width = 0;
		while (ft_isdisit(format[*idx]))
		{
			width *= 10;
			width += ft_atoi(format[*idx]);
			*idx++;
		}
	}
}
*/
