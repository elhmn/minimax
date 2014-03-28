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

# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <time.h>
# define	P1	1
# define	P2	2
# define	CPU 2

typedef struct		s_data
{
	int				col;
	int				line;
	int				token;
	int				pos;
	int				**tab;
	int				player1;
	int				player2;
}					t_data;

void	swap(int *i, int *j);
int		convert(int who);
void	play(t_data *data, int who);
int		turn(t_data *data, int who_start);
int		ft_get_data(char **av, t_data *data);
int		win_diag(int **tab, t_data data);
int		win(int **tab, t_data data);
int		win_line(int **tab, t_data data);
int		win_col(int **tab, t_data data);
int		get_mode(void);
int		choose_mode(void);
int		put_piece(t_data *data, int who);
int		arg_error(int ac);
int		ft_error(int err);
int		ft_isspace(char c);
int		ft_check_data(char *str);
void	ft_display_tab(t_data data);
int		ft_init_tab(t_data *data);
int		getnbr_fd(t_data *data, int fd);
void	ft_display_nbr(int col);

#endif /* !PUISSANCE4_H */
