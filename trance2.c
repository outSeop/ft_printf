/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trance2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inssong <inssong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:37:39 by inssong           #+#    #+#             */
/*   Updated: 2021/02/23 22:23:22 by inssong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				trance_p(void *p, t_tag *tag)
{
	long long		i;
	int				j;
	long long		lp;

	lp = (long long)p;
	tag->argument = malloc(19);
	tag->argument[0] = '0';
	tag->argument[1] = 'x';
	tag->argument[2] = 0;
	i = 4 * 15;
	j = 2;
	while (i >= 0)
	{
		tag->argument[j] = "0123456789abcdef"[((lp >> i) & 15)];
		if (tag->argument[2] != '0')
			j++;
		i -= 4;
	}
	if (j == 2)
		tag->argument[j++] = '0';
	tag->argument[j] = '\0';
	tag->arg_len = ft_strlen(tag->argument);
}

void				trance_hex(int value, char *arr, t_tag *tag)
{
	int				i;
	int				j;

	tag->argument = malloc(9);
	tag->argument[0] = 0;
	i = 4 * 7;
	j = 0;
	while (i >= 0)
	{
		tag->argument[j] = arr[((value >> i) & 15)];
		if (tag->argument[0] != '0')
			j++;
		i -= 4;
	}
	if (j == 0)
		j++;
	tag->argument[j] = '\0';
	tag->arg_len = ft_strlen(tag->argument);
}
