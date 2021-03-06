/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inssong <inssong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:31:11 by inssong           #+#    #+#             */
/*   Updated: 2021/02/23 21:43:05 by inssong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*my_str_cpy(char *str, char c, int nbr)
{
	char		*temp;
	int			size;
	int			i;
	int			j;

	size = ft_strlen(str);
	if (size >= nbr)
		return (str);
	temp = malloc(nbr + 1);
	i = 0;
	while (i < nbr - size)
		temp[i++] = c;
	j = 0;
	while (str[j])
	{
		temp[i + j - 1] = str[j];
		j++;
	}
	temp[i + j] = '\0';
	save_free((void**)&str);
	str = temp;
	return (str);
}

void			init_tag(t_tag *tag)
{
	tag->sign = 0;
	tag->arg_len = 1;
	tag->precision = 0;
	tag->prec_len = 0;
	tag->argument = NULL;
	tag->fill = ' ';
	tag->width = 0;
}

char			*my_itoa(unsigned int n)
{
	long long	tmp;
	int			len;
	char		*res;

	len = 0;
	tmp = n;
	len += a_get_len(tmp);
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	res[--len] = tmp % 10 + '0';
	while (tmp /= 10)
		res[--len] = tmp % 10 + '0';
	return (res);
}

int				a_get_len(long long tmp)
{
	if (tmp < 10)
		return (1);
	return (a_get_len(tmp / 10) + 1);
}

void			save_free(void **pointer)
{
	if (pointer)
	{
		free(*pointer);
		*pointer = NULL;
	}
}
