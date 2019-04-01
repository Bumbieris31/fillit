#include <string.h>
#include "libft.h"
#include "fillit.h"

/*
** @desc -	checks if it is possible to place tetrimino in a board.
** @param - tbox->tindex - which tetrimino in a tetri[] array it is.
** @var - int xy[2] - xy[0] and xy[1] array that represents x and y values respectively.
** @return - either i with x and y values or -1 if there is no space.
*/

int		*ft_locate_tetri_space(int tetri[][6], t_tbox *tbox)
{
	if (tbox->board[tbox->xy[0] + tetri[tbox->tindex][0]] \
	&& tbox->board[tbox->xy[0] + tetri[tbox->tindex][0]][tbox->xy[1] + tetri[tbox->tindex][1]] \
	&& tbox->board[tbox->xy[0] + tetri[tbox->tindex][2]]	\
	&& tbox->board[tbox->xy[0] + tetri[tbox->tindex][2]][tbox->xy[1] + tetri[tbox->tindex][3]] \
	&& tbox->board[tbox->xy[0] + tetri[tbox->tindex][4]] \
	&& tbox->board[tbox->xy[0] + tetri[tbox->tindex][4]][tbox->xy[1] + tetri[tbox->tindex][5]] \
	&& tbox->board[tbox->xy[0] + tetri[tbox->tindex][0]][tbox->xy[1] + tetri[tbox->tindex][1]] == '.' \
	&& tbox->board[tbox->xy[0] + tetri[tbox->tindex][2]][tbox->xy[1] + tetri[tbox->tindex][3]] == '.' \
	&& tbox->board[tbox->xy[0] + tetri[tbox->tindex][4]][tbox->xy[1] + tetri[tbox->tindex][5]] == '.')
	{
		return (tbox->xy);
	}
	else
		return (NULL);
}

void	ft_put_tetri(int tetri[][6], t_tbox *tbox)
{
	tbox->board[tbox->xy[0]][tbox->xy[1]] = 'A' + tbox->tindex;
	tbox->board[tbox->xy[0] + tetri[tbox->tindex][0]][tbox->xy[1] + tetri[tbox->tindex][1]] = 'A' + tbox->tindex;
	tbox->board[tbox->xy[0] + tetri[tbox->tindex][2]][tbox->xy[1] + tetri[tbox->tindex][3]] = 'A' + tbox->tindex;
	tbox->board[tbox->xy[0] + tetri[tbox->tindex][4]][tbox->xy[1] + tetri[tbox->tindex][5]] = 'A' + tbox->tindex;
}

int		*ft_check_for_space(int tetri[][6], t_tbox *tbox)
{
	int *ret;

	tbox->xy[0] = 0;
	tbox->xy[1] = 0;
	while (tbox->board && tbox->board[tbox->xy[0]] != NULL)
	{
		while (tbox->board[tbox->xy[0]][tbox->xy[1]] && tbox->board[tbox->xy[0]][tbox->xy[1]] != '.' && tbox->board[tbox->xy[0]][tbox->xy[1]] != '\n')
			tbox->xy[1]++;
		if (tbox->board[tbox->xy[0]][tbox->xy[1]] == '.')
		{
			ret = ft_locate_tetri_space(tetri, tbox);
			if (ret != NULL)
				return (tbox->xy);
		}
		if (tbox->board[tbox->xy[0]][tbox->xy[1]] == '\n')
		{
			tbox->xy[0]++;
			tbox->xy[1] = 0;
		}
		else
			tbox->xy[1]++;
	}
	return (NULL);
}

/*
** @desc - Checks if it is necessary to increase the board. Can be used in a loop.
** @param -
** @var -  
** @return -
*/

int		ft_check_incr(t_tbox *tbox)
{
	int	i;

	i = 0;
	while (tbox->board[0][i] != '\n')
		i++;
	if (tbox->tcount * 4 > i * i)
		return (1);
	return (0);
}
