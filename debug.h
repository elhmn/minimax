/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 19:08:31 by elhmn             #+#    #+#             */
/*   Updated: 2014/03/10 19:08:31 by elhmn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
#define DEBUG_H
#include "minimax.h"

void	print_game(t_game game, int play,int mark);
void	debug(int i);
void	segfault(int i);

#endif /* !DEBUG_H */
