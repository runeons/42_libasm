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
	char	dest[5] = "zab\0a";
	char	src[7] = "zab\0b";
	char	dest2[5] = "zab\0a";
	char	src2[7] = "zab\0b";

	printf("STRCMP :\n");
	printf("AVANT : \n");
	ft_putstr(dest);
	printf("\n");
	ft_putstr(src);
	printf("\n");

	printf("return value : %d\n", strcmp(dest, src));
/*
	printf("\nAPRES : \n");
	ft_putstr(dest);
	printf("\n");
	ft_putstr(src);
	printf("\n");
*/
	printf("\nFT_STRCMP :\n");
	printf("AVANT : \n");
	ft_putstr(dest2);
	printf("\n");
	ft_putstr(src2);
	printf("\n");

	printf("return value : %d\n", ft_strcmp(dest2, src2));
/*
	printf("\nAPRES : \n");
	ft_putstr(dest2);
	printf("\n");
	ft_putstr(src2);
	printf("\n");
*/
	return (0);
}
