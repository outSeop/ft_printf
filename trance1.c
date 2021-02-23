/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trance1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inssong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:39:59 by inssong           #+#    #+#             */
/*   Updated: 2021/02/23 19:40:02 by inssong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			trance_c(char c, t_tag *tag)
{
	tag->argument = malloc(sizeof(c) + 1);
	tag->argument[0] = c;
	tag->argument[1] = '\0';
	tag->arg_len = 1;
}

void			trance_s(char *s, t_tag *tag)
{
	if (!s)
		tag->argument = ft_strdup("(null)");
	else
		tag->argument = ft_strdup(s);
	tag->arg_len = ft_strlen(tag->argument);
}

void			trance_d(int d, t_tag *tag)
{
	if (d < 0)
		tag->sign = -1;
	tag->argument = ft_itoa(d);
	tag->arg_len = ft_strlen(tag->argument);
}

void			trance_u(unsigned int u, t_tag *tag)
{
	tag->argument = my_itoa(u);
	tag->arg_len = ft_strlen(tag->argument);
}
