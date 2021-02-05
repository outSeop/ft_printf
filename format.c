#include "ft_printf.h"

char			*algin(t_tag *tag)
{
	if (tag->fill == '-')
		return (align_left(tag));
	else
		return (combine_fill(tag, tag->width, tag->fill));
}

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
	i = 0;
	while (i < fill_size)
		result[i++] = fill;
	j = 0;
	while (i < total_size)
		result[i++] = tag->argument[j++];
	result[i] = '\0';
	free(tag->argument);
	tag->arg_len = total_size;
	printf("total size: %d\n", total_size);
	return (result);
	}

	char		*align_left(t_tag *tag)
	{
		char	*result;
		int		total_size;
		int		i;

		if (tag->arg_len > tag->width)
			return (tag->argument);
		total_size = tag->width;
		result = malloc(total_size + 1);
		i = 0;
		while (tag->argument[i])
		{
			result[i] = tag->argument[i];
			i++;
		}
		while (i < total_size)
		{
			result[i] = ' ';
			i++;
		}
		result[i] = '\0';
		free(tag->argument);
		return (result);
	}
