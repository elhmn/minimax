/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 18:09:29 by elhmn             #+#    #+#             */
/*   Updated: 2014/03/16 18:09:29 by elhmn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "puissance4.h"
#define P1 1
#define P2 2

static int		convert(int who)
{
	if (who == 0)
		return (P1);
	else
		return (P2);
}

/*
static void		swap(int *i, int *j)
{
	int		tmp;
	
	tmp = *i;
	*i = *j;
	*j = tmp;
	
}
*/

int				main(int ac, char **av)
{
	int		who;
	int		mode;
	t_game	game;
	int		gain;
	int		**tab;

	srand(time(NULL));
	who = convert(rand() % 2);
	if (!arg_error(ac))
		return (0);
	else
	{
		if (!ft_get_data(av, &game, who))
			return (1);
		mode = choose_mode();
		if (mode == 2)
		{
			while (!(who = win(game.tab, game))) //rajouter le cas d'egalite
			{
				play(&game);
				if (game.player == P1)
					game.player = P2;
				else
					game.player = P1;
			}
			congrat(who);
			ft_display_tab(game);
		}
		else
		{
			while (!(who = win(game.tab, game)))
			{
				if (game.player == 1)
				{
					play(&game);
					game.player = 2;
				}
				else
				{
					gain = minimax(tab = copy_tab(game.tab, game.line, game.col), &game, DEPHT, 0, 2);
					printf("gain = [ %d ]\n", gain);
					game.player = 2;
					if (gain == 0)
						game.coup = game.col / 2 + 1;
					while (put_coin(game.tab, game, -1))
						game.coup = rand() % game.col;
					game.player = 1;
					free_tab(tab, game.line);
				}
			}
			congrat(who);
			ft_display_tab(game);
		}
	}
	free_tab(game.tab, game.line);
	return (0);
}
