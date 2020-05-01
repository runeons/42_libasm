/*
 * A small program that illustrates how to call the maxofthree function we wrote in
 * assembly language.
 */

#include "libasm.h"
#include <stdio.h>
#include <unistd.h>

int main(void) {
	char	dest[10] = "abcdefghij";
	char	src[6] = "hello";
	int	i;

	printf("AVANT : \n");
	i = -1;
	while (dest[++i])
		write(1, &dest[i], 1);
	printf("\n");

	i = -1;
	while (src[++i])
		write(1, &src[i], 1);
	printf("\n");

	ft_strcpy(dest, src);

	printf("APRES : \n");

	i = -1;
	while (dest[++i])
		write(1, &dest[i], 1);
	printf("\n");

	i = -1;
	while (src[++i])
		write(1, &src[i], 1);
	printf("\n");
	return (0);
}
