#include "cat.h"

void ft_putchar(char c)
{
    write (1, &c, 1);
}
void ft_putstr(char *str)
{
    while (*str)
    {
        write (1, str++, 1);
    }
}
int ft_strerror(int buflen, char *file)
{
    if (buflen != 0)
    {
        ft_putstr(file);
        ft_putstr(": ");
        if (buflen == errno)
            ft_putstr("No such file or directory\n");
    }
    return (0);
}
int ft_cat(char *file)
{
    int fd;
    int store;
    char byte;

    if ((fd = open(file, O_RDONLY)) == -1)
        return (errno);
    while ((store = read(fd, &byte, 1)))
    {
        ft_putchar(byte);
    }
    close (fd);
    ft_putstr("\n");
    return (0);
}
int main(int argc, char **argv)
{
    int i;
    i = 1;
    if (argc < 2)
        ft_putstr("Missing file arguments\n");
    if (argc >= 2)
    {
        while (argv[i])
        {
            // it returns string showing the number of errors
            ft_strerror(ft_cat(argv[i]), argv[i]);
            i++;
        }
    }
    return (0);
}