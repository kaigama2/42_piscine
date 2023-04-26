#include "../../includes/piscine.h"

void ft_putchar(char c)
{
    write (1, &c, 1);
}
int ft_strlen(char *str)
{
    int i;
    i = 0;
    while (str[i])
        i++;
    return (i);
}
void ft_hexaddress(void *addr)
{
    long nbr;
    char array[16];
    nbr = (long)addr;
    int i;
    
    i = 0;
    // nbr is a random number here
    while (nbr > 0)
    {
        // increase the random number (nbr) and assign it to the array
        array[i] = nbr % 16;
        // if the array is less than 10 put number else
        if (array[i] < 10)
            array[i] = array[i] + '0';
        // if the array is greater than 10 put alphabet
        else
            array[i] = array[i] + 'a' - 10;
        // reducing the random number (nbr)
        nbr = nbr / 10;
        i++;
    }
    // put 0 in the rest of the array
    while (i < 16)
        array[i++] = '0';
    // starting our printing from the back
    while (i-- >= 0)
        ft_putchar(array[i]);
}
void ft_printcontent(int ascii_no, int base)
{
    int n;
    n = ascii_no;
    // test for a negative number
    if (n < 0)
    {
        ft_putchar('-');
        n *= -1;
    }
    if (n >= base)
    {
        // reduce the number given in n
        // by dividing the given ascii number by the base
        n = n / base;
        ft_printcontent(n, base);
    }
    // increase the number given in nbr
    ascii_no = 48 + ascii_no % base;
    if (ascii_no > '9')
        ft_putchar('a' + ascii_no - '9' - 1);
    else
        ft_putchar(ascii_no);
}
void ft_hex_content(char *str, int i, int size)
{
    int n;
    int x;

    n = 0;
    x = 0;
    // check 16 character in the string array
    while (n != 16)
    {
        // check 2 character in the string array
        while (x != 2)
        {
            // check the string
            if (str[i] && i < size)
            {
                ft_printcontent(str[i], 16);
            }
            i++;
            x++;
            n++;
        }
        // initialize x to 0 after executing loop 2x times
        x = 0;
        // print space in hex content
        ft_putchar(' ');
    }
}
int ft_test_char(int c)
{
    if (!((c >= ' ' && c <= '~')))
        return (0);
    else
        return (1);
}
void ft_print_char(char *str, int i, int size)
{
    int n;
    n = 0;
    // execute the loop 16x times
    while (n != 16)
    {
        if (str[i] && i < size)
        {
            if (ft_test_char(str[i]))
            {
                ft_putchar(str[i]);
            }
            else
                ft_putchar(str[i]);
        }
        i++;
        n++;
    }
}
void *ft_print_memory(void *addr, int size)
{
    int i;
    char *str;
    str = addr;

    i = 0;
    while (i < size)
    {
        ft_hexaddress(addr + i);
        ft_putchar(':');
        ft_putchar(' ');
        ft_hex_content(str, i, size);
        ft_print_char(str, i, size);
        // add/allocate more array to the previous string array
        i += 16;
        ft_putchar('\n');
    }
    return (addr);
}
int main()
{
    char str[] = "Bonjour les aminches...c  est fou.tout.ce qu on peut faire avec...print_memory....lol.lol. \n ";
    ft_print_memory(str, ft_strlen(str));
    return (0);
}