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
	printf("\n----------------------------------\n\n");

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
	printf("cmp : %i\n", strcmp("", ""));
	printf("fcmp : %i\n", ft_strcmp("", ""));
	printf("\n");

	return (0);
}
