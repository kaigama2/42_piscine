#include "../../includes/piscine.h"

void ft_putchar(char c)
{
// ** &c means take c to a memory address void * while (*) with any variable
// ** is called the memory location or dereference pointer to store values
    write (1, &c, 1);
}

int main()
{
    ft_putchar('k');
    ft_putchar('\n');
    return (0);
}
