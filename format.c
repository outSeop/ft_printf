#include "ft_printf.h"

char			*combine_fill(t_tag *tag, int size, char fill)
{
	char		*result;
	int			total_size;
	int			fill_size;
	int			i;
	int			j;

	if (tag->arg_len > size)
		return (tag->argument);
	total_size = size;
	fill_size = total_size - tag->arg_len;
	result = malloc(total_size + 1);
	result[total_size] = '\0';
	i = 0;
	while (i < fill_size)
		result[i++] = fill;
	j = 0;
	while (i < total_size)
		result[i++] = tag->argument[j++];
	free(tag->argument);
	tag->arg_len = total_size;
	return (result);
}
