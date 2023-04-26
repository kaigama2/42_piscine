#include "../../includes/piscine.h"
// a function that converts the initial
// portion of the string pointed by str to int representation.

int ft_strlen(char *base)
{
	int i;
	i = 0;
	while (base[i])
		i++;
	return (i);
}
int ft_no_search(char c, char *base)
{
	int i;
	i = 0;
	while (base[i] != '\0')
	{
		// character found in string
		if (base[i] == c)
		// returning the number of characters with null byte('\0')
        // allocating + 1 end position for '\0'
			return (i + 1);
		i++;
	}
	return (0);
}
int ft_printout(char *str, char *base, int i, int size)
{
	int temp;
	int len;
	int result;

	temp = 1;
	len = ft_strlen(base);
	while (size >= i)
	{
		result = result + (ft_no_search(str[size], base) - 1) * temp;
		temp = temp * len;
		size--;
	}
	return (result);
}
int ft_base_rule(char *base)
{
	int i;
	int x;
	i = 0;
	x = 1;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if ((base[i] == '-' || base[i] == '+') || (base[i] >= 0 && base[i] <= 32))
			return (0);
		while (base[x])
		{
			if (base[i] == base[x])
				return (0);
			x++;
		}
		i++;
	}
	return (1);
}
int ft_atoi_base(char *str, char *base)
{
	int i;
	int neg;
	int temp;

	i = 0;
	neg = 1;
	if (ft_base_rule(base))
	{
		while (str[i] == ' ' || str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				neg *= -1;
			i++;
		}
		temp = i;
		while (ft_no_search(str[i], base) > 0)
			i++;
		i--;
	}
	return (ft_printout(str, base, temp, i) * neg);
}
int main()
{
	char str[] = " ---+--+1234ab567";
	char radix[] = "0123456789";
	printf("%d\n", ft_atoi_base(str, radix));
	return (0);
}