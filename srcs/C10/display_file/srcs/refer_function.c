#include "../includes/ft_lib.h"

void ft_putchar(char c)
{
	write (1, &c, 1);
}

void ft_putstr(char *str)
{
	while (*str)
		write (1, str++, 1);
}

int ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
