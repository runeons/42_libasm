#include "libasm.h"
#include <stdio.h>
#include <string.h>

int main(void) {
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
    return 0;
}
