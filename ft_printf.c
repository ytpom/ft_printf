#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

void	ft_putnbr_l(long long int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n / 10)
		ft_putnbr_l(n / 10);
	ft_putchar(n % 10 + '0');
}

int		ft_nbr_len(long long nb, int base)
{
	int i;

	i = 0;
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(long long value, int base)
{
	int		i;
	int		n;
	int		len;
	char	*radix;
	char	*result;

	i = 0;
	n = 0;
	len = 0;
	radix = "0123456789ABCDEF";
	if (value == 0)
		return ("0");
	if (base == 10 && value < 0)
		n = 1;
	len = ft_nbr_len(value, base);
	result = (char*)malloc(sizeof(char) * (len + n + 1));
	if (result == NULL)
		return (NULL);
	if (n == 1)
	{
		result[0] = '-';
		len++;
	}
	result[len] = '\0';
	if (value < 0)
		value *= -1;
	while (len > n)
	{
		result[len - 1] = radix[value % base];
		value /= base;
		len--;
	}
	return (result);
}

char	*ft_strlow(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

int ft_printf(char* format,...) 
{ 
	char *traverse; 
	long long int i; 
	char *s; 
	
	//Module 1: Initializing Myprintf's arguments 
	va_list arg; 
	va_start(arg, format);
	int left;
	int right;
	int tmp;
	unsigned long int li;
	char *str;
	int flag;
	int flag2;
	size_t len;
	
	traverse = format;
	len = 0;
	while (*traverse != '\0') 
	{
		flag = 0;
		flag2 = 0;
		left = 0;
		right = 0;
		if (*traverse == '%')
		{
			traverse++;
			if (*traverse == '\0')
				break;
			if (*traverse == '#')
			{
				traverse++;
				flag2 = 1;
			}
			if (*traverse == 'l')
			{
				traverse++;
				flag = 2;
			}
			if (*traverse == 'l')
			{
				traverse++;
				flag = 3;
			}
			if (*traverse == 'h')
			{
				traverse++;
				flag = 4;
			}
			if (*traverse == 'h')
			{
				traverse++;
				flag = 5;
			}
			if (*traverse == '0')
			{
				traverse++;
				flag = 6;
			}
			while(ft_isdigit(*traverse))
			{
				left = left * 10 + *traverse - '0';
				traverse++;
			}
			while(*traverse == ' ')
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
			if (*traverse == '.' && left == 0)
			{
				traverse++;
				if (*traverse == '0')
				{
					traverse++;
					if (*traverse == '%')
					{
						ft_putchar ('%');
						len++;
						continue;
					}
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
			if (*traverse == '%')
			{
				tmp = left - 1;
				while (tmp > 0)
				{
					ft_putchar(' ');
					tmp--;
					len++;
				}
				ft_putchar ('%');
				len++;
				tmp = right - 1;
				while (tmp > 0)
				{
					ft_putchar(' ');
					tmp--;
					len++;
				}
			}
			if (*traverse == 's')
			{
				s = va_arg(arg,char *);
				tmp = left - ft_strlen(s);
				while (tmp > 0)
				{
					ft_putchar(' ');
					tmp--;
					len++;
				}
				ft_putstr(s);
				len += ft_strlen(s);
				tmp = right - ft_strlen(s);
				while (tmp > 0)
				{
					ft_putchar(' ');
					tmp--;
					len++;
				}		
			}
			if (*traverse == '+')
			{
				traverse++;
				ft_putchar('+');
				len++;
			}
			//if (*traverse != 'c' && *traverse != 'd' && *traverse != 'i' && *traverse != 'u' && *traverse != 'x' && *traverse != 'X' && *traverse != 'o' && *traverse != '\0')
			//	traverse++;
			if (*traverse == 'c')
			{
				i = va_arg(arg,int);
				ft_putchar(i);
				len++;
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
				tmp = ft_power(10,left) / right;
				while (tmp > 10)
				{
					ft_putchar('0');
					tmp = tmp / 10;
				}
				
				ft_putnbr(i);
				len += ft_nbr_len(i,10);
			}
			if (*traverse == 'u')
			{
				i = va_arg(arg,int);
				li = i;
				ft_putnbr_l(li);
				len += ft_nbr_len(i,10);
			}
			if (*traverse == 'x')
			{
				if (flag == 5)
					i = (unsigned char)va_arg(arg,int);
				else if (flag == 4)
					i = (unsigned short)va_arg(arg,int);
				else if (flag == 3)
					i = va_arg(arg,unsigned long long); 
				else if (flag == 2)
					i = va_arg(arg,unsigned long);
				else
					i = va_arg(arg,unsigned int);
				str = ft_strlow(ft_itoa_base(i,16));
				tmp = left - ft_strlen(str);
				while (tmp > 0)
				{
					if (flag == 6)
						ft_putchar('0');
					else	
						ft_putchar(' ');
					tmp--;
					len++;
				}

				if (flag2 == 1 && ft_strcmp (str,"0"))
				{
					ft_putstr("0x");
					len += 2;
				}
				ft_putstr(str);
				len += ft_strlen(str);

				tmp = right - ft_strlen(str);
				while (tmp > 0)
				{
					ft_putchar(' ');
					tmp--;
					len++;
				}	

			}
			if (*traverse == 'X')
			{
				if (flag == 5)
					i = (unsigned char)va_arg(arg,int);
				else if (flag == 4)
					i = (unsigned short)va_arg(arg,int);
				else if (flag == 3)
					i = va_arg(arg,unsigned long long); 
				else if (flag == 2)
					i = va_arg(arg,unsigned long);
				else
					i = va_arg(arg,unsigned int);
				str = ft_itoa_base(i,16);
				if (flag2 == 1)
				{
					ft_putstr("0X");
					len += 2;
				}
				ft_putstr(str);
				len += ft_strlen(str);
			}
			if (*traverse == 'o')
			{
				i = va_arg(arg,int);
				str = ft_strlow(ft_itoa_base(i,8));
				if (flag == 1)
				{
					ft_putstr("0");
					len++;
				}
				ft_putstr(str);
				len += ft_strlen(str);
			}
			if (*traverse != '\0')
				traverse++;
		}
		if (*traverse != '\0')
		{
			ft_putchar(*traverse);
			len++;
		}
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
		if (*traverse != '\0')
		{
			traverse++;
		}
	} 
	
	//Module 3: Closing argument list to necessary clean-up
	va_end(arg); 
	return (len);
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