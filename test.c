#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int i;
	
	i = -1;	
	printf("[%p]\n", &i);
	ft_printf("[%p]", &i);
}
