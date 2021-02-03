#include "ft_printf.h"

int				check(char **format, t_tag *tag)
{

	while (**format)
	{
		if (**format == '%')
		{
			(*format)++;
			check_type(format, tag);
		}
		else
		{
			write(1, *format, 1);
		}
		(*format)++;
	}
	return (1);
}
int				check_type(char **format, t_tag *tag)
{
	check_flag(format, tag);
	check_width(format, tag);
	check_precision(format, tag);
	check_specifier(format, tag);
	tag->argument = combine_fill(tag, tag->prec_len, '0');
	tag->argument = combine_fill(tag, tag->width, tag->fill);
	write(1, tag->argument, tag->arg_len);
	return (1);
}

int				check_flag(char **format, t_tag *tag)
{
	while (**format)
	{
		if (**format == '-')
			tag->fill = '-';
		else if (**format == '0')
			tag->fill = '0';
		else if (ft_isdigit(**format))
		{
			tag->fill = ' ';
			return (1);
		}
		else if (**format == ' ')
			tag->sign = '+';
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


char			*my_str_cpy(char *str, char c, int nbr)
{
	char		*temp;
	int			size;
	int			i;
	int			j;

	size = ft_strlen(str);
	if (size >= nbr)
		return (str);
	temp = malloc(nbr + 1);
	i = 0;
	while (i < nbr - size)
		temp[i++] = c;
	j = 0;
	while (str[j])
	{
		temp[i + j - 1] = str[j];
		j++;
	}
	temp[i + j] = '\0';
	free(str);
	str = temp;
	return (str);
}

t_tag			*initTag()
{
	t_tag		*tag;

	tag = malloc(sizeof(t_tag));
	tag->arg_len = 0;
	tag->argument = NULL;
	tag->fill = '\0';
	tag->print_out = NULL;
	tag->sign = '\0';
	tag->width = 0;
	return (tag);
}


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
	return (s);
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

char			*trance_p(void *p)
{
	long long	lp;
	char		*address;
	int			size;
	long long	divider;

	lp = (long long)p;
	if(!(address = malloc(17)))
		return (NULL);
	ft_memset(address, '0', 17);
	address[16] = '\0';
	size = 16;
	divider = 1;
	while (divider < lp)
	{
		divider *= 16;
		size--;
	}
	divider /= 16;
	while (divider > 0)
	{
		address[size++] = "0123456789ABCDEF"[lp / divider];
		lp %= divider;
		divider /= 16;
	}
	return (address);
}

char			*trance_hex(int hex, char *arr)
{
	char		*str;
	char		*bin;
	int			sum;
	int			i;

	str = malloc(9);
	i = 0;
	bin = trance_bin(hex);
	sum = 0;
	i = 0;
	while (i < 32)
	{
		sum += (bin[i + 0] - '0') * 8;
		sum += (bin[i + 1] - '0') * 4;
		sum += (bin[i + 2] - '0') * 2;
		sum += (bin[i + 3] - '0') * 1;
		str[i / 4] = arr[sum];
		i += 4;
		sum = 0;
	}
	str[i / 4] = '\0';
	free(bin);
	return (str);
}

char			*trance_bin(int n)
{
	unsigned int	a;
	int				i;
	char			*arr;

	a = 0x80000000;
	arr = malloc(33);
	arr[32] = '\0';
	i = 0;
	while (i < 32)
	{
		if ((a & n) == a)
			arr[i] = '1';
		else
			arr[i] = '0';
		a >>= 1;
		i++;
	}
	return (arr);
}

char			*my_itoa(unsigned int n)
{
	long long	tmp;
	int			len;
	char		*res;

	len = 0;
	tmp = n;
	len += a_get_len(tmp);
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	res[--len] = tmp % 10 + '0';
	while (tmp /= 10)
		res[--len] = tmp % 10 + '0';
	return (res);
}


int				a_get_len(long long tmp)
{
	if (tmp < 10)
		return (1);
	return (a_get_len(tmp / 10) + 1);
}

/*
** 할 것
** 가변인자로 받은 값 문자열로 처리
*/
