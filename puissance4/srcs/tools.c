/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 01:46:10 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/08 07:29:50 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "puissance4.h"
#include "libft.h"

int		getnbr_fd(t_game *game)
{
	char	*nbr;
	int		ret;
	int		play;

	play = 0;
	if ((ret = get_next_line(0, &nbr)))
		if (ft_check_data(nbr) || !*nbr)
		{
			ft_putendl_fd("U must only type digit", 2);
			return (0);
		}
	if (ret == -1)
	{
		ft_putendl_fd("file not found", 2);//error
		return (0);
	}
	play = ft_atoi(nbr);
	if (play >= game->col || play < 0)
	{
		ft_putendl_fd("U cant play on this column", 2);
		return (0);
	}
	if (put_coin(game->tab, *game, play))//si je peu plus deposer le pion
	{
			ft_putendl_fd("This column is already full", 2);
		return (0);
	}
	return (1);
}
