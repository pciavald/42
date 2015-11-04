#include "main.h"

extern void		ft_bzero(void *s, size_t n);

int		test_bzero(void)
{
	char		str[] = "coucou\n";
	int			size = strlen(str);
	char		str0[] = "coucou\n";

	ft_bzero(str, size);
	if (strncmp(str, "\0\0\0\0\0\0\0", size))
		return (1);
	ft_bzero(str0, 0);
	if (strncmp(str0, "coucou\n", size))
		return (2);
	ft_bzero(str0, 3);
	if (strncmp(str0, "\0\0\0cou\n", size))
		return (3);
	return (0);
}
