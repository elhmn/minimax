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

void	swap(int *i, int *j);
int		convert(int who);
int		get_mode(void);
int		choose_mode(void);
int		arg_error(int ac);
int		ft_error(int err);
int		ft_isspace(char c);

#endif /* !PUISSANCE4_H */
