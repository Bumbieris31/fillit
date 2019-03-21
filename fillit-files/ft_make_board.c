
// Compile with Arturs libft bc of the difference in ft_wordlen.

#include "libft.h"

/*
** @desc - Creates a board.
** @param
** @var char** board - a 2d char array(2 by 2) which holds dots.
** @return - board.
*/

char	**make_board()
{
	char	**board;

	board = (char**)malloc(sizeof(char*) * 6);
	board[0] = (char*)malloc(4);
	board[1] = (char*)malloc(4);
	board[2] = (char*)malloc(1);
	board[0] = ft_strcpy(board[0], "..\n");
	board[1] = ft_strcpy(board[1], "..\n");
	board[2] = ft_strcpy(board[2], "\0");
	return(board);
}

/*
** @desc - Increments the boards field by (x + 1)^2 where x is the length of a side.
** @param - char **board.
** @var - a to save '\n' index.
** @var - i and j to loop through.
** @var - *point to hold a pointer to "./n" string to be added at the end of line.
** @var - *temp to avoid memory leak.
** @return - board.
*/

char	**incr_board(char **board)
{
	int		a;
	int		i;
	int		j;
	char	*point;
	char	*temp;

	point = ".\n";
	a = ft_wordlen(board[0], '\n');
	i = 0;
	while (ft_strcmp(board[i], "\0") != 0)
	{
		board[i][a] = '\0';
		temp = ft_strdup(board[i]);
		free(board[i]);
		board[i] = ft_strjoin(temp, point);
		free(temp);
		i++;
	}
	board[i] = (char*)malloc(a + 2);
	j = 0;
	while (j <= a)
	{
		board[i][j] = '.';
		j++;
	}
	board[i][j]	= '\n';
	board[i][j + 1] = '\0';
	board[i + 1] = (char*)malloc(1);
	board[i + 1] = "\0";
	return(board);
}
/*
** @desc - Prints a board.
** @param char **board.
*/

void	ft_print_board(char **board)
{
	int	i;

	i = 0;
	while (ft_strcmp(board[i], "\0") != 0)
	{
		ft_putstr(board[i]);
		i++;
	}
}

/*
int	main(void)
{
	char	**board;

	board = make_board();
	ft_print_board(board);
	board = incr_board(board);
	ft_print_board(board);
	board = incr_board(board);
	ft_print_board(board);
	board = incr_board(board);
	ft_print_board(board);
	return(0);
}
*/
