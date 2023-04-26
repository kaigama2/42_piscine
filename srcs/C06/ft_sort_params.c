#include "../../includes/piscine.h"

void ft_putchar(char c)
{
	write (1, &c, 1);
}
void ft_swapped(char *a, char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1[i] && s2[i]) && s1[i] == s2[i])
	{
		i++;
	}
	// note here (char c) comparing for equality in int or char
	return (s1[i] - s2[i]);
}

void ft_printout(char **str)
{
	int i;
	int x;
// passing the first string to be printed
// if we wish to print another increment the loop by 2
	i = 1;
	while (str[i])
	{
// check the char c or unsigned char one after the other
// in the string given to the function ft_putchar to be printed
		x = 0;
		while (str[i][x])
		{
			ft_putchar(str[i][x]);
			ft_putchar(' ');
			x++;
		}
		i++;
	}
}
int main(int argc, char **argv)
{
	int i;
	int x;

// passing in the first string after d program name into the function
// ft_strcmp
	i = 1;
	while (i < argc)
	{
// passing in the first string after d program name into the function
// ft_strcmp
		x = 1;
		while (x < argc)
		{
			if (ft_strcmp(argv[i], argv[x]) < 0)
			{
				ft_swapped(argv[i], argv[x]);
			}
			x++;
		}
		i++;
	}
	ft_printout(argv);
	ft_putchar('\n');
	return (0);
}