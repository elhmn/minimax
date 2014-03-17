/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 14:31:29 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/15 17:58:22 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minimax.h"
#include <unistd.h>


int		eval(int **tab, t_game game, int col, int who)
{
	int		mark;
	
	mark = 0;
	if (who == MIN)
	{
		if (check_marks(tab, game, 0, 4, col))
			mark = 10000;
		else if (check_marks(tab, game, 3, 1, col))
			mark = 1000;
		else if (check_marks(tab, game, 2, 1, col))
			mark = 100;
		else if (check_marks(tab, game, 4, 0, col))
			mark = -10000;
		else if (check_marks(tab, game, 1, 3, col))
			mark = -1000;
		else if (check_marks(tab, game, 1, 2, col))
			mark = -100;
	}
	else
	{
		if (check_marks(tab, game, 4, 0, col))
			mark = -10000;
		else if (check_marks(tab, game, 1, 3, col))
			mark = -1000;
		else if (check_marks(tab, game, 1, 2, col))
			mark = -100;
		else if (check_marks(tab, game, 0, 4, col))
			mark = 10000;
		else if (check_marks(tab, game, 3, 1, col))
			mark = 1000;
		else if (check_marks(tab, game, 2, 1, col))
			mark = 100;
	}
	return (mark);
}


int		check_marks(int **tab, t_game game, int P1, int P2, int col)
{
	int		i;
	int		m;
	int		win1;
	int		win2;
	int		e;
	int		l;
	int		n;

	e = 0;
	m = 0;
	i = 0;
	while (!tab[i][col] && i < game.line)
		i++;
	m = i;
	win1 = 0;
	win2 = 0;
	while (m < i + 4 && m < game.line)
	{
		//	printf("******DEBUG_LINE*************\n");
		if (tab[m][col] == 1)
			win1++;
		if (tab[m][col] == 2)
			win2++;
		if (win2 == P2 && win1 == P1)
		{
		//	printf("******DEBUG_LINE*************\n");
		//	printf("P1 = %d && P2 = %d \n", P1, P2);
		//	sleep(2);
			return (1);
		}
		m++;
	}
	e = col - 3;
	while (e <= col && e < game.col)
	{
		win1 = 0;
		win2 = 0;
		m = e;
		while (m < e + 4 && m < game.col && m >= 0)
		{
		//		printf("******DEBUG_COL************\n");
			if (tab[i][m] == 1)
				win1++;
			if (tab[i][m] == 2)
				win2++;
			if (win1 == P1 && win2 == P2)
			{
		//		printf("******DEBUG_COL************\n");
		//		printf("P1 = %d && P2 = %d \n", P1, P2);
		//		sleep(2);
				return (1);
			}
			m++;
		}
		e++;
	}

	/*
	** check diag montante
	*/

	m = i + 3;
	e = col - 3;
	while (e <= col && m >= i)
	{
		l = m;
		n = e;
		win1 = 0;
		win2 = 0;
		while (n >= 0 && n < e + 4
				&& n < game.col && l >= 0
				&& l >= m - 3 && l < game.line)
		{
			//	printf("******DEBUG_DIAG_UP************\n");
			if (tab[l][n] == 1)
				win1++;
			if (tab[l][n] == 2)
				win2++;
			if (win1 == P1 && win2 == P2)
			{
			//	printf("******DEBUG_DIAG_UP************\n");
			//	printf("P1 = %d && P2 = %d \n", P1, P2);
				return (1);
			}
			n++;
			l--;
		}
		e++;
		m--;
	}
	
	/*
	** check diag descendante
	*/
	
	m = i - 3;
	e = col - 3;
	while (e <= col && m <= i)
	{
		l = m;
		n = e;
		win1 = 0;
		win2 = 0;
		while (n < e + 4 && n < game.col
				&& n >= 0 && l >= 0 
				&& l < game.line && l < m + 4)
		{
			//	printf("******DEBUG_DIAG_DOWN************\n");
			if (tab[l][n] == 1)
				win1++;
			if (tab[l][n] == 2)
				win2++;
			if (win1 == P1 && win2 == P2)
			{
			//	printf("******DEBUG_DIAG_DOWN************\n");
			//	printf("P1 = %d && P2 = %d \n", P1, P2);
				return (1);
			}
			n++;
			l++;
		}
		e++;
		m++;
	}
	return (0);
}
