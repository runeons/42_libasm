/*
 * A small program that illustrates how to call the maxofthree function we wrote in
 * assembly language.
 */

#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int	main(void) {
	char	str[3] = "abc";
	char	*str2;
	char	str3[0] = "";
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

/*
	// Read stdin
	errno = 0;
	printf("|ret : %zd\n", read(1, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(1, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");
*/

//	str = "abc"
	printf("	str = abc\n\n");
	errno = 0;
	printf("|ret : %zd\n", read(fd, &str, 1));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str, 1));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", read(fd, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", read(fd, &str, 4));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str, 4));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", read(fd, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
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
	printf("	str2 = NULL\n\n");
	errno = 0;
	printf("|ret : %zd\n", read(fd, &str2, 0));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str2, 0));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", read(fd, &str2, 3));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str2, 3));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", read(fd, &str2, 4));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str2, 4));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", read(fd, &str2, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str2, 5));
	printf("%i : %s\n", errno, strerror(errno));
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
	printf("	str3 = \"\"\n\n");
	errno = 0;
	printf("|ret : %zd\n", read(fd, &str3, 0));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str3, 0));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", read(fd, &str3, 3));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str3, 3));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", read(fd, &str3, 4));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str3, 4));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", read(fd, &str3, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str3, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", read(4, &str3, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(4, &str3, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|ret : %zd\n", read(fd, &str3, -1));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|ret : %zd\n", ft_read(fd, &str3, -1));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");
	return (0);
}
