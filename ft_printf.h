/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inssong <inssong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:39:55 by inssong           #+#    #+#             */
/*   Updated: 2021/02/23 21:35:06 by inssong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef	struct			s_tag
{
	char				sign;
	char				fill;
	char				specifier;
	int					precision;
	int					width;
	int					arg_len;
	int					prec_len;
	char				*argument;
}						t_tag;

va_list					g_ap;

int						ft_printf(const char *format, ...);
int						check(char **str, t_tag *tag);
int						check_type(char **format, t_tag *tag);
void					check_flag(char **format, t_tag *tag);
void					check_width(char **format, t_tag *tag);
void					check_precision(char **format, t_tag *tag);
void					check_specifier(char **format, t_tag *tag);
void					init_tag(t_tag *tag);
void					trance_c(char c, t_tag *tag);
void					trance_s(char *s, t_tag *tag);
void					trance_d(int d, t_tag *tag);
void					trance_u(unsigned int u, t_tag *tag);
void					trance_p(void *p, t_tag *tag);
void					trance_hex(int value, char *arr, t_tag *tag);
char					*algin(t_tag *tag);
char					*align_left(t_tag *tag);
char					*refine(t_tag *tag);
char					*insert_char(t_tag *tag, int idx, int size, char c);
char					*slice_str(t_tag *tag);
char					*my_itoa(unsigned int n);
int						a_get_len(long long tmp);
void					save_free(void **pointer);

#endif
