#include "ft_printf.h"
    #define STR "world"
    #define test1    "%0p", STR
    #define test2    "%020p", STR
    #define test3    "%0.20p", STR
    #define test4    "%03p", STR
    #define test5    "%0.3p", STR
    #define test6    "%020.5p", STR
    #define test7    "%05.20p", STR
    #define test8    "%07.5p", STR
    #define test9    "%05.7p", STR
int main() {




    printf("\n----------1---------\n");
    printf("|\nreturn : %d\n", ft_printf(test1));
    printf("|\nreturn : %d", printf(test1));
    printf("\n----------2---------\n");
    printf("|\nreturn : %d\n", ft_printf(test2));
    printf("|\nreturn : %d", printf(test2));
    printf("\n----------3---------\n");
    printf("|\nreturn : %d\n", ft_printf(test3));
    printf("|\nreturn : %d", printf(test3));
    printf("\n----------4---------\n");
    printf("|\nreturn : %d\n", ft_printf(test4));
    printf("|\nreturn : %d", printf(test4));
    printf("\n----------5---------\n");
    printf("|\nreturn : %d\n", ft_printf(test5));
    printf("|\nreturn : %d", printf(test5));
    printf("\n----------6---------\n");
    printf("|\nreturn : %d\n", ft_printf(test6));
    printf("|\nreturn : %d", printf(test6));
    printf("\n----------7---------\n");
    printf("|\nreturn : %d\n", ft_printf(test7));
    printf("|\nreturn : %d", printf(test7));
    printf("\n----------8---------\n");
    printf("|\nreturn : %d\n", ft_printf(test8));
    printf("|\nreturn : %d", printf(test8));
    printf("\n----------9---------\n");
    printf("|\nreturn : %d\n", ft_printf(test9));
    printf("|\nreturn : %d", printf(test9));
}
