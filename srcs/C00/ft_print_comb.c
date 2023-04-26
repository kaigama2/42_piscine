#include <piscine.h>

void ft_putchar(char c)
{
    write (1, &c, 1);
}

void ft_punctuation(void)
{
    ft_putchar(',');
    ft_putchar(' ');
}
void ft_print_comb(void)
{
    int number[3];
    number[0] = '0';
    while (number[0] <= '9')
    {
        number[1] = '0';
        while (number[1] <= '9')
        {
            number[2] = '0';
            while (number[2] <= '9')
            {
                if (number[0] < number[1] && number[1] < number[2])
                {
                    ft_putchar(number[0]);
                    ft_putchar(number[1]);
                    ft_putchar(number[2]);
                    if (!(number[0] == '1' && number[1] == '2' && number[2] == '3'))
                        ft_punctuation();
                }
                number[2]++;
            }
            number[1]++;
        }
        number[0]++;
    }
}
int main()
{
    ft_print_comb();
    return (0);
}
// =============================================================================================================================================
// void ft_putchar(char c)
// {
//     write (1, &c, 1);
// }

// void ft_printout(char a, char b, char c, bool last)
// {
//     ft_putchar(a);
//     ft_putchar(b);
//     ft_putchar(c);
//     if (last)
//     {
//         ft_putchar(',');
//         ft_putchar(' ');
//     }
// }
// void ft_print_comb(void)
// {
//     char a;
//     char b;
//     char c;
//     bool ap;
//     a = '0';
//     while (a <= '7')
//     {
//         b = a + 1;
//         while (b <= '8')
//         {
//             c = b + 1;
//             while (c <= '9')
//             {
//                 // evaluate ap statement as true
//                 ap = !(a == '7' && b == '8' && c == '9');
//                 ft_printout(a, b, c, ap);
//                 c++;
//             }
//             b++;
//         }
//         a++;
//     }
// }
// int main()
// {
//     ft_print_comb();
//     return (0);
// }