/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 21:16:18 by scadoux           #+#    #+#             */
/*   Updated: 2014/03/07 22:53:01 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	else if (c == ' ')
		return (1);
	return (0);
}

int			ft_check_data(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || ft_isspace(str[i]))
			i++;
		else
			return (-1);
	}
	return (0);
}
