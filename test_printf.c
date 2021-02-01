#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"

void	func(char *format, ...);

int main()
{
	int i = -1;

	printf("printf: %p\n", &i);
	func("func: %p\n", &i);
}

void	func(char *format, ...)
{
	t_tag	*tag;

	tag= initTag();
	va_start(g_ap, format);

	/*
	check_flag(&format, tag);
	check_width(&format, tag);
	check_precision(&format, tag);
	check_specifier(&format, tag);
	*/
	check(&format, tag);

	va_end(g_ap);


	printf("sign: [%c]\n", tag->sign);
	printf("fill: [%c]\n", tag->fill);
	printf("width: [%d]\n", tag->width);
	printf("prec: [%d]\n", tag->prec_len);
	printf("spec: [%c]\n", tag->specifier);
	printf("arg: [%s]\n", tag->argument);

}


