#include "main.h"

extern int		ft_isdigit(int c);

int		test_isdigit(void)
{
	for (unsigned char c = 0; c < UCHAR_MAX; c++)
	{
		if (isdigit((int)c) != ft_isdigit((int)c))
		{
			printf("wrong number : %c", c);
			return (1);
		}
	}
	return (0);
}
