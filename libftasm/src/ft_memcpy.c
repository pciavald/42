#include "main.h"

extern void *	ft_memcpy(void * restrict dst, const void * restrict src, size_t n);

int		test_memcpy(void)
{
	char	src[] = {"world\n"};
	char	dst[] = {"hello, friend\n"};
	char *	ret;

	ret = ft_memcpy(dst + 7, src, strlen(src));
	if (ret != dst + 7)
		return (1);
	if (strcmp(dst, "hello, world\n"))
		return (2);
	return (0);
}
