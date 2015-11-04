#include "main.h"

extern int		ft_isalnum(int c);

int		test_isalnum(void)
{
	for (unsigned char c = 0; c < UCHAR_MAX; c++)
	{
		if (isalnum((int)c) != ft_isalnum((int)c))
		{
			printf("wrong number : %c\n", c);
			return (1);
		}
	}
	return (0);
}
