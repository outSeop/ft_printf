/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inssong <inssong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:40:17 by inssong           #+#    #+#             */
/*   Updated: 2021/02/23 21:42:10 by inssong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	t_tag		*tag;
	char		*temp;
	char		*rm;
	int			size;

	va_start(g_ap, format);
	temp = ft_strdup(format);
	rm = temp;
	tag = malloc(sizeof(t_tag));
	size = check(&temp, tag);
	save_free((void**)&tag);
	save_free((void**)&rm);
	va_end(g_ap);
	return (size);
}

int				check(char **format, t_tag *tag)
{
	int			size;

	size = 0;
	while (**format)
	{
		if (**format == '%')
		{
			init_tag(tag);
			size += check_type(format, tag);
		}
		else
		{
			write(1, *format, 1);
			size++;
		}
		(*format)++;
	}
	return (size);
}
