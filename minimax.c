/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimax.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 16:32:48 by elhmn             #+#    #+#             */
/*   Updated: 2014/03/10 16:32:48 by elhmn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab_tools.h"
#include "minimax.h"
#include "debug.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	remove_coin(int **tab, t_game game, int play)
{
	int		i;

	i = 0;
	while (i < game.line && tab[i][play] == 0)
		i++;
	if (i < game.line && tab[i][play] != 0)
		tab[i][play] = 0;
}

//static int lol = 0;

void	put_coin(int **tab, t_game game, int play)
{
	int		i;

//	segfault(lol++);
	i = game.line - 1;
	if (play == -1)
		play = game.coup;
	while (i >= 0 && tab[i][play] != 0)
		i--;
	if (i >= 0 && tab[i][play] == 0)
		tab[i][play] = game.player;
}

void	free_tab(int **tab, int size)
{
	int		i;
	
	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
}
	
int		minimax(int **tab, t_game *game, int depht)
{
	int		m;
	int		mark_max;
	int		mark;

	m = 0;
	if (depht <= 0)
		return (eval(tab, *game));
	if (game->player == MAX)
	{
		mark_max = -INF;
		while (m < game->col)
		{
			put_coin(tab, *game, m);
			game->player = MIN;
			//print_game(*game, m, mark);
			//usleep(PAUSE);
			mark = minimax(tab, game, --depht);
			//printf("mark = %d\n", mark);
			//print_game(*game, m, mark);
			//usleep(PAUSE);
			remove_coin(tab, *game, m);
			if (mark > mark_max)
			{
				mark_max = mark;
				game->coup = m;
			}
			m++;
		}
	}
	else
	{	
		mark_max = INF;
		while (m < game->col)
		{
			put_coin(tab, *game, m);
			game->player = MAX;
	//print_tab(tab, game->line, game->col);
			//print_game(*game, m, mark);
			//usleep(PAUSE);
			mark = minimax(tab, game, --depht);
			//printf("mark = %d", mark);
			//print_game(*game, m, mark);
			//usleep(PAUSE);
			remove_coin(tab, *game, m);
			if (mark < mark_max)
			{
				mark_max = mark;
				game->coup = m;
			}
			m++;
		}
	}
	return (mark_max);
}
