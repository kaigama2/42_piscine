#include "../../includes/piscine.h"

int ft_strlen(int nbr)
{
	int i;

	i = 0;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}
char *ft_itoa(int nbr)
{
	int i;
	int len;
	char *dest;
	long count;
	count = nbr;

	i = 0;
	len = ft_strlen(nbr);
	if (!(dest = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	// here add null byte '\0' to the end of the array dest[len--]
	dest[len--] = '\0';
	if (nbr < 0)
	{
		dest = "Please insert a positive argument";
		return (dest);
	}
	while (nbr > 0)
	{
		dest[len] = 48 + nbr % 10;
		nbr = nbr / 10;
		i++;
		len--;
	}
	dest[len] = '\0';
	return (dest);
}
int main()
{
	printf("%s\n", ft_itoa(1234));
	return (0);
}