
int		ft_fillit_magic(char **board)
{
	int 	tetri[3][6] = {{0, 1, 0, 2, 1, 2}, {1, 0, 2, 0, 3, 0}, {1, 0, 2, 0, 2, 1}}; // ¬ , I , L
	char	**board;

	board = make_board();
}


/*
** @desc -	checks if it is possible to place tetrimino in a board.
** @param - tetri_index - which tetrimino in a tetri[] array it is.
** @var - int i[2] - i[0] and i[1] array that represents x and y values respectively.
** @return - either i with x and y values or -1 if there is no space.
*/

int		*ft_check_for_space(int **tetri, char **board, int tetri_index)
{
	int	i[2];

	i[0] = 0;
	i[1] = 0;
	while (board[i[0]])
	{
		while (board[i[0]][i[1]] && board[i[0]][i[1]] != '.')
			i[1]++;
		if (board[i[0]][i[1]] == '.')
		{
			if (board[i[0] + tetri[tetri_index][0]][i[1] + tetri[tetri_index][1]] \
			&& board[i[0] + tetri[tetri_index][2]][i[1] + tetri[tetri_index][3]] \
			&& board[i[0] + tetri[tetri_index][4]][i[1] + tetri[tetri_index][5]] \
			&& board[i[0] + tetri[tetri_index][0]][i[1] + tetri[tetri_index][1]] == '.' \
			&& board[i[0] + tetri[tetri_index][2]][i[1] + tetri[tetri_index][3]] == '.' \
			&& board[i[0] + tetri[tetri_index][4]][i[1] + tetri[tetri_index][5]] == '.')
			{
				return (i);
			}
		}
		i[0]++;
	}
	return (-1);
}

int		ft_create_tetri(int	**tetri, char **board, int tetri_index)
{
	int side;
	ft_check_for_space();
	ft_
}