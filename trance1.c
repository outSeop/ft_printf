#include "ft_printf.h"

char			*trance_c(char c)
{
	char		*str;

	str = malloc(sizeof(c) + 1);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char			*trance_s(char *s)
{
	char		*str;

	if (!s)
	{
		str = ft_strdup("(null)");
		return (str);
	}
	str = ft_strdup(s);
	return (str);
}

char			*trance_d(int d)
{
	char		*str;

	str = ft_itoa(d);
	return (str);
}

char			*trance_u(unsigned int u)
{
	char		*str;

	str = my_itoa(u);
	return (str);
}
