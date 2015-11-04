#include "main.h"

extern int		ft_tolower(int c);

int		test_tolower(void)
{
	for (unsigned char c = 0; c < UCHAR_MAX; c++)
	{
		if (tolower((int)c) != ft_tolower((int)c))
		{
			printf("wrong char : %c\n", c);
			return (1);
		}
	}
	return (0);
}
