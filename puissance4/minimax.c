/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimax.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 16:32:48 by elhmn             #+#    #+#             */
/*   Updated: 2014/03/15 17:06:58 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

int		put_coin(int **tab, t_game game, int play)
{
	int		i;

//	segfault(lol++);
	i = game.line - 1;
	if (play == -1) //if IA is playing
		play = game.coup;
	if (tab[0][play] != 0)
		return (1);
	while (i >= 0 && tab[i][play] != 0)
		i--;
	if (i >= 0 && tab[i][play] == 0)
		tab[i][play] = game.player;
	return (0);
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
	
int		minimax(int **tab, t_game *game, int depht, int col, int who)
{
	int		mark_max;
	int		mark;

	if (depht <= 0 || win(tab, *game))
		return (eval(tab, *game, col, who));
	if (game->player == MIN)
	{
		mark_max = -INF;
		col = 0;
		while (col < game->col)
		{
			put_coin(tab, *game, col);
			game->player = MAX;
		//	print_game(*game, col, mark);
		//	usleep(PAUSE);
			mark = minimax(tab, game, --depht, col, MIN);
		//	printf("mark = %d\n", mark);
		//	print_game(*game, col, mark);
			//usleep(PAUSE);
			remove_coin(tab, *game, col);
			if (mark > mark_max)
			{
				mark_max = mark;
				game->coup = col;
			}
			col++;
		}
	}
	else
	{	
		mark_max = INF;
		col = 0;
		while (col < game->col)
		{
			put_coin(tab, *game, col);
			game->player = MIN;
		//	print_tab(tab, game->line, game->col);
		//	print_game(*game, col, mark);
		//	usleep(PAUSE);
			mark = minimax(tab, game, --depht, col, MAX);
		//	printf("mark = %d", mark);
		//	print_game(*game, col, mark);
		//	usleep(PAUSE);
			remove_coin(tab, *game, col);
			if (mark < mark_max)
			{
				mark_max = mark;
				game->coup = col;
			}
			col++;
		}
	}
	return (mark_max);
}
