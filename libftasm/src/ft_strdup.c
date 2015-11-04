#include "main.h"

extern char *	ft_strdup(const char * s1);

int		test_strdup(void)
{
	char	s1[] = {"hello, friend\n"};
	char *	s2;

	s2 = ft_strdup(s1);
	if (s1 == s2)
		return (1);
	if (s2 == NULL)
		return (2);
	if (strcmp(s1, s2))
		return (3);
	return (0);
}
