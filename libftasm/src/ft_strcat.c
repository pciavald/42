#include "main.h"

extern char *	ft_strcat(char * restrict s1, const char * restrict s2);

int		test_strcat(void)
{
	char	str1[16] = "coucou";
	char	str2[] = " les amis\n";
	char *	ret;

	ret = ft_strcat(str1, str2);
	if (ret != str1)
		return (1);
	if (strcmp(ret, "coucou les amis\n"))
		return (2);
	return (0);
}
