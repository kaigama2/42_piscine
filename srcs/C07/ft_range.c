#include "../../includes/piscine.h"

void ft_putchar(char c)
{
    write (1, &c, 1);
}
void ft_putnbr(int nbr)
{
    if (nbr < 0)
    {
        ft_putchar('-');
        nbr *= -1;
    }
    else
    {
        if (nbr > 9)
        {
            ft_putnbr(nbr / 10);
        }
        ft_putchar(48 + nbr % 10);
    }
}
void ft_printout(int *array, int range)
{
    int i;
    i = 0;
    while (i < range)
    {
        ft_putnbr(array[i++]);
        ft_putchar(' ');
    }
}
int *ft_range(int min, int max)
{
    int *array;
    int i;
    i = 0;
    if (min >= max)
        return (0);
    if (!(array = (int *)malloc(sizeof(array) * (max - min))))
        return (0);
    while (min < max)
    {
        array[i] = min;
        min++;
        i++;
    }
    return (array);
}
int main()
{
    ft_printout(ft_range(1, 20), 20 - 1);
    ft_putchar('\n');
    return (0);
}

// void ft_printout(int *tab, int size)
// {
// 	int i;
// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%d ", tab[i]);
// 		i++;
// 	}
// }
// int *ft_range(int min, int max)
// {
// 	int *tab;
// 	int i;

// 	i = 0;
// 	if (min >= max)
// 		return (NULL);
// 	if (!(tab = (int *)malloc(sizeof(int) * (max - min))))
// 		return (NULL);
// 	while (min < max)
// 	{
// 		tab[i] = min;
// 		min++;
// 		i++;
// 	}
// 	return (tab);
// }
// int main()
// {
// 	ft_printout(ft_range(1, 20), 20 - 1);
// 	// effect of ft_putchar for newline is dat a space is given
// 	// and not a newline due to incompatible int to char c = 'a'
// 	printf("\n");
// }