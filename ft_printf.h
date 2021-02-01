#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#define ERROR -1
#define FALSE 0
#define TRUE 1

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct 			s_tag
{
	char				sign;
	char				fill;
	int					width;
	int					arg_len;
	int					prec_len;
	char				*argument;
	char				*print_out;
	char				specifier;
}						t_tag;

va_list	g_ap;

int 					ft_printf(const char* , ...);
int						check(char **str, t_tag *tag);
int						check_type(char **format, t_tag *tag);
int						check_flag(char **format, t_tag *tag);
int						check_width(char **format, t_tag *tag);
int						check_precision(char **format, t_tag *tag);
int						check_specifier(char **format, t_tag *tag);
t_tag					*initTag();
char					*trance_c(char c);
char					*trance_s(char *s);
char					*trance_d(int d);
char					*trance_u(unsigned int u);
char					*trance_p(void *p);
char			*my_itoa(unsigned int n);
int				a_get_len(long long tmp);

#endif
