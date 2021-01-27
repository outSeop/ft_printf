#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#define ERROR -1
#define FALSE 0
#define TRUE 1
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int 		ft_printf(const char* , ...);
int			check_type(char *tpye);
int			check_specifier(char *str);
int			check_flag(char *str);

#endif
