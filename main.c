#include "ft_printf.h"

void func(char **str);

int main()
{
	char *str[20];
	(*str) = "1234567890abcdefg";
	func(str);
	printf("%s", *str);

}
void func(char **str)
{
	(*str)++;
	(*str)++;
	(*str)++;
	(*str)++;
	(*str)++;
	(*str)++;
}
