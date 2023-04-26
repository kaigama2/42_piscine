#include "../../includes/piscine.h"
#define No_match -1

int ft_strlen(char *str)
{
	int i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}
int ft_invalid_base(char *str)
{
	int i;
	int x;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '+' || str[i] == '-')
			return(0);
		x = i + 1;
		while (str[x])
		{
			if (str[i] == str[x])
				return (0);
			x++;
		}
		i++;
	}
	return (1);
}
int ft_nbr_found(char *b, char nbr)
{
	int i;
	i = 0;
	while (b[i])
	{
		if (b[i] == nbr)
			return (i);
		i++;
	}
	return (No_match);
}
int ft_nbr_div_count(int nbr, int len, int neg)
{
	int i;
	i = neg;
	while (1)
	{
		i++;
		if (nbr / len == 0)
			break;
	// here the result of our division is stored in nbr
		nbr = nbr / len;
	}
	return (i);
}