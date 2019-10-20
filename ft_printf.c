#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

void ft_printf(char* format,...) 
{ 
	char *traverse; 
	unsigned int i; 
	char *s; 
	
	//Module 1: Initializing Myprintf's arguments 
	va_list arg; 
	va_start(arg, format);
	int left;
	int right;
	int tmp;
	
	traverse = format;
	while (*traverse) 
	{
		left = 0;
		right = 0;
		if (*traverse == '%')
		{
			traverse++;
			if (*traverse == '\0')
				break;
			if (*traverse == '%')
				ft_putchar ('%');
			while(ft_isdigit(*traverse))
			{
				left = left * 10 + *traverse - '0';
				traverse++;
			}
			if (*traverse == '-')
			{
				traverse++;
				while(ft_isdigit(*traverse))
				{
					right = right * 10 + *traverse - '0';
					traverse++;
				}
			}
			if (*traverse == '*')
			{
				i = va_arg(arg,int);
				left = i;
				traverse++;
			}
			if (*traverse == 's')
			{
				s = va_arg(arg,char *);
				tmp = left - ft_strlen(s);
				while (tmp > 0)
				{
					ft_putchar(' ');
					tmp--;
				}
				ft_putstr(s);
				tmp = right - ft_strlen(s);
				while (tmp > 0)
				{
					ft_putchar(' ');
					tmp--;
				}		
			}
			if (*traverse == 'c')
			{
				i = va_arg(arg,int);
				ft_putchar(i);
			}
			if (*traverse == '.')
			{
				traverse++;
				if (*traverse == '0')
				{
					traverse++;
					i = va_arg(arg,int);
					traverse++;
					continue;
				}
				while(ft_isdigit(*traverse))
				{
					left = left * 10 + *traverse - '0';
					traverse++;
				}
			}
			if (*traverse == '+')
			{
				traverse++;
				ft_putchar('+');
			}
			if (*traverse == 'd' || *traverse == 'i')
			{
				i = va_arg(arg,int);
				tmp = i;
				right = 1;
				while (tmp / 10)
				{
					right = right * 10;
					tmp = tmp / 10;
				}
				//printf("left = %lld\n", ft_power(10,left));
				tmp = ft_power(10,left) / right;
				while (tmp > 10)
				{
					ft_putchar('0');
					tmp = tmp / 10;
				}
				ft_putnbr(i);
			}
			traverse++;
		}
		//while( *traverse != '%' || *traverse != '\0' ) 
		//{ 
			ft_putchar(*traverse);
		//	traverse++; 
		//} 
		
		//traverse++; 
		
		//Module 2: Fetching and executing arguments
		/*switch(*traverse) 
		{ 
			case 'c' : i = va_arg(arg,int);		//Fetch char argument
						ft_putchar(i);
						break; 
						
			case 'd' : i = va_arg(arg,int); 		//Fetch Decimal/Integer argument
						if(i<0) 
						{ 
							i = -i;
							ft_putchar('-'); 
						} 
						ft_putstr(convert(i,10));
						break; 
						
			case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
						ft_putstr(convert(i,8));
						break; 
						
			case 's': s = va_arg(arg,char *); 		//Fetch string
						ft_putstr(s); 
						break; 
						
			case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
						ft_putstr(convert(i,16));
						break; 
		}*/
		traverse++;
	} 
	
	//Module 3: Closing argument list to necessary clean-up
	va_end(arg); 
} 

char *convert(unsigned int num, int base) 
{ 
	static char Representation[]= "0123456789ABCDEF";
	static char buffer[50]; 
	char *ptr; 
	
	ptr = &buffer[49]; 
	*ptr = '\0'; 
	
	do 
	{ 
		*--ptr = Representation[num%base]; 
		num /= base; 
	}while(num != 0); 
	
	return(ptr); 
}