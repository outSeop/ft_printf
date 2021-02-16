#include "ft_printf.h"

char			*algin(t_tag *tag)
{
	int			added_size;
	int			inserted;

	added_size = 0;
	inserted = 0;
	if (tag->fill == '-')
		return (align_left(tag));
	else
	{
		if (tag->sign < 0 && (tag->specifier == 'd' || tag->specifier == 'i'))
		{
			if (tag->fill == '0')
				inserted = 1;
		}
	return (insert_char(tag->argument, inserted, tag->width, tag->fill));
	}
}

char			*refine(t_tag *tag)
{
	if (tag->specifier == 's')
		return (slice_str(tag));
	else
	{
		if (tag->sign < 0 && (tag->specifier == 'd' || tag->specifier == 'i'))
			return (insert_char(tag->argument, 1, tag->prec_len + 1, '0'));
		if (tag->specifier == 'p')
			return (insert_char(tag->argument, 2, tag->prec_len + 2, '0'));
		if (tag->prec_len == 0 && tag->argument[0] == '0' && tag->precision == 1)
		{
			free(tag->argument);
			tag->argument = malloc(1);
			tag->argument[0] = 0;
			tag->arg_len = 1;
			return (tag->argument);
		}
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
/*
char			*insert_char(char *str, int inserted_idx, int size, char c)
{
	char		*result;
	int			i;
	int			j;
	int			str_len;

	str_len = ft_strlen(str);
	if (str_len > size)
		return (str);
	if (!(result = malloc(size + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < inserted_idx)
	{
		result[i] = str[i];
		i++;
	}
	while (i + j < size - (int)ft_strlen(str) + inserted_idx)
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
*/
char			*insert_char(char *str, int idx, int size, char c)
{
	char		*result;
	int			i;
	int			str_len;

	str_len = ft_strlen(str);
	if (str_len > size)
		return (str);
	if (!(result = malloc(size + 1)))
		return (NULL);
	i = 0;
	ft_strlcpy(result, str, idx);
	/*
	printf("\n===test====\n");
	printf("%s\n", result);
	*/
	while (i < size - str_len)
	{
		result[idx + i] = c;
		i++;
	}
	ft_strlcpy(result + idx + i, str + idx, str_len - idx + 1);
	result[size] = '\0';
	free(str);
	return (result);
}
