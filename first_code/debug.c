/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 19:04:43 by elhmn             #+#    #+#             */
/*   Updated: 2014/03/10 19:04:43 by elhmn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minimax.h"

void	segfault(int i)
{
	printf("**************** SEGFAULT %d *****************\n", i);
}

void	debug(int i)
{
	printf("**************** DEBUG %d *****************\n", i);
}

void	print_game(t_game game, int play, int mark)
{
	printf(" game.line = [ %d ] \n game.col = [ %d ] \n game.player = [ %d ]\n game.coup = [ %d ]\n m = [ %d ]\n", game.line, game.col, game.player, game.coup, play);
	printf(" mark = [ %d ]\n", mark);
}


/*
void	debug(int i)
{
	printf("**************** SEGFAULT %d *****************\n", i)
}
*/
