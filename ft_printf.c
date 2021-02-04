#include "ft_printf.h"


int			ft_printf(const char *format, ...)
{
	int		i;
	t_tag	*tag;
	char	*temp;
	char	*rm;
	int		size;

	va_start(g_ap, format);
	temp = ft_strdup(format);
	rm = temp;
	size = check(&temp, tag);
	free(rm);
	va_end(g_ap);
	return (size);
}

int				check(char **format, t_tag *tag)
{
	int			size;

	size = 0;
	while (**format)
	{
		if (**format == '%')
		{
			initTag(tag);
			size += check_type(format, tag);
		}
		else
		{
			write(1, *format, 1);
			size++;
		}
		(*format)++;
	}
	free(tag);
	return (size);
}
