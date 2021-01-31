#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"

void	func(char *format, ...);

int main()
{
	func("-3.5d");
}

void	func(char *format, ...)
{
	t_tag *tag;

	tag = initTag();
	va_start(g_ap, format);

	format += check_flag(format, tag);
	format += check_width(format, tag);
	format += check_precision(format, tag);
	format += check_specifier(format, tag);

	va_end(g_ap);


	printf("sign: [%d]\n", tag->sign);
	printf("fill: [%c]\n", tag->fill);
	printf("width: [%d]\n", tag->width);
	printf("prec: [%d]\n", tag->prec_len);
	printf("spec: [%c]\n", tag->specifier);

}


