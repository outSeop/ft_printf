#include "ft_printf.h"


int			ft_printf(const char *format, ...)
{
	int		i;
	t_tag	*tag;
	char	*temp;
	char	*rm;
<<<<<<< HEAD
	int		size;
=======
>>>>>>> e619a0a757ca2c2ed104371c8cdcaf79985a0dd7

	temp = ft_strdup(format);
	rm = temp;
	va_start(g_ap, format);
	tag = malloc(sizeof(t_tag));
<<<<<<< HEAD
	check(&format, tag);
=======
	check(&temp, tag);
>>>>>>> e619a0a757ca2c2ed104371c8cdcaf79985a0dd7
	free(rm);
	va_end(g_ap);
	return (1);
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
			size = check_type(format, tag);
		}
		else
		{
			write(1, *format, 1);
		(*format)++;
	}
	free(tag);
	return (size);
}
