#include "../../includes/piscine.h"
#include <unistd.h>

void ft_putchar(char c)
{
    write (1, &c, 1);
}
void	ft_putout(int *board)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int		checkdiag(int a, int b)
{
	if (a >= b)
		return (a - b);
	else
		return (b - a);
}

int		checksafe(int nqueen, int *board)
{
	int i;

	i = 0;
	while (i < nqueen)
	{
	// here if board value is equal increment the value in the
	// board and if the return value of the function is equal
	// to the math of the variable increment the value
	// in the board
		if ((board[nqueen] == board[i]) ||
				(checkdiag(board[nqueen], board[i]) == (nqueen - i)))
			return (0);
		i++;
	}
	return (1);
}

void	start(int nqueen, int *board, int *conta)
{
	board[nqueen] = 0;
	while (board[nqueen] < 10)
	{
		if (checksafe(nqueen, board))
		{
			if (nqueen == 9)
			{
				ft_putout(board);
				*conta = *conta + 1;
			}
			else
				start(nqueen + 1, board, conta);
		}
		board[nqueen]++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int board[10];
	int nqueen;
	int conta;

	conta = 0;
	nqueen = 0;
	start(nqueen, board, &conta);
	return (conta);
}
int main()
{
    printf("%d\n", ft_ten_queens_puzzle());
    ft_putchar('\n');
}