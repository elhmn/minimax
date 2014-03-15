/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:46:37 by elhmn             #+#    #+#             */
/*   Updated: 2014/03/15 13:23:08 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "tab_tools.h"
#include "minimax.h"
#include "debug.h"
#include "puissance4.h"

void	game_init(t_game *game)
{
	srand(time(NULL));
	game->line = LINE;
	game->col = COL;
	game->player = 1;
	game->coup = rand() % game->col;
}

int		main(void)
{
	int		**tab;
	int		**new;
	t_game  game;
	int gain;

	game_init(&game);
	tab = NULL;
	tab = create_tab(tab, LINE, COL);
	init_tab(tab, LINE, COL);
	print_tab(tab, LINE, COL);
	while(!win(tab, game, 4, 0) && !win(tab, game, 0, 4))
	{
		srand(time(NULL));
		sleep(2);
		game.player = 1;
		printf("********* before ***********\n");
		//print_game(game, 0, 0);
		gain = 	minimax(new = copy_tab(tab, LINE, COL), &game, DEPHT, 0);
		free(new);
		if (!game.coup)
		{
			printf("game_coup == 0\n");
			game.coup = rand() % game.col;
		}
		put_coin(tab, game, -1);
		printf("********* after ***********\n");
		print_game(game, 0, 0);
		print_tab(tab, LINE, COL);
		printf(" gain1 = %d\n",gain);
		
		sleep(2);

		game.player = 2;
		printf("********* before ***********\n");
		print_game(game, 0, 0);
		gain = minimax(new = copy_tab(tab, LINE, COL), &game, DEPHT, 0);
		free(new);
		if (!game.coup)
		{
			printf("game_coup == 0\n");
			game.coup = rand() % game.col;
		}
		put_coin(tab, game, -1);
		printf("********* after ***********\n");
	//	print_game(game, 0, 0);
		print_tab(tab, LINE, COL);
	printf(" gain2 = %d\n",gain);
	}
	print_tab(tab, LINE, COL);
	free_tab(tab, LINE);
	return (0);
}
