#include "ft_printf.h"

int main()
{
	printf("[%d]\n", ft_printf("%d\n", ft_printf("hello - [%d]-[%s]-[%c] - world! [%s]\n", 123, "123", '1', "23")));
}
