/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:46:37 by elhmn             #+#    #+#             */
/*   Updated: 2014/03/10 15:46:37 by elhmn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tab_tools.h"
#include "debug.h"
#include "minimax.h"
#include <unistd.h>

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

	game_init(&game);
	tab = NULL;
	tab = create_tab(tab, LINE, COL);
	init_tab(tab, LINE, COL);
	print_tab(tab, LINE, COL);
	while (1)
	{
		srand(time(NULL));
		sleep(2);
		game.player = 1;
		printf("********* before ***********\n");
		print_game(game, 0, 0);
		minimax(new = copy_tab(tab, LINE, COL), &game, DEPHT);
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
		
		sleep(2);

		game.player = 2;
		printf("********* before ***********\n");
		print_game(game, 0, 0);
		minimax(new = copy_tab(tab, LINE, COL), &game, DEPHT);
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
	}
	free_tab(tab, LINE);
	return (0);
}
