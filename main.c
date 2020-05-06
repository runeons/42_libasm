/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 19:30:12 by tsantoni          #+#    #+#             */
/*   Updated: 2020/05/06 09:43:41 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

void	check_strlen(void)
{
	char	*str;
	str = NULL;
	
	printf(GREEN "ft_strlen :"RESET"\n");
	printf("	len : %zu\n", strlen(""));
	printf("	len : %zu\n", ft_strlen(""));
	printf("	len : %zu\n", strlen("A"));
	printf("	len : %zu\n", ft_strlen("A"));
	printf("	len : %zu\n", strlen("ABCD"));
	printf("	len : %zu\n", ft_strlen("ABCD"));
	printf("	len : %zu\n", strlen("0123456789012345678901234567890123456789012345678901234567890123456789"));
	printf("	len : %zu\n", ft_strlen("0123456789012345678901234567890123456789012345678901234567890123456789"));
	printf("	len : SEGMENTATION FAULT\n");
	printf("	len : %zu\n", ft_strlen(str));
}

void	check_strcpy(void)
{
	char	buf[12] = {0};
	char	buff[12] = {0};

	printf("----------------------------------\n");
	printf(GREEN "ft_strcpy :"RESET"\n");
	printf("	 cpy: %s\n", strcpy(buf, ""));
	printf("	 fcpy: %s\n", ft_strcpy(buff, ""));
	printf("	 cpy: %s\n", strcpy(buf, "abc"));
	printf("	 fcpy: %s\n", ft_strcpy(buff, "abc"));
	printf("	 cpy: %s\n", strcpy(buf, "d\0ef"));
	printf("	 fcpy: %s\n", ft_strcpy(buff, "d\0ef"));
	printf("	 cpy: SEGMENTATION FAULT\n");
	printf("	 fcpy: %s\n", ft_strcpy(buff, NULL));
	printf("\n");
}

void	check_strcmp(void)
{
	printf("----------------------------------\n");
	printf(GREEN "ft_strcmp :"RESET"\n");
	printf("	cmp : %i\n", strcmp("zab", ""));
	printf("	fcmp : %i\n", ft_strcmp("zab", ""));
	printf("\n");
	printf("	cmp : %i\n", strcmp("zab\0a", "zab\0b"));
	printf("	fcmp : %i\n", ft_strcmp("zab\0a", "zab\0b"));
	printf("\n");
	printf("	cmp : %i\n", strcmp("abcdef", "abccef"));
	printf("	fcmp : %i\n", ft_strcmp("abcdef", "abccef"));
	printf("\n");
	printf("	cmp : %i\n", strcmp("abc", "abcc"));
	printf("	fcmp : %i\n", ft_strcmp("abc", "abcc"));
	printf("\n");
	printf("	cmp : %i\n", strcmp("abcc", "abc"));
	printf("	fcmp : %i\n", ft_strcmp("abcc", "abc"));
	printf("\n");
	printf("	cmp : %i\n", strcmp("abcc", "abc\0"));
	printf("	fcmp : %i\n", ft_strcmp("abcc", "abc\0"));
	printf("\n");
	printf("	cmp : %i\n", strcmp("abc", "abc\0e"));
	printf("	fcmp : %i\n", ft_strcmp("abc", "abc\0e"));
	printf("\n");
	printf("	cmp : %i\n", strcmp("", ""));
	printf("	fcmp : %i\n", ft_strcmp("", ""));
	printf("\n");
	printf("	cmp : %i\n", strcmp("\x01", "\x01"));
	printf("	fcmp : %i\n", ft_strcmp("\x01", "\x01"));
	printf("\n");
	printf("	cmp : %i\n", strcmp("\x01\x02", "\x01\x02"));
	printf("	fcmp : %i\n", ft_strcmp("\x01\x02", "\x01\x02"));
	printf("\n");
	printf("	cmp : %i\n", strcmp("\x01\x01", "\x01\x01"));
	printf("	fcmp : %i\n", ft_strcmp("\x01\x01", "\x01\x01"));
	printf("\n");
	printf("	cmp : %i\n", strcmp("\x01\x01", "\x01\x02"));
	printf("	fcmp : %i\n", ft_strcmp("\x01\x01", "\x01\x02"));
	printf("\n");
	printf("	cmp : SEGMENTATION FAULT\n");
	printf("	fcmp : %i\n", ft_strcmp("", NULL));
	printf("\n");
	printf("	cmp : SEGMENTATION FAULT\n");
	printf("	fcmp : %i\n", ft_strcmp(NULL, NULL));
	printf("\n");
	printf("	cmp : SEGMENTATION FAULT\n");
	printf("	fcmp : %i\n", ft_strcmp(NULL, ""));
	printf("\n");
	
}

void	check_write(void)
{
	int	fd;
	int	fd2;
	char	*str = NULL;
	char	buf[11] = "abcdefghij";

	fd = open("./test2", O_RDWR);
	fd2 = open("./test", O_RDONLY);
	
	printf("----------------------------------\n");
	printf(GREEN"ft_write :"RESET"\n");
	printf(YELLOW"	str = \"abc\""RESET"\n");
	str = "abc";
	// 9 : Bad file descriptor (RDONLY)
	errno = 0;
	printf("		|wr : %zd\n", write(fd2, str, 2));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(fd2, str, 2));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	// 9 : Bad file descriptor (RANDOM)
	errno = 0;
	printf("		|wr : %zd\n", write(4, str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(4, str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	// 14 : Bad address
	errno = 0;
	printf("		|wr : %zd\n", write(fd, str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(fd, str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	// 0 : Write on file
	errno = 0;
	printf("		|wr : %zd\n", write(fd, str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(fd, str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(4, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(4, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	str = NULL;
	printf(YELLOW"	str = NULL"RESET"\n");
	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 0));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 0));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(4, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(4, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	str = "";
	printf(YELLOW"	str = \"\""RESET"\n");
	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 0));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 0));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(fd, str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(fd, str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(4, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(4, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, "bonjour", 7));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, "bonjour", 7));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(98123, "", 1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(98123, "", 1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(42, NULL, 7));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(42, NULL, 7));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, &buf, 7));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, &buf, 7));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, buf, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, buf, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");
}

void	check_read(void)
{
	int	fd;
	char	*str = NULL;

	fd = open("./Makefile", O_RDONLY);

	// 0 : Success
	printf("----------------------------------\n\n");
	printf(GREEN"ft_read :"RESET"\n");
	printf(YELLOW"	str = \"abc\""RESET"\n");
	str = "abc";
	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 2));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 2));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	// 9 : Bad file descriptor
	errno = 0;
	printf("		|rd : %zd\n", read(410, &str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(410, &str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	// 14 : Bad address
	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");


	// Read stdin
	errno = 0;
	printf("		|rd : %zd\n", read(1, &str, 25));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(1, &str, 25));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");


	fd = open("./Makefile", O_RDONLY);
	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(410, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(410, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	fd = open("./Makefile", O_RDONLY);
	str = NULL;
	printf(YELLOW"	str = NULL"RESET"\n");
	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 0));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 0));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(410, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(410, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	fd = open("./Makefile", O_RDONLY);
	str = "";
	printf(YELLOW"	str = \"\""RESET"\n");
	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 0));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 0));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(410, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(410, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");
	
	char	buf[32];
	errno = 0;
	printf("		|rd : %zd\n", read(98123, buf, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(98123, buf, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, buf, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, buf, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(42, NULL, 7));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(42, NULL, 7));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");
}

void	check_strdup(void)
{
	char	*tmp = NULL;
	char	*tmp2 = NULL;

	printf("----------------------------------\n");
	printf(GREEN"ft_strdup :"RESET"\n");
	tmp = "abc";
	printf("	dup : %s\n", strdup(tmp));
	printf("	fdup : %s\n", tmp2 = ft_strdup(tmp));
	printf("	fdup : %s\n", ft_strdup(tmp2));
	printf("\n");
	tmp = "abcdefghijklmnopqstuvwxyz";
	printf("	dup : %s\n", strdup(tmp));
	printf("	fdup : %s\n", tmp2 = ft_strdup(tmp));
	printf("	fdup : %s\n", ft_strdup(tmp2));
	printf("\n");
	tmp = "";
	printf("	dup : %s\n", strdup(tmp));
	printf("	fdup : %s\n", tmp2 = ft_strdup(tmp));
	printf("	fdup : %s\n", ft_strdup(tmp2));
	printf("\n");
	tmp = NULL;
	printf("	dup : SEGMENTATION FAULT\n");
	printf("	fdup : %s\n", tmp2 = ft_strdup(tmp));
	printf("	fdup : %s\n", ft_strdup(tmp2));
	printf("\n");
	tmp = "\0";
	printf("	dup : %s\n", strdup(tmp));
	printf("	fdup : %s\n", tmp2 = ft_strdup(tmp));
	printf("	fdup : %s\n", ft_strdup(tmp2));
	printf("\n");
	tmp = "abcd\0fgh";
	printf("	dup : %s\n", strdup(tmp));
	printf("	fdup : %s\n", tmp2 = ft_strdup(tmp));
	printf("	fdup : %s\n", ft_strdup(tmp2));
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
