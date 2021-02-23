/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inssong <inssong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:30:45 by inssong           #+#    #+#             */
/*   Updated: 2021/02/23 21:42:49 by inssong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (insert_char(tag, inserted, tag->width, tag->fill));
	}
}

char			*refine(t_tag *tag)
{
	if (tag->specifier == 's')
		return (slice_str(tag));
	else
	{
		if (tag->sign < 0 && (tag->specifier == 'd' || tag->specifier == 'i'))
			return (insert_char(tag, 1, tag->prec_len + 1, '0'));
		if (tag->prec_len == 0 && tag->argument[2] == '0'
			&& tag->precision == 1 && tag->specifier == 'p')
		{
			ft_strlcpy(tag->argument, "0x", 3);
			tag->arg_len = 2;
			return (tag->argument);
		}
		if (tag->specifier == 'p')
			return (insert_char(tag, 2, tag->prec_len + 2, '0'));
		if (tag->prec_len == 0 && tag->argument[0] == '0'
			&& tag->precision == 1)
		{
			ft_strlcpy(tag->argument, "\0", 1);
			tag->arg_len = 0;
			return (tag->argument);
		}
		else
			return (insert_char(tag, 0, tag->prec_len, '0'));
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
	save_free((void**)&tag->argument);
	return (result);
}

char			*align_left(t_tag *tag)
{
	char		*result;
	int			total_size;
	int			i;

	if (tag->arg_len > tag->width)
		return (tag->argument);
	total_size = tag->width;
	result = malloc(total_size + 1);
	i = 0;
	while (i < tag->arg_len)
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
	save_free((void**)&tag->argument);
	return (result);
}

char			*insert_char(t_tag *tag, int idx, int size, char c)
{
	char		*result;
	int			i;
	int			str_len;

	str_len = tag->arg_len;
	if (str_len > size)
		return (tag->argument);
	if (!(result = malloc(size + 1)))
		return (NULL);
	i = 0;
	ft_memcpy(result, tag->argument, idx + 1);
	while (i < size - str_len)
	{
		result[idx + i] = c;
		i++;
	}
	ft_memcpy(result + idx + i, tag->argument + idx, str_len - idx + 1);
	result[size] = '\0';
	tag->arg_len = size;
	save_free((void**)&tag->argument);
	return (result);
}
