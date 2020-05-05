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
	char	buf[12] = {0};
	char	buff[12] = {0};

	
	printf("cpy : %s\n", strcpy(buf, ""));
	printf("fcpy : %s\n", ft_strcpy(buff, ""));
	printf("\n");
	printf("cpy : %s\n", strcpy(buf, "abc"));
	printf("fcpy : %s\n", ft_strcpy(buff, "abc"));
	printf("\n");
	printf("cpy : %s\n", strcpy(buf, "d\0ef"));
	printf("fcpy : %s\n", ft_strcpy(buff, "d\0ef"));
	printf("\n");
	return (0);
}
