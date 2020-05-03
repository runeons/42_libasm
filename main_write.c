/*
 * A small program that illustrates how to call the maxofthree function we wrote in
 * assembly language.
 */

#include "libasm.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <error.h>
//extern	__error

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

int	main(void) {
	char	str[3] = "abc";

	printf("str : %p\n", str);
	printf("&str : %p\n", &str);

	printf("|ret : %zd\n", write(1, &str, 0));
	printf("|ret : %zd\n", ft_write(1, &str, 0));
	printf("\n");
	errno = 0;
	printf("|ret : %zd\n", write(1, &str, -1));
	printf("errno : %i\n", errno);
	printf("strerror : %s\n", strerror(errno));
	perror("perror : ");
	errno = 0;
	printf("|ret : %zd\n", ft_write(1, &str, -1));
	printf("errno : %i\n", errno);
	printf("strerror : %s\n", strerror(errno));
	perror("perror : ");
	//printf("___errno : %i\n", error(errno));
	printf("\n");
	printf("|ret : %zd\n", write(1, &str, 1));
	printf("|ret : %zd\n", ft_write(1, &str, 1));
	printf("\n");
	printf("|ret : %zd\n", write(1, &str, 3));
	printf("|ret : %zd\n", ft_write(1, &str, 3));
	printf("\n");
	printf("|ret : %zd\n", write(1, &str, 4));
	printf("|ret : %zd\n", ft_write(1, &str, 4));
	printf("\n");
	printf("|ret : %zd\n", write(1, &str, 5));
	printf("|ret : %zd\n", ft_write(1, &str, 5));
	printf("\n");
	return (0);
}
