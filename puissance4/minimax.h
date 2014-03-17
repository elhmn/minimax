/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimax.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 17:26:21 by elhmn             #+#    #+#             */
/*   Updated: 2014/03/15 13:24:10 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAX_H
# define MINIMAX_H
# define INF 20000
# define MAX 1
# define MIN 2
# define DEPHT 10
# define PAUSE 50000

typedef struct	s_game
{
	int		line;
	int		col;
	int		coup;
	int		player;
	int		**tab;
}				t_game;

/*
** gametools.c 
*/

int		ft_get_data(char **av, t_game *game, int who);

/*
** minimax.c
*/

int		minimax(int **tab, t_game *game, int depht, int col, int who);
void	remove_coin(int **tab, t_game game, int play);
int		put_coin(int **tab, t_game game, int play);
void	free_tab(int **tab, int size);

/*
** win.c
*/

void	congrat(int who);
int		win(int **tab, t_game game);
int		win_line(int **tab, t_game game);
int		win_col(int **tab, t_game game);

/*
** win_diag.c
*/

int		win_diag(int **tab, t_game game);
int		win_diag1(int **tab, t_game game);
int		win_diag2(int **tab, t_game game);
int		win_diag3(int **tab, t_game game);
int		win_diag4(int **tab, t_game game);

/*
** eval.c
*/

int		check_marks(int **tab, t_game game, int P1, int P2, int col);
int		eval(int **tab, t_game game, int col, int who);

#endif /* !MINIMAX_H */
