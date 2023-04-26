#include "../../includes/piscine.h"

void ft_putstr(char *str)
{
    int i;
    i = 0;
    while (*(str + i))
    {
        write (1, str++, 1);
    }
}
int main(int argc, char **argv)
{
    int i;
    int size;

    i = 0;
// here remove 1 position ./a.out from the passed in string into the function
// ft_putstr
    size = argc - 1;
    while (i < size)
    {
        ft_putstr(argv[size]);
        ft_putstr("\n");
        size--;
    }
}