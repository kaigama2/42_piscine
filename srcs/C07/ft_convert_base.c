#include "../../includes/piscine.h"
#include "ft_convert_base2.c"
char *ft_convert_to(char *b2, int nbr, int neg)
{
	int len;
	int total;
	int i;
	char *array;

	len = ft_strlen(b2);
	total = ft_nbr_div_count(nbr, len, neg);
	if (!(array = (char *)malloc(sizeof(b2) * (total + 1))))
		return (NULL);
	if (neg)
		array[0] = '-';
	i = neg;
	while (i < total)
	{
		array[total - (!neg) - i++] = b2[nbr % len];
		nbr = nbr / len;
	}
	array[total] = '\0';
	return (array);
}
char *ft_convert_base(char *nbr, char *b4, char *b2)
{
	int i;
	int bag;
	int content;
	int neg;
	int len;

	i = 0;
	neg = 1;
	bag = 0;
	if (!ft_invalid_base(b4) || !ft_invalid_base(b2))
		return (NULL);
	while (nbr[i] == ' ' || nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			neg *= -1;
		i++;
	}
	len = ft_strlen(b4);
	while ((content = ft_nbr_found(b4, nbr[i])) != No_match)
	{
		bag = bag * len;
		bag += content;
		i++;
	}
	neg = bag == false ? true : neg;
	return (ft_convert_to(b2, bag, (neg > 0 ? false : true)));
}
int main()
{
	printf("$%s$\n", ft_convert_base("2147483647", "0123456789", "0123456789abcdef"));
	printf("$%s$\n", ft_convert_base("----7fffffff", "0123456789abcdef", "01"));
	printf("$%s$\n", ft_convert_base("--+-1024", "0123456789", "0123456789"));
	printf("$%s$\n", ft_convert_base("-0", "0123456789", "abcdefghij"));
	return (0);
}