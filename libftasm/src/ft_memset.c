#include "main.h"

extern void *	ft_memset(void * b, int c, size_t len);

int		test_memset(void)
{
	char	buf[10] = {'\0'};
	char *	ret;
	int		i = 0;

	ret = ft_memset((void *)buf, 'A', 10);
	if (ret != buf)
		return (1);
	while (i < 10)
		if (buf[i] != 'A')
			return (2);
	ft_memset((void *)ret, 'B', 5);
	i = 0;
	while (i < 10)
		if (buf[i] != 'B' && i != 5)
			return (3);
	if (ft_memset(NULL, 0, 0) != NULL)
		return (4);
	if (ft_memset(NULL, 0, 1) != NULL)
		return (5);
	return (0);
}
