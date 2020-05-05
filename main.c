
#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

void	check_strlen(void)
{
	char	*str;
	int	len;
	str = NULL;
	//len = strlen(str);
	len = ft_strlen(str);
	
	printf("len : %zu\n", ft_strlen(""));
	printf("len : %zu\n", strlen(""));
	printf("len : %zu\n", ft_strlen("A"));
	printf("len : %zu\n", strlen("A"));
	printf("len : %zu\n", ft_strlen("ABCD"));
	printf("len : %zu\n", strlen("ABCD"));
	printf("len : %zu\n", ft_strlen("0123456789012345678901234567890123456789012345678901234567890123456789"));
	printf("len : %zu\n", strlen("0123456789012345678901234567890123456789012345678901234567890123456789"));
}

void	check_strcpy(void)
{
	char	buf[12] = {0};
	char	buff[12] = {0};

	printf("\n----------------------------------\n");
	printf("cpy : %s\n", strcpy(buf, ""));
	printf("fcpy : %s\n", ft_strcpy(buff, ""));
	printf("cpy : %s\n", strcpy(buf, "abc"));
	printf("fcpy : %s\n", ft_strcpy(buff, "abc"));
	printf("cpy : %s\n", strcpy(buf, "d\0ef"));
	printf("fcpy : %s\n", ft_strcpy(buff, "d\0ef"));
	printf("cpy : SEGMENTATION FAULT\n");
	printf("fcpy : %s\n", ft_strcpy(buff, NULL));
	printf("\n");
}

void	check_strcmp(void)
{
	printf("\n----------------------------------\n");

	printf("cmp : %i\n", strcmp("zab", ""));
	printf("fcmp : %i\n", ft_strcmp("zab", ""));
	printf("\n");
	printf("cmp : %i\n", strcmp("zab\0a", "zab\0b"));
	printf("fcmp : %i\n", ft_strcmp("zab\0a", "zab\0b"));
	printf("\n");
	printf("cmp : %i\n", strcmp("abcdef", "abccef"));
	printf("fcmp : %i\n", ft_strcmp("abcdef", "abccef"));
	printf("\n");
	printf("cmp : %i\n", strcmp("abc", "abcc"));
	printf("fcmp : %i\n", ft_strcmp("abc", "abcc"));
	printf("\n");
	printf("cmp : %i\n", strcmp("abcc", "abc"));
	printf("fcmp : %i\n", ft_strcmp("abcc", "abc"));
	printf("\n");
	printf("cmp : %i\n", strcmp("abcc", "abc\0"));
	printf("fcmp : %i\n", ft_strcmp("abcc", "abc\0"));
	printf("\n");
	printf("cmp : %i\n", strcmp("abc", "abc\0e"));
	printf("fcmp : %i\n", ft_strcmp("abc", "abc\0e"));
	printf("\n");
	printf("cmp : %i\n", strcmp("", ""));
	printf("fcmp : %i\n", ft_strcmp("", ""));
	printf("\n");
	printf("cmp : %i\n", strcmp("\x01", "\x01"));
	printf("fcmp : %i\n", ft_strcmp("\x01", "\x01"));
	printf("\n");
	printf("cmp : %i\n", strcmp("\x01\x02", "\x01\x02"));
	printf("fcmp : %i\n", ft_strcmp("\x01\x02", "\x01\x02"));
	printf("\n");
	printf("cmp : %i\n", strcmp("\x01\x01", "\x01\x01"));
	printf("fcmp : %i\n", ft_strcmp("\x01\x01", "\x01\x01"));
	printf("\n");
	printf("cmp : %i\n", strcmp("\x01\x01", "\x01\x02"));
	printf("fcmp : %i\n", ft_strcmp("\x01\x01", "\x01\x02"));
	printf("\n");
	printf("cmp : SEGMENTATION FAULT\n");
	printf("fcmp : %i\n", ft_strcmp("", NULL));
	printf("\n");
	printf("cmp : SEGMENTATION FAULT\n");
	printf("fcmp : %i\n", ft_strcmp(NULL, NULL));
	printf("\n");
	printf("cmp : SEGMENTATION FAULT\n");
	printf("fcmp : %i\n", ft_strcmp(NULL, ""));
	printf("\n");
	
}

