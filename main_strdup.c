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
	char	*str;
	char	*cpy;
	

	if (!(str = malloc(sizeof(char) * 6)))
		return (0);
	str[0] = 'h';
	str[1] = 'e';
	str[2] = 'l';
	str[3] = 'l';
	str[4] = 'o';
	str[5] = '\0';

	printf("str : %s\n", str);
	cpy = strdup(str);
	printf("cpy : %s\n", cpy);
	printf("dup : %s\n", ft_strdup(str));
	

	
	return (0);
}
