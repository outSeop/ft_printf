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
	char				flag;
	char				width;
	char				precision;
	char				specifier;
	int					size;
	int					arg_len;
	char				*argument;
	char				*print_out;
}						t_tag;

int 					ft_printf(const char* , ...);
int						check(const char *format);
int						check_flag(const char *format);
int						check_width(const char *format);
int						check_type(const char *format);
int						check_precision(const char *format, int width);
int						check_specifier(const char *format);

#endif