void	check_write(void)
{
	int	fd;
	int	fd2;
	char	*str = NULL;

	fd = open("./test2", O_RDWR);
	fd2 = open("./test", O_RDONLY);
	
	printf("\n----------------------------------\n");
	str = "abc";
	// 9 : Bad file descriptor (RDONLY)
	errno = 0;
	printf("|wr : %zd\n", write(fd2, &str, 2));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|wr : %zd\n", ft_write(fd2, &str, 2));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	// 9 : Bad file descriptor (RANDOM)
	errno = 0;
	printf("|wr : %zd\n", write(4, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|wr : %zd\n", ft_write(4, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	// 14 : Bad address
	errno = 0;
	printf("|wr : %zd\n", write(fd, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|wr : %zd\n", ft_write(fd, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	// 0 : Write on file
	errno = 0;
	printf("|wr : %zd\n", write(fd, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|wr : %zd\n", ft_write(fd, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	printf(".............str = \"abc\"\n\n");
	errno = 0;
	printf("|wr : %zd\n", write(1, &str, 1));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|wr : %zd\n", ft_write(1, &str, 1));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|wr : %zd\n", write(1, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|wr : %zd\n", ft_write(1, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|wr : %zd\n", write(1, &str, 4));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|wr : %zd\n", ft_write(1, &str, 4));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|wr : %zd\n", write(1, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|wr : %zd\n", ft_write(1, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|wr : %zd\n", write(4, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|wr : %zd\n", ft_write(4, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|wr : %zd\n", write(1, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|wr : %zd\n", ft_write(1, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	str = NULL;
	printf(".............str = NULL\n\n");
	errno = 0;
	printf("|wr : %zd\n", write(1, &str, 0));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|wr : %zd\n", ft_write(1, &str, 0));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|wr : %zd\n", write(1, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|wr : %zd\n", ft_write(1, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|wr : %zd\n", write(1, &str, 4));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|wr : %zd\n", ft_write(1, &str, 4));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|wr : %zd\n", write(1, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|wr : %zd\n", ft_write(1, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|wr : %zd\n", write(4, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|wr : %zd\n", ft_write(4, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|wr : %zd\n", write(1, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|wr : %zd\n", ft_write(1, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	str = "";
	printf(".............str = \"\"\n\n");
	errno = 0;
	printf("|wr : %zd\n", write(1, &str, 0));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|wr : %zd\n", ft_write(1, &str, 0));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|wr : %zd\n", write(1, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|wr : %zd\n", ft_write(1, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|wr : %zd\n", write(1, &str, 4));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|wr : %zd\n", ft_write(1, &str, 4));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|wr : %zd\n", write(fd, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|wr : %zd\n", ft_write(fd, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|wr : %zd\n", write(1, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|wr : %zd\n", ft_write(1, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|wr : %zd\n", write(4, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|wr : %zd\n", ft_write(4, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|wr : %zd\n", write(1, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|wr : %zd\n", ft_write(1, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");
}

void	check_read(void)
{
	int	fd;
	char	*str = NULL;

	fd = open("./Makefile", O_RDONLY);

	// 0 : Success
	printf("\n----------------------------------\n\n");
	str = "abc";
	errno = 0;
	printf("|rd : %zd\n", read(fd, &str, 2));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|rd : %zd\n", ft_read(fd, &str, 2));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	// 9 : Bad file descriptor
	errno = 0;
	printf("|rd : %zd\n", read(410, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|rd : %zd\n", ft_read(410, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	// 14 : Bad address
	errno = 0;
	printf("|rd : %zd\n", read(fd, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|rd : %zd\n", ft_read(fd, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

/*
	// Read stdin
	errno = 0;
	printf("|rd : %zd\n", read(1, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|rd : %zd\n", ft_read(1, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");
*/

	fd = open("./Makefile", O_RDONLY);
	printf(".............str = abc\n\n");
	errno = 0;
	printf("|rd : %zd\n", read(fd, &str, 1));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|rd : %zd\n", ft_read(fd, &str, 1));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|rd : %zd\n", read(fd, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|rd : %zd\n", ft_read(fd, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|rd : %zd\n", read(fd, &str, 4));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|rd : %zd\n", ft_read(fd, &str, 4));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|rd : %zd\n", read(fd, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|rd : %zd\n", ft_read(fd, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|rd : %zd\n", read(410, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|rd : %zd\n", ft_read(410, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|rd : %zd\n", read(fd, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|rd : %zd\n", ft_read(fd, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	fd = open("./Makefile", O_RDONLY);
	str = NULL;
	printf(".............str = NULL\n\n");
	errno = 0;
	printf("|rd : %zd\n", read(fd, &str, 0));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|rd : %zd\n", ft_read(fd, &str, 0));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|rd : %zd\n", read(fd, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|rd : %zd\n", ft_read(fd, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|rd : %zd\n", read(fd, &str, 4));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|rd : %zd\n", ft_read(fd, &str, 4));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|rd : %zd\n", read(fd, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|rd : %zd\n", ft_read(fd, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|rd : %zd\n", read(410, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|rd : %zd\n", ft_read(410, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|rd : %zd\n", read(fd, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|rd : %zd\n", ft_read(fd, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	fd = open("./Makefile", O_RDONLY);
	str = "";
	printf(".............str = \"\"\n\n");
	errno = 0;
	printf("|rd : %zd\n", read(fd, &str, 0));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|rd : %zd\n", ft_read(fd, &str, 0));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|rd : %zd\n", read(fd, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|rd : %zd\n", ft_read(fd, &str, 3));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|rd : %zd\n", read(fd, &str, 4));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|rd : %zd\n", ft_read(fd, &str, 4));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|rd : %zd\n", read(fd, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|rd : %zd\n", ft_read(fd, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|rd : %zd\n", read(410, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|rd : %zd\n", ft_read(410, &str, 5));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("|rd : %zd\n", read(fd, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("|rd : %zd\n", ft_read(fd, &str, -1));
	printf("%i : %s\n", errno, strerror(errno));
	printf("\n");
	
}

void	check_strdup(void)
{
	char	*tmp = NULL;
	char	*tmp2 = NULL;

	printf("\n----------------------------------\n");
	tmp = "abc";
	printf("dup : %s\n", strdup(tmp));
	printf("fdup : %s\n", tmp2 = ft_strdup(tmp));
	printf("fdup : %s\n", ft_strdup(tmp2));
	printf("\n");
	tmp = "";
	printf("dup : %s\n", strdup(tmp));
	printf("fdup : %s\n", tmp2 = ft_strdup(tmp));
	printf("fdup : %s\n", ft_strdup(tmp2));
	printf("\n");
	tmp = NULL;
	printf("dup : SEGMENTATION FAULT\n");
	printf("fdup : %s\n", tmp2 = ft_strdup(tmp));
	printf("fdup : %s\n", ft_strdup(tmp2));
	printf("\n");
}

int	main(void)
{
	check_strlen();
	check_strcpy();
	check_strcmp();
	check_write();
	check_read();
	check_strdup();
	return (0);
}
