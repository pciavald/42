#include "main.h"

extern size_t	ft_strlen(const char * s);

int test_strlen(void)
{
	if (ft_strlen("hello, friend\n") != 14)
		return (1);
	if (ft_strlen("") != 0)
		return (2);
	if (ft_strlen(NULL) != 0)
		return (3);
	return (0);
}
