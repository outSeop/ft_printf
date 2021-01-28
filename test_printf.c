#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft/libft.h"

char		*my_str_cpy(char *, char , int);

int main()
{
	char *arr;
	arr = malloc(10);
	strcpy(arr, "migaehada");
	printf("before: %s\n", arr);
	arr = my_str_cpy(arr, '0', 20);
	printf("after: %s\n", arr);

	while(1){}
}

char		*my_str_cpy(char *str, char c, int nbr)
{
	char	*temp;
	int		size;
	int		i;
	int		j;

	size = ft_strlen(str);
	if (size >= nbr)
		return (str);
	temp = malloc(nbr + 1);
	i = 0;
	while (i < nbr - size)
		temp[i++] = c;
	j = 0;
	while (str[j])
		temp[i + j - 1] = str[j++];
	temp[i + j] = '\0';
	free(str);
	str = temp;
	return (str);
}
