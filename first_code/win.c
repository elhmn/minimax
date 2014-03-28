/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 05:04:14 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/08 13:26:53 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "tab_tools.h"
#include "minimax.h"
#include "puissance4.h"

void	congrat(int who)
{
	printf("\n\n****************** CONGRATULATION *******************");
		if (who == 1)
			printf("\n**************** PLAYER 1 WIN ****************\n");
		else
			printf("\n**************** PLAYER 2 WIN ****************\n");
//		ft_display_tab(rata);
}

int		win(int **tab, t_game game)
{
	int		who;

	who = 0;
	if ((who = win_col(tab, game)))
		congrat(who);
	else if ((who = win_line(tab, game)))
		congrat(who);
	else if ((who = win_diag(tab, game)))
		congrat(who);
	return (who);
}

int		win_col(int **tab, t_game game)
{
	int		i;
	int		j;
	int		k;
	int		win[2] = {0,0};

	i = 0;
	while (i < game.col)
	{
		j = 0;
		while (j + 3 < game.line)
		{
			k = j;
			win[0] = 0;
			win[1] = 0;
			while (k < j + 4 && k < game.line)
			{
			//	tab[k][i] = 1;
			//	print_tab(tab, LINE, COL);
			//	usleep(PAUSE);
				if (tab[k][i] == 1)
					win[0]++;
				else if (tab[k][i] == 2)
					win[1]++;
				k++;
			}
			//	init_tab(tab, LINE, COL);
			//	usleep(PAUSE);
			if (win[0] == 4)
				return (1);
			if (win[1] == 4)
				return (2);
			j++;
		}
		i++;
	}
	return (0);
}

int		win_line(int **tab, t_game game)
{
	int		i;
	int		j;
	int		k;
	int		win[2] = {0,0};

	i = 0;
	while (i < game.line)
	{
		j = 0;
		while (j + 3 < game.col)
		{
			k = j;
			win[0] = 0;
			win[1] = 0;
			while (k < j + 4 && k < game.col)
			{
			//	tab[i][k] = 2;
			//	print_tab(tab, LINE, COL);
			//	usleep(PAUSE);
				if (tab[i][k] == 1)
					win[0]++;
				else if (tab[i][k] == 2)
					win[1]++;
				k++;
			}
			//init_tab(tab, LINE, COL);
			//usleep(PAUSE);
			if (win[0] == 4)
				return (1);
			if (win[1] == 4)
				return (2);
			j++;
		}
		i++;
	}
	return (0);
}
