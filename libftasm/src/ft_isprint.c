#include "main.h"

extern int		ft_isprint(int c);

int		test_isprint(void)
{
	for (unsigned char c = 0; c < UCHAR_MAX; c++)
	{
		if (isprint((int)c) != ft_isprint((int)c))
		{
			printf("wrong number : %c\n", c);
			return (1);
		}
	}
	return (0);
}
