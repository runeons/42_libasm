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

	int	*err;
	
	err = NULL;
	printf("%p\n", err);
	err = __errno_location();
	printf("%p - %d\n", err, *err);
	*err = 14;
	perror("");
	printf("%d\n", errno);
	return (0);
}
