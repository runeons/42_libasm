
#include <stddef.h>
#include <unistd.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_bzero(char *str, int n);
int	ft_strcmp(const char *s1, const char *s2);
ssize_t	write(int fd, const void *buf, size_t count);
ssize_t	read(int fd, void *buf, size_t count);
char	*strdup(const char *s); // malloc autorisé
