#include "ft_printf.h"

char			*algin(t_tag *tag)
{
	if (tag->fill == '-')
		return (align_left(tag));
	else
	{
		if (tag->sign < 0 && tag->specifier == 'd')
			return (insert_char(tag->argument, 1, tag->width, tag->fill));
		else
			return (insert_char(tag->argument, 0, tag->width, tag->fill));

	}
}

char			*refine(t_tag *tag)
{
	if (tag->specifier == 's')
		return (slice_str(tag));
	else
	{
		if (tag->sign < 0 && tag->specifier == 'd')
			return (insert_char(tag->argument, 1, tag->prec_len, '0'));
		else
			return (insert_char(tag->argument, 0, tag->prec_len, '0'));
	}
}

char			*slice_str(t_tag *tag)
{
	char		*result;
	int			i;

	if (tag->arg_len < tag->prec_len || tag->precision == 0)
		return (tag->argument);
	if (!(result = malloc(tag->prec_len + 1)))
		return (NULL);
	i = 0;
	while (i < tag->prec_len)
	{
		result[i] = tag->argument[i];
		i++;
	}
	result[i] = '\0';
	tag->arg_len = tag->prec_len;
	free(tag->argument);
	return (result);
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
		tag->arg_len = total_size;
		free(tag->argument);
		return (result);
	}

char			*insert_char(char *str, int inserted_idx, int size, char c)
{
	char		*result;
	int			fill_size;
	int			i;
	int			j;

	if (!(result = malloc(size + 1)))
		return (NULL);
	i = 0;
	while (i < inserted_idx)
	{
		result[i] = str[i];
		i++;
	}
	while (j + inserted_idx < size - ft_strlen(str))
	{
		result[i + j] = c;
		j++;
	}
	while (i + j < size)
	{
		result[i + j] = str[i];
		i++;
	}
	result[size] = '\0';
	free(str);
	return (result);
}

