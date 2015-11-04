#include "main.h"

extern int		ft_isascii(int c);

int		test_isascii(void)
{
	for (unsigned char c = 0; c < UCHAR_MAX; c++)
	{
		if (isascii((int)c) != ft_isascii((int)c))
		{
			printf("wrong number : %c\n", c);
			return (1);
		}
	}
	return (0);
}
