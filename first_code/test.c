/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 16:17:08 by elhmn             #+#    #+#             */
/*   Updated: 2014/03/15 11:56:24 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab_tools.h"
#include "minimax.h"
#include "puissance4.h"
#include <stdio.h>

int		main(void)
{
	int		**tab;
	t_game	game;

	tab = NULL;
	tab = create_tab(tab, LINE, COL);
	if (!tab)
	{
		printf("ERROR\n");
		return (0);
	}
	init_tab(tab, LINE, COL);
	game_init(game);
	print_tab(tab, LINE, COL);
	win_line(tab, data);
	init_tab(tab, LINE, COL);
	win_col(tab, data);
	init_tab(tab, LINE, COL);
	win_diag1(tab, data);
	init_tab(tab, LINE, COL);
	win_diag2(tab, data);
	printf("END\n");
	init_tab(tab, LINE, COL);
	win_diag3(tab, data);
	init_tab(tab, LINE, COL);
	win_diag4(tab, data);
	print_tab(tab, LINE, COL);
	return (0);
}
