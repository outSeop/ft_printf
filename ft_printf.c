#include "ft_printf.h"


int			ft_printf(const char *format, ...)
{
	int		i;
	t_tag	*tag;
	char	*temp;
	char	*rm;

	temp = ft_strdup(format);
	rm = temp;
	va_start(g_ap, format);
	tag = malloc(sizeof(t_tag));
	check(&temp, tag);
	free(rm);
	va_end(g_ap);
	return (1);
}

int				check(char **format, t_tag *tag)
{
	while (**format)
	{
		if (**format == '%')
		{
			initTag(tag);
			check_type(format, tag);
		}
		else
			write(1, *format, 1);
		(*format)++;
	}
	free(tag);
	return (1);
}
