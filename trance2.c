#include "ft_printf.h"

char			*trance_p(void *p)
{
	long long	lp;
	char		*address;
	int			i;
	long long	divider;

	lp = (long long)p;
	if(!(address = malloc(20))
		return (NULL);
	divider = 1;
	while (divider < lp)
		divider *= 16;
	divider /= 16;
	address[0] = '0';
	address[1] = 'x';
	i = 2;
	while (divider > 0)
	{
		address[i++] = "0123456789abcdef"[lp / divider];
		lp %= divider;
		divider /= 16;
	}
	address[i] = '\0';
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
