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
	char	*str2;
	char	*str3;

	if (!(str = malloc(sizeof(char) * 6)))
		return (0);
	str[0] = 'h';
	str[1] = 'e';
	str[2] = 'l';
	str[3] = 'l';
	str[4] = 'o';
	str[5] = '\0';

	printf("str : %s\n", str);
	printf("dup : %s\n", strdup(str));
	printf("fdup : %s\n", ft_strdup(str));
	printf("\n");

/*
	str2 = NULL;
	printf("str : %s\n", str2);
	printf("dup : %s\n", strdup(str2));
	//printf("fdup : %s\n", ft_strdup(str2));
	printf("\n");
*/	
	if (!(str2 = malloc(sizeof(char) * 0)))
		return (0);
	printf("str : %s\n", str2);
	printf("dup : %s\n", strdup(str2));
	printf("fdup : %s\n", ft_strdup(str2));
	printf("\n");

	if (!(str3 = malloc(sizeof(char) * 1)))
		return (0);
	str3[0] = 'Z';
	printf("str : %s\n", str3);
	printf("dup : %s\n", strdup(str3));
	printf("fdup : %s\n", ft_strdup(str3));
	printf("\n");
	
	return (0);
}
