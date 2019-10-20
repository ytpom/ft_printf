#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"

void ft_printf(char *,...); 				//Our printf function
char* convert(unsigned int, int); 		//Convert integer number into octal, hex, etc.

#endif
