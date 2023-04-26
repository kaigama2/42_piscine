#include "../../includes/piscine.h"

void ft_putchar(char c)
{
	write (1, &c, 1);
}
void ft_putstr(char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
char *ft_strjoin(int size, char **strs, char *sep)
{
	int i;
	int x;
	int c;
	char *dest;

	i = 0;
	c = 0;
	// passing the first number of the string to dest
	if (!(dest = (char *)malloc(sizeof(strs))))
		return (NULL);
	while (i < size)
	{
		x = 0;
		while (strs[i][x] != '\0')
		{
			dest[c] = strs[i][x];
			c++;
			x++;
		}
		x = 0;
		while (sep[x])
		{
			dest[c] = sep[x];
			c++;
			x++;
		}
		i++;
	}
	dest[c] = '\0';
	return (dest);
}
int main()
{
	char *pointer;
	
	char *strs[5];
	strs[0] = "kaigama";
	strs[1] = "is";
	strs[2] = "a";
	strs[3] = "good";
	strs[4] = "boy";
	pointer = ft_strjoin(5, strs, "-");
	ft_putstr(pointer);
	// output the string and free the address of the pointer
	free(pointer);
	ft_putstr("\n");
	return (0);
}