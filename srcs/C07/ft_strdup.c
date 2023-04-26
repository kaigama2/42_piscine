#include "../../includes/piscine.h"

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
		write (1, str++, 1);
}
char *ft_strdup(char *src)
{
	int i;
	char *p;

	i = 0;
	while (src[i])
		i++;
	if (!(p = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
int main(int argc, char **argv)
{
	char *p;
	int i;
// number of string after program name passed 
// into the function ft_strdup to be printed
	i = 1;
	while (i < argc)
	{
		p = ft_strdup(argv[i]);
		ft_putstr(p);
		ft_putstr("\n");
		free(p);
		i++;
	}
	return (0);
}