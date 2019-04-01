/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 22:16:10 by rlaros            #+#    #+#             */
/*   Updated: 2019/03/29 19:34:18 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

// #include "../libft/includes/libft.h"

/*
** ERROR MESSAGES
*/
# define WRONG_USAGE "usage: ./fillit source_file\n"

typedef struct	s_tbox
{
	int		xy[2];
	int		tcount;
	int		tindex;
	char	**board;
}				t_tbox;

int		ft_setup(int argc, char **argv);
void	ft_handle_error(int error_code);

#endif
