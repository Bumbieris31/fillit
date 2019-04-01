#include <string.h>
#include "libft.h"
#include "fillit.h"

char	**make_board(int tcount);
char	**incr_board(char **board);
void	ft_print_board(char **board);
int		*ft_locate_tetri_space(int tetri[][6], t_tbox *tbox);
void	ft_put_tetri(int tetri[][6], t_tbox *tbox);
int		*ft_check_for_space(int tetri[][6], t_tbox *tbox);
int		ft_check_incr(t_tbox *tbox);

t_tbox	*ft_make_tbox(int tetri_count)
{
	t_tbox	*tbox;

	tbox = (t_tbox*)malloc(sizeof(t_tbox));
	tbox->tcount = tetri_count;
	tbox->tindex = 0;
	tbox->board = make_board(tetri_count);
	tbox->xy[0] = 0;
	tbox->xy[1] = 0;
	return(tbox);
}

void	ft_fillit_magic()
{
	int 	tetri[7][6] = {{0, 1, 0, 2, 1, 2}, {1, 0, 2, 0, 3, 0}, {1, 0, 2, 0, 2, 1}, \
	{1, 0, 2, 0, 2, 1}, {0, 1, 1, 1, 1, 0}, {1, -1, 1, 0, 1, 1}, {2, -1, 2, 0, 1, 0}}; // ¬ , | , L, L, [], ^, _|
	int 	*x_y_val;
	t_tbox	*tbox;

	tbox = ft_make_tbox(7);
	if (tbox->board == NULL)
		ft_putstr("Make fail! \n");
	else
	{
		while (ft_check_incr(tbox))
			tbox->board = incr_board(tbox->board);
		while (tbox->tindex < tbox->tcount)
		{
			x_y_val = NULL;
			while (x_y_val == NULL)
			{
				x_y_val = ft_check_for_space(tetri, tbox);
				if (x_y_val == NULL)
				{
					tbox->board = incr_board(tbox->board);
					ft_putstr("\nIncr happened \n");
				}
				if (tbox->board == NULL)
				{
					ft_putstr("Epic increment fail! \n");
					break;
				}
			}
			ft_put_tetri(tetri, tbox);
			ft_putstr("\nTetri planted -_-\n");
			ft_print_board(tbox->board);
			tbox->tindex++;
		}
	}
}


/*
char	**ft_fillit_solve(int tetri[][6], t_tbox *tbox)
{
	int		*a;
	char 	**ret;

	a = ft_check_for_space(tetri, tbox);
	if (a != NULL)
	{
		ft_put_tetri(tetri, tbox);
		tbox->tindex++;
		if (tbox->tindex == tbox->tcount)
			return (tbox->board);
		
		ret = ft_fillit_solve(tetri, tbox);
	}
	else if (a == NULL && ft_check_incr(tbox) == 0)
	{
	}
	// vienu tetri atpakal, tad pakustini to tetri uz prieksu, tad megini atkal.
}
*/

int	main(void)
{
	/*
	int	tetri[5][6] = {{0, 1, 0, 2, 1, 2}, {1, 0, 2, 0, 3, 0}, {1, 0, 2, 0, 2, 1}, \
	{1, 0, 2, 0, 2, 1}, {0, 1, 1, 1, 1, 0}}; // ¬ , I , L, L, []
	t_tbox	*tbox;
	
	tbox = ft_make_tbox(5);
	ft_fillit_solve(tetri, tbox);
	*/
	ft_fillit_magic();
}