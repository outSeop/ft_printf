#include "ft_printf.h"

void			trance_p(void *p, t_tag *tag)
{
	long long		i;
	int		j;
	long long lp;

	lp = (long long)p;
	tag->argument = malloc(20);
	tag->argument[0] = '0';
	tag->argument[1] = 'x';
	tag->argument[2] = 0;
	i = 48;
	j = 2;
	while (i >= 0)
	{
		tag->argument[j] = "0123456789abcdef"[((lp >> i) & 15)];
		if (tag->argument[2] != '0')
			j++;
		i -= 4;
	}
	if (j == 2)
		tag->argument[j++] = '0';
	tag->argument[j] = '\0';
	tag->arg_len = ft_strlen(tag->argument);
}

/*
void			trance_p(void *p, t_tag *tag)
{
	long long	lp;
	int			i;
	long long	divider;

	lp = (long long)p;
	if (!(tag->argument = malloc(20)))
		return ;
	divider = 1;
	while (divider < lp)
		divider *= 16;
	divider /= 16;
	tag->argument[0] = '0';
	tag->argument[1] = 'x';
	i = 2;
	while (divider > 0)
	{
		tag->argument[i++] = "0123456789abcdef"[lp / divider];
		lp %= divider;
		divider /= 16;
	}
	if (i == 2)
		tag->argument[i++] = '0';
	tag->argument[i] = '\0';
	tag->arg_len = ft_strlen(tag->argument);
}
*/

void			test(int hex, char *arr)
{
	char		*address;
	int			i;
	long long	divider;

	if (!(address = malloc(20)))
		return ;
	divider = 1;
	while (divider < hex)
		divider *= 16;
	divider /= 16;
	if (divider == 0)
		divider++;
	i = 0;
	while (divider > 0)
	{
		address[i++] = arr[hex / divider];
		hex %= divider;
		divider /= 16;
	}
	address[i] = '\0';

}
/*
void			trance_bin(int n)
{
	unsigned int	a;
	int				i;
	void			arr;

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
}
*/
void		trance_hex(int value, char *arr, t_tag *tag)
{
	int		i;
	int		j;

	tag->argument = malloc(9);
	tag->argument[0] = 0;
	i = 28;
	j = 0;
	while (i >= 0)
	{
		tag->argument[j] = arr[((value >> i) & 15)];
		if (tag->argument[0] != '0')
			j++;
		i -= 4;
	}
	if (j == 0)
		j++;
	tag->argument[j] = '\0';
	tag->arg_len = ft_strlen(tag->argument);
}
