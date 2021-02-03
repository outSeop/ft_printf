#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"

void	func(char *format, ...);

int main()
{
	int i = 123;

	printf("printf: [%22.10d]\n", i);
	  func("functi: [%22.10d]\n", i);
}

void	func(char *format, ...)
{
	t_tag	*tag;

	tag= initTag();
	va_start(g_ap, format);

	check(&format, tag);

	va_end(g_ap);

	/*
	printf("sign: [%c]\n", tag->sign);
	printf("fill: [%c]\n", tag->fill);
	printf("width: [%d]\n", tag->width);
	printf("prec: [%d]\n", tag->prec_len);
	printf("spec: [%c]\n", tag->specifier);
	printf("a_ln: [%d]\n", tag->arg_len);
	printf("arg: [%s]\n", tag->argument);
	*/

}


