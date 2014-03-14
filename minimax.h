/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimax.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 17:26:21 by elhmn             #+#    #+#             */
/*   Updated: 2014/03/10 17:26:21 by elhmn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAX_H
# define MINIMAX_H
# define INF 20000
# define MAX 1
# define MIN 2
# define PAUSE 50000

typedef struct	s_game
{
	int		line;
	int		col;
	int		coup;
	int		player;
}				t_game;

int		minimax(int **tab, t_game *game, int depht);
void	remove_coin(int **tab, t_game game, int play);
void	put_coin(int **tab, t_game game, int play);
void	free_tab(int **tab, int size);

/*
** Evaluation functions
*/

int		win_diag(int **tab, t_game game, int P1, int P2);
int		win_diag1(int **tab, t_game game, int P1, int P2);
int		win_diag2(int **tab, t_game game, int P1, int P2);
int		win_diag3(int **tab, t_game game, int P1, int P2);
int		win_diag4(int **tab, t_game game, int P1, int P2);

int		win(int **tab, t_game game, int P1, int P2);
int		win_line(int **tab, t_game game, int P1, int P2);
int		win_col(int **tab, t_game game, int P1, int P2);
int		check_marks(int **tab, t_game game, int P1, int P2);
int		eval(int **tab, t_game game);

#endif /* !MINIMAX_H */
