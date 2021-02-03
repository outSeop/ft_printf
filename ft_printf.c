/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inssong </var/mail/inssong>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 19:13:09 by inssong           #+#    #+#             */
/*   Updated: 2021/02/03 19:30:14 by inssong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int			ft_printf(const char *format, ...)
{
	int		i;
	t_tag	*tag;
	char	*temp;

	temp = ft_strdup(format);
	va_start(g_ap, format);
	check(&temp, tag);
	va_end(g_ap);
	return (1);
}

int				check(char **format, t_tag *tag)
{

	while (**format)
	{
		if (**format == '%')
		{
			tag = initTag();
			check_type(format, tag);
			free(tag->argument);
		}
		else
			write(1, *format, 1);
		(*format)++;
	}
	return (1);
}
