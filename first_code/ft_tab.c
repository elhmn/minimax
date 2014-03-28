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

#include "puissance4.h"

void	ft_display_nbr(int col)
{
	int		i;

	i = 0;
	while (i < col)
	{
		ft_putstr("   ");
		ft_putnbr((i + 1) % 10);
		i++;
	}
	ft_putchar('\n');
}

static void		ft_disp_token(int nbr)
{
	if (nbr == 0)
		ft_putchar('.');
	else if (nbr == 1)
		ft_putchar('X');
	else
		ft_putchar('O');
}


void	ft_display_tab(t_data data)
{
	int		line;
	int		col;
	int		i;
	int		j;

	line = data.line;
	col = data.col;
	i = 0;
	j = 0;
	while (i < line)
	{
		while (j < col)
		{
			ft_putstr(" | ");
			ft_disp_token(data.tab[i][j]);
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

int		ft_init_tab(t_data *data)
{
	int		line;
	int		col;
	int		i;
	int		j;

	line = data->line;
	col = data->col;
	i = 0;
	j = 0;
	if (!(data->tab = (int **)malloc(sizeof(int *) * (line))))
	{
		ft_putendl_fd("Puissance 4: not sufficient memory", 2);//puterror();
		return (0);
	}
	while (i < line)
	{
		if (!(data->tab[i] = (int *)malloc(sizeof(int) * (col))))
		{
			ft_putendl_fd("Puissance 4: not sufficient memory", 2);
			return (0);
		}
		while (j < col)
		{
			data->tab[i][j] = 0;
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}
