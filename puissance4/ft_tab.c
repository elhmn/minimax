/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 21:39:34 by scadoux           #+#    #+#             */
/*   Updated: 2014/03/09 19:45:39 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "puissance4.h"
#include "libft.h"
#define MAL_ERROR {ft_putendl_fd("Puissance 4: not sufficient memory", 2);\
			return (0);}

void	ft_display_nbr(int col)
{
	int		i;

	i = 0;
	ft_putstr("\033[0;1;35m");
	while (i < col)
	{
		if (i > 9)
			ft_putstr("  ");
		else
			ft_putstr("   ");
		ft_putnbr(i);
		i++;
	}
	ft_putstr("\033[0m");
	ft_putchar('\n');
}

static void		ft_disp_token(int nbr)
{
	if (nbr == 0)
		ft_putstr("\033[0;1;35m.\033[0m");
	else if (nbr == 1)
		ft_putstr("\033[0;1;31mX\033[0m");
	else
		ft_putstr("\033[0;1;33mO\033[0m");
}

/*
** print map
*/

void	ft_display_tab(t_game game)
{
	int		line;
	int		col;
	int		i;
	int		j;

	line = game.line;
	col = game.col;
	i = 0;
	j = 0;
	while (i < line)
	{
		while (j < col)
		{
			ft_putstr(" | ");
			ft_disp_token(game.tab[i][j]);
			j++;
		}
		ft_putstr(" | ");
		ft_putchar('\n');
		i++;
		j = 0;
	}
	ft_display_nbr(col);
	ft_putstr("Token per player : ");
	ft_putnbr((line * col) / 2);
	ft_putchar('\n');
}

/*
** create and initialize map
*/

int		ft_init_tab(t_game *game)
{
	int		line;
	int		col;
	int		i;
	int		j;

	line = game->line;
	col = game->col;
	i = 0;
	j = 0;
	if (!(game->tab = (int **)malloc(sizeof(int *) * (line))))
		MAL_ERROR
	while (i < line)
	{
		if (!(game->tab[i] = (int *)malloc(sizeof(int) * (col))))
			MAL_ERROR
		while (j < col)
		{
			game->tab[i][j] = 0;
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}
