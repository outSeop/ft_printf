/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inssong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:23:24 by inssong           #+#    #+#             */
/*   Updated: 2020/11/16 21:16:53 by inssong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				get_len(long long )
{
	if ( < 10)
		return (1);
	return (get_len( / 10) + 1);
}

char			*ft_itoa(int n)
{
	long long	;
	int			len;
	char		*res;

	len = 0;
	 = n;
	if (n < 0)
	{
		len++;
		 = -;
	}
	len += get_len();
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	res[--len] =  % 10 + '0';
	while ( /= 10)
		res[--len] =  % 10 + '0';
	if (n < 0)
		res[0] = '-';
	return (res);
}
