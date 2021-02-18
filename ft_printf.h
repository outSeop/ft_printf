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
	int					precision;
	int					width;
	int					arg_len;
	int					prec_len;
	char				*argument;
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
void					init_tag(t_tag *tag);
void					trance_c(char c, t_tag *tag);
void					trance_s(char *s, t_tag *tag);
void					trance_d(int d, t_tag *tag);
void					trance_u(unsigned int u, t_tag *tag);
void					trance_p(void *p, t_tag *tag);
void					trance_hex(int value, char *arr, t_tag *t_tag);
void					trance_bin(int n);
char					*algin(t_tag *tag);
char					*align_left(t_tag *tag);
char					*refine(t_tag *tag);
char					*insert_char(t_tag *tag, int idx, int size, char c);
char					*slice_str(t_tag *tag);
char					*combine_fill(t_tag *tag, int size, char fill);
char					*my_itoa(unsigned int n);
int						a_get_len(long long tmp);

#endif
