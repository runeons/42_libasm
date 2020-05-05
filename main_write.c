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
#include <fcntl.h>

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
	char	*str2;
	char	str3[0] = "";
	int	fd;
	int	fd2;

	fd = open("./test2", O_RDWR);
	fd2 = open("./test", O_RDONLY);
	
	str2 = NULL;

	printf("str : %p\n", str);
	printf("&str : %p\n", &str);
	printf("\n");

	// 9 : Bad file descriptor (RDONLY)

	errno = 0;
	printf("|ret : %zd\n", write(fd2, &str, 2));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_write(fd2, &str, 2));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	// 9 : Bad file descriptor (RANDOM)
	errno = 0;
	printf("|ret : %zd\n", write(4, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_write(4, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	// 14 : Bad address
	errno = 0;
	printf("|ret : %zd\n", write(fd, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_write(fd, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	// 0 : Write on file
	errno = 0;
	printf("|ret : %zd\n", write(fd, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_write(fd, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

//	str = "abc"
	printf("	str = abc\n\n");
	errno = 0;
	printf("|ret : %zd\n", write(1, &str, 1));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_write(1, &str, 1));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", write(1, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_write(1, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", write(1, &str, 4));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_write(1, &str, 4));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", write(1, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_write(1, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", write(4, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_write(4, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", write(1, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_write(1, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

//	str2 = NULL
	printf("	str2 = NULL\n\n");
	errno = 0;
	printf("|ret : %zd\n", write(1, &str2, 0));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_write(1, &str2, 0));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", write(1, &str2, 3));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_write(1, &str2, 3));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", write(1, &str2, 4));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_write(1, &str2, 4));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", write(1, &str2, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_write(1, &str2, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", write(4, &str2, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_write(4, &str2, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", write(1, &str2, -1));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_write(1, &str2, -1));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

//	str3 = ""
	printf("	str3 = \"\"\n\n");
	errno = 0;
	printf("|ret : %zd\n", write(1, &str3, 0));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_write(1, &str3, 0));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", write(1, &str3, 3));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_write(1, &str3, 3));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", write(1, &str3, 4));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	// 14 : Bad address
	errno = 0;
	printf("|ret : %zd\n", write(fd, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_write(fd, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	printf("|ret : %zd\n", ft_write(1, &str3, 4));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", write(1, &str3, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_write(1, &str3, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", write(4, &str3, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_write(4, &str3, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", write(1, &str3, -1));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_write(1, &str3, -1));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");
	return (0);
}
