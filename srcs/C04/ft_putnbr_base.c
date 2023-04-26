#include "../../includes/piscine.h"

// Create a function that displays a number in a base system in the terminal.
void ft_putchar(char c)
{
	write (1, &c, 1);
}
int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int ft_invalid_sign(char *str)
{
	int i;
	int x;

// i = 0 is a computer understanding way of counting numbers for string
// while x = 1 is the users/programmers way of counting numbers for string
	i = 0;
	x = 1;
	// do the radix contain 1 or zero string
	if (str[0] == '\0' || str[1] == '\0')
		return (0);
	while (str[i])
	{
		// do the radix contain - or + or printable characters
		if (str[i] == '-' || str[i] == '+' || (str[i] >= 0 && str[i] <= 32))
			return (0);

		while (str[x])
		{
			// if the string contain the same character twice
			if (str[i] == str[x])
				return (0);
			x++;
		}
		i++;
	}
	// return true for equal numbers of string
	return (1);
}
void ft_putnbr_base(int nbr, char *str)
{
	int i;
	char array[16];
	int len;

	i = 0;
	if (ft_invalid_sign(str))
	{
		if (nbr < 0)
		{
			nbr *= -1;
			write (1, "-", 1);
		}
		len = ft_strlen(str);
		while (nbr)
		{
			array[i] = nbr % len;
			nbr = nbr / len;
			i++;
		}
		// printing the value from front to the back thereby decrementing
		// i
		while (--i >= 0)
			ft_putchar(str[array[i]]);
	}
}
int main()
{
	char radix[] = "PONEYVIF";
	int nbr;
	nbr = -2;
	ft_putnbr_base(nbr, radix);
	ft_putchar('\n');
	return (0);
}