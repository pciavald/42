#include "main.h"

extern int		ft_toupper(int c);

int		test_toupper(void)
{
	for (unsigned char c = 0; c < UCHAR_MAX; c++)
	{
		if (toupper((int)c) != ft_toupper((int)c))
		{
			printf("wrong char : %c\n", c);
			return (1);
		}
	}
	return (0);
}
