/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 03:51:32 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/08 04:40:11 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "puissance4.h"
#include "libft.h"

static int	get_mode(void)
{
	char	*nbr;
	int		ret;
	int		mode;

	if ((ret = get_next_line(0, &nbr)))
		if (ft_check_data(nbr))
		{
			ft_putendl_fd("U must only type digit", 2);
			return (0);
		}
	if (ret == -1)
	{
		ft_putendl_fd("file not found", 2);
		return (0);
	}
	mode = ft_atoi(nbr);
	return (mode);
}

int			choose_mode(void)
{
	int		mode;

	mode = 0;
	while (mode > 2 || mode == 0)
	{
		ft_putendl("******* Welcome to Puissance4 ********\n\n");
		ft_putendl("1 - to play with CPU");
		ft_putendl("2 - two payers");
		ft_putstr("Press Key ? ");
		mode = get_mode();
	}
	return (mode);
}
