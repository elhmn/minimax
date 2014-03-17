/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 20:06:38 by scadoux           #+#    #+#             */
/*   Updated: 2014/03/09 20:14:42 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H
# include "minimax.h"

/*
** ft_tab.c
*/

void	ft_display_tab(t_game game);
int		ft_init_tab(t_game *game);

/*
** tools.c
*/

int		getnbr_fd(t_game *game);

/*
** mode_tools.c 
*/

int		choose_mode(void);

/*
** ft_error.c
*/

int		arg_error(int ac);
int		ft_error(int err);

/*
** ft_check data.c
*/

int		ft_check_data(char *str);

/*
** gametools.c 
*/

void	play(t_game *game, int who);

#endif /* !PUISSANCE4_H */
