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
int						check(const char *str);
int						check_type(const char *format);
int						check_flag(const char *format, t_tag *tag);
int						check_width(const char *format, t_tag *tag);
int						check_precision(const char *format, t_tag *tag);
int						check_specifier(const char *format, t_tag *tag);
t_tag					*initTag();

#endif
