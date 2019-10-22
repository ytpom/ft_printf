#include <stdio.h>
#include "main.h"

int	main()
{
	const char* s = "Hello";
	printf("Strings:\n");
	printf("%%");
	printf("%5%");
	printf("%-5%");
	printf("%.0%");
	printf("\t.%10s.\n\t.%-10s.\n\t.%*s.\n", s, s, 10, s);

	printf("Characters:\t%c %%\n", 65);

	printf("Integers\n");
	printf("Decimal:\t%i %d %.6i %i %.0i123 %+i %u\n", 1, 2, 3, 0, 0, 4, -1);
	printf("Hexadecimal:\t%x %x %X %#x %x %x %d %#x\n", 5, 10, 10, 6, 42, -42, -42, 0);
	printf("Octal:\t%o %#o %#o\n", 10, 10, 4);

	printf("Floating point\n");
	printf("Rounding:\t%f %.0f %.32f\n", 1.5, 1.5, 1.3);
	printf("Padding:\t%05.2f %.2f %5.2f\n", 1.5, 1.5, 1.5);
	printf("Scientific:\t%E %e\n", 1.5, 1.5);
	printf("Hexadecimal:\t%a %A\n", 1.5, 1.5);

	ft_printf("Strings:\n");
	ft_printf("%%");
	ft_printf("%5%");
	ft_printf("%-5%");
	ft_printf("%.0%");
	ft_printf("\t.%10s.\n\t.%-10s.\n\t.%*s.\n", s, s, 10, s);

	ft_printf("Characters:\t%c %%\n", 65);

	ft_printf("Integers\n");
	ft_printf("Decimal:\t%i %d %.6i %i %.0i123 %+i %u\n", 1, 2, 3, 0, 0, 4, -1);
	ft_printf("Hexadecimal:\t%x %x %X %#x %x %x %d %#x\n", 5, 10, 10, 6, 42, -42, -42, 0);
	ft_printf("Octal:\t%o %#o %#o\n", 10, 10, 4);

	ft_printf("Floating point\n");
	ft_printf("Rounding:\t%f %.0f %.32f\n", 1.5, 1.5, 1.3);
	ft_printf("Padding:\t%05.2f %.2f %5.2f\n", 1.5, 1.5, 1.5);
	ft_printf("Scientific:\t%E %e\n", 1.5, 1.5);
	ft_printf("Hexadecimal:\t%a %A\n", 1.5, 1.5);

}
