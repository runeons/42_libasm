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
	int	fd;

	fd = open("./test", O_RDONLY);
	
	str2 = NULL;

	printf("str : %p\n", str);
	printf("&str : %p\n", &str);
	printf("\n");

	// 0 : Success

	errno = 0;
	printf("|ret : %zd\n", read(fd, &str, 2));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str, 2));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	// 9 : Bad file descriptor
	errno = 0;
	printf("|ret : %zd\n", read(4, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(4, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	// 14 : Bad address
	errno = 0;
	printf("|ret : %zd\n", read(fd, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

//	str = "abc"
	errno = 0;
	printf("|ret : %zd\n", read(fd, &str, 1));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str, 1));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", read(fd, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str, 3));
	printf("\n");

	errno = 0;
	printf("|Wret : %zd\n", read(fd, &str, 4));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|Fret : %zd\n", ft_read(fd, &str, 4));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", read(fd, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str, 5));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", read(4, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(4, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", read(fd, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

//	str2 = NULL
	errno = 0;
	printf("|ret : %zd\n", read(fd, &str2, 0));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str2, 0));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", read(fd, &str2, 3));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str2, 3));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", read(fd, &str2, 4));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str2, 4));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", read(fd, &str2, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str2, 5));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", read(4, &str2, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(4, &str2, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", read(fd, &str2, -1));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str2, -1));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

//	str3 = ""
	return (0);
}
