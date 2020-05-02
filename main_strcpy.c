/*
 * A small program that illustrates how to call the maxofthree function we wrote in
 * assembly language.
 */

#include "libasm.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

int	main(void) {
	char	dest[10] = "abcdefghij";
	char	src[6] = "hello";
	char	dest2[10] = "abcdefjhij";
	char	src2[6] = "hello";

	printf("STRCPY :\n");
	printf("AVANT : \n");
	ft_putstr(dest);
	printf("\n");
	ft_putstr(src);
	printf("\n");

	printf("return value : %s\n", strcpy(dest, src));

	printf("\nAPRES : \n");
	ft_putstr(dest);
	printf("\n");
	ft_putstr(src);
	printf("\n");

	printf("\nFT_STRCPY :\n");
	printf("AVANT : \n");
	ft_putstr(dest2);
	printf("\n");
	ft_putstr(src2);
	printf("\n");

	printf("return value : %s\n", ft_strcpy(dest2, src2));

	printf("\nAPRES : \n");
	ft_putstr(dest2);
	printf("\n");
	ft_putstr(src2);
	printf("\n");
	return (0);
}
