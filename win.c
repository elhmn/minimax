/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 05:04:14 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/08 13:26:53 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab_tools.h"
#include "minimax.h"
#include "puissance4.h"
#include <unistd.h>
#include <stdio.h>

void	congrat(int who)
{
	printf("\n\n****************** CONGRATULATION *******************");
		if (who == 1)
			printf("\n**************** PLAYER 1 WIN ****************\n");
		else
			printf("\n**************** PLAYER 2 WIN ****************\n");
//		ft_display_tab(data);
}
/*
int		win(int **tab, t_data data)
{
	int		who;

	if ((who = win_col(tab, data)))
		congrat(who);
	else if ((who = win_line(tab, data)))
		congrat(who);
	else if ((who = win_diag(tab, data)))
		congrat(who);
	return (who);
}
*/

int		win_col(int **tab, t_data data)
{
	int		i;
	int		j;
	int		k;
	int		win1;
	int		win2;

	i = 0;
	while (i < data.col)
	{
		j = 0;
		while (j + 3 < data.line)
		{
			k = j;
			win2 = 0;
			win1 = 0;
			while (k < j + 4 && k < data.line)
			{
				tab[k][i] = 1;
				print_tab(tab, LINE, COL);
				usleep(PAUSE);
				/*
				if (tab[k][i] == 1)
					win1++;
				else if (tab[k][i] == 2)
					win2++;
				*/
				k++;
			}
			init_tab(tab, LINE, COL);
				usleep(PAUSE);
			if (win2 == 4)
				return (2);
			if (win1 == 4)
				return (1);
			j++;
	//		printf("********************* DEBUG *****************\n");
	//		printf("i = [ %d ] \n j = [ %d ] \n who = [ %d ]\n win = [ %d ]\n", i, j, who, win);
		}
		i++;
	}
	return (0);
}

int		win_line(int **tab, t_data data)
{
	int		i;
	int		j;
	int		k;
	int		win2;
	int		win1;

	i = 0;
	while (i < data.line)
	{
		j = 0;
		while (j + 3 < data.col)
		{
			k = j;
			win1 = 0;
			win2 = 0;
			while (k < j + 4 && k < data.col)
			{
				tab[i][k] = 2;
				print_tab(tab, LINE, COL);
				usleep(PAUSE);
				/*
				if (tab[i][k] == 1)
					win1++;
				else if (tab[i][k] == 2)
					win2++;
				*/
				k++;
			}
			init_tab(tab, LINE, COL);
				usleep(PAUSE);
//			printf("********************* DEBUG *****************\n");
//			printf("i = [ %d ] \n k = [ %d ] \n win1 = [ %d ]\n win2 = [ %d ]\n", i, k, win1, win2);
			if (win1 == 4)
				return (1);
			if (win2 == 4)
				return (2);
			j++;
			}
		i++;
	}
	return (0);
}
