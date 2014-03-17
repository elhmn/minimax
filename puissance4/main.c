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
			while (!win(game.tab, game)) //rajouter le cas d'egalite
			{
				play(&game, who);
				if (game.player == P1)
					game.player = P2;
				else
					game.player = P1;
			}
			ft_display_tab(game);
		}
		else
		{
		//	while (!win(game.tab, game))
		//	{
		//		if ()
		//			return (0);
		//	}
			ft_putendl("The IA versus mode is unavialable");
		}
	}
	free_tab(game.tab, game.line);
	return (0);
}
