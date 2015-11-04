#include "main.h"

extern int		ft_isalpha(int c);

int		test_isalpha(void)
{
	for (unsigned char c = 0; c < UCHAR_MAX; c++)
	{
		if (isalpha((int)c) != ft_isalpha((int)c))
		{
			printf("wrong number : %c\n", c);
			return (1);
		}
	}
	return (0);
}
