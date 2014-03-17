/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 21:13:09 by scadoux           #+#    #+#             */
/*   Updated: 2014/03/08 01:26:07 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "puissance4.h"

int		ft_error(int err)
{
	if (err == 1)
	{
		ft_putendl_fd("Puissance 4 : error Colomn must be digits only", 2);
		return (0);
	}
	if (err == 2)
	{
		ft_putendl_fd("Puissance 4 : error line must be digits only", 2);
		return (0);
	}
	if (err == 3)
	{
		ft_putstr_fd("Puissance 4 : error Grid size must be at least 6", 2);
		ft_putendl_fd(" * 7 digits", 2);
		return (0);
	}
	return (0);
}

int		arg_error(int ac)
{
	if (ac == 1)
	{
		ft_putendl_fd("Puissance 4 : usage col, line ", 2);
		return (0);
	}
	else if (ac == 2)
	{
		ft_putendl_fd("Puissance 4 : error Too few Arguments", 2);
		return (0);
	}
	else if (ac != 3)
	{
		ft_putendl_fd("Puissance 4 : error Too much Arguments", 2);
		return (0);
	}
	return (1);
}
