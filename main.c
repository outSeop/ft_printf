#include "ft_printf.h"

char				*ten_to_two(int n) {
    unsigned int	a = 0x80000000; // 1000 0000 0000 0000 0000 0000 0000 0000(2) <약 21억>
	int	i;
	char	*arr;

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
int main()
{
	char *a;
	int n = -12314;
	int		sum;
	int		i;
	int		j;

	a = ten_to_two(n);
	printf("%X\n", n);
	i = 0;
	while (i < 32)
	{
		sum += (a[i + 0] - '0') * 8;
		sum += (a[i + 1] - '0') * 4;
		sum += (a[i + 2] - '0') * 2;
		sum += (a[i + 3] - '0') * 1;
		i += 4;
		printf("%c", sum["0123456789ABCDEF"]);
		sum = 0;
	}
}


