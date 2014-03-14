/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 14:31:29 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/09 18:35:43 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minimax.h"


int		eval(int **tab, t_game game)
{
	int		mark;
	
	mark = 0;
	if (check_marks(tab, game, 4, 0))
		mark = 1000;
	else if (check_marks(tab, game, 3, 1))
		mark = 100;
	else if (check_marks(tab, game, 2, 2))
		mark = 10;
	else if (check_marks(tab, game, 1, 3))
		mark = 1;
	else if (check_marks(tab, game, 0, 4))
		mark = -1000;
	else if (check_marks(tab, game, 1, 3))
		mark = -100;
	else if (check_marks(tab, game, 2, 2))
		mark = -10;
	else if (check_marks(tab, game, 3, 1))
		mark = -1;
	return (mark);
}

int		check_marks(int **tab, t_game game, int P1, int P2)
{
	if (win_line(tab, game, P1, P2))
		return (1);
	else if (win_col(tab, game, P1, P2))
		return (1);
	else if (win_diag(tab, game, P1, P2))
		return (1);
	return (0);
}
