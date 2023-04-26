#include <stdio.h>

#include "../includes/ft_tail.h"
#include "../includes/ft_args_parser.h"
#include "ft_console_io.c"
#include "ft_atoi.c"
#include "ft_is.c"
#include "ft_strncpy.c"
#include "ft_tail_utils.c"
#include "ft_tail_out.c"
#include "ft_tail.c"
#include "ft_args_parser.c"

int		main(int argc, char **argv)
{
	if (!parse_args(argv, argc))
		return (1);
	return (0);
}