/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gametools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 19:37:10 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/09 20:43:57 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "puissance4.h"
#include "minimax.h"
#include <time.h>
#include <stdlib.h>

//game.coup

int		ft_get_data(char **av, t_game *game, int who)
{
	srand(time(NULL));
	if (ft_check_data(av[2]) == -1)
		return (ft_error(1));
	game->col = ft_atoi(av[2]);
	if (ft_check_data(av[1]) == -1)
		return (ft_error(2));
	game->line = ft_atoi(av[1]);
	if ((game->line < 6) || (game->col < 7))
		return (ft_error(3));
	if(!ft_init_tab(game))
		return (0);
	game->coup = rand() % game->col;
	game->player = who;
	return (1);
}

/*
int		turn_cpu(t_game *game, int who_start)
{
	int		p1;
	int		cpu;

	p1 = P1;
	cpu = CPU;
	if (who_start == P1)
		swap(&p1, &cpu);
	play_cpu(game, p1);
	if (win(game->tab, *game))
		return (1);
	play_cpu(game, cpu);
	return (0);
}
*/

/*
void	play_cpu(t_game *game, int who)
{
	ft_display_tab(*game);
	ft_putstr("Player ");
	ft_putnbr(who);
	ft_putendl(" : play ?");
	while (!getnbr_fd(game, who))
	{
		ft_putstr("Player ");
		ft_putnbr(who);
		ft_putendl(" : play ?");
	}
}
*/

void	play(t_game *game)
{
	ft_display_tab(*game);
	ft_putstr("Player ");
	ft_putnbr(game->player);
	ft_putendl(" : play ?");
	while (!getnbr_fd(game))
	{
		ft_putstr("Player ");
		ft_putnbr(game->player);
		ft_putendl(" : play ?");
	}
}
