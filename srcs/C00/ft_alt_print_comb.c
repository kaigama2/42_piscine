#include "../../includes/piscine.h"

void ft_putchar(char c)
{
    write (1, &c, 1);
}
void ft_printout(char a, char b, char c, bool last)
{
    ft_putchar(a);
    ft_putchar(b);
    ft_putchar(c);
    if (last)
    {
        ft_putchar(',');
        ft_putchar(' ');
    }
}
void ft_print_comb(void)
{
    // since we'd be converting to its ascii character we're using
    char a;
    char b;
    char c;
    bool last_con;
    a = '0';
    while (a <= '7')
    {
        b = a + 1;
        while (b <= '8')
        {
            c = b + 1;
            while (c <= '9')
            {
                last_con = !(a == '7' && b == '8' && c == '9');
                ft_printout(a, b, c, last_con);
                c++;
            }
            b++;
        }
        a++;
    }
}
int main()
{
    ft_print_comb();
    return (0);
}
