/*
 * A small program that illustrates how to call the maxofthree function we wrote in
 * assembly language.
 */

#include "libasm.h"
#include <stdio.h>

int main(void) {
    printf("len : %zu\n", ft_strlen(""));
    printf("len : %zu\n", ft_strlen("A"));
    printf("len : %zu\n", ft_strlen("ABCD"));
    printf("len : %zu\n", ft_strlen("0123456789012345678901234567890123456789012345678901234567890123456789"));
    return 0;
}
