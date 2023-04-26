#include "../includes/ft_lib.h"
#include "refer_function.c"

void ft_display_file(int argc, char **argv)
{
	int char_count;
	char buffer;
	int fd;
	if (argc == 1)
	{
		write (1, "File name missing.\n", 20);
	}
	else if (argc > 2)
	{
		write (1, "Too many arguments.\n", 21);
	}
	else if (argc == 2)
	{
		if (ft_strcmp(argv[1], ".") == 0 || ft_strcmp(argv[1], "..") == 0 || ft_strcmp(argv[1], "./") == 0
		|| ft_strcmp(argv[1], "../")== 0)
		{
			ft_putstr("./: is a directory.\n");
		}
		// return -1 if the given file is not readable
		else if ((fd = open(argv[1], O_RDONLY)) == -1)
			ft_putstr("Cannot read file.\n");
		else
		{
			while ((char_count = read(fd, &buffer, 1)))
			{
					ft_putchar(buffer);
			}
			if (close(fd) == -1)
				ft_putstr("fix error Message during closing the text file.\n");
			else
			ft_putchar('\n');
		}
	}
}