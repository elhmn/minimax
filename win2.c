/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 07:20:34 by elhmn             #+#    #+#             */
/*   Updated: 2014/03/14 07:20:34 by elhmn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab_tools.h"
#include "minimax.h"
#include "puissance4.h"
#include <unistd.h>
#include <stdio.h>

int		win_diag1(int **tab, t_data data)
{
	int		i;
	int		j;
	int		k;
	int		l;
	int		m;
	int		win1;
	int		win2;

	i = 0;
	while (i < data.line)
	{
		m = i;
		j = 0;
		while (j + 3 < data.col && m + 3 < data.line)
		{
			k = j;
			l = m;
			win1 = 0;
			win2 = 0;
			while (k < j + 4 && l < m + 4)
			{
				tab[l][k] = 1;
				print_tab(tab, LINE, COL);
				usleep(PAUSE);
				/*
				if (tab[l][k] == 1)
					win1++;
				else if (tab[l][k] == 2)
					win2++;
				*/
				k++;
				l++;
			}
			init_tab(tab, LINE, COL);
			print_tab(tab, LINE, COL);
			usleep(PAUSE);
			if (win2 == 4)
				return (2);
			if (win1 == 4)
				return (1);
			j++;
			m++;
		}
		i++;
	}
	return (0);
}

int		win_diag2(int **tab, t_data data)
{
	int		i;
	int		j;
	int		k;
	int		l;
	int		m;
	int		win1;
	int		win2;

	i = data.line - 1;
	while (i >= 0)
	{
		j = 0;
		m = i;
		while (j + 3 < data.col && m >= 3)
		{
			k = j;
			l = m;
			win1 = 0;
			win2 = 0;
			while (k < j + 4 && l >= m - 3)
			{
				tab[l][k] = 2;
				print_tab(tab, LINE, COL);
				usleep(PAUSE);
				/*
				if (tab[l][k] == 1)
					win1++;
				else if (tab[l][k] == 2)
					win2++;
				*/
				k++;
				l--;
			}
			init_tab(tab, LINE, COL);
			print_tab(tab, LINE, COL);
			usleep(PAUSE);
			if (win2 == 4)
				return (2);
			if (win1 == 4)
				return (1);
			j++;
			m--;
		}
		i--;
	}
	return (0);
}

int		win_diag3(int **tab, t_data data)
{
	int		i;
	int		j;
	int		k;
	int		l;
	int		m;
	int		win1;
	int		win2;

	i = 0;
	while (i < data.line)
	{
		m = i;
		j = data.col - 1;
		while (j >= 3 && m + 3 < data.line)
		{
			k = j;
			l = m;
			win1 = 0;
			win2 = 0;
			while (k + 3 >= j && l < m + 4)
			{
				tab[l][k] = 1;
				print_tab(tab, LINE, COL);
				usleep(PAUSE);
				/*
				if (tab[l][k] == 1)
					win1++;
				else if (tab[l][k] == 2)
					win2++;
				*/
				k--;
				l++;
			}
			print_tab(tab, LINE, COL);
			init_tab(tab, LINE, COL);
			usleep(PAUSE);
			if (win2 == 4)
				return (2);
			if (win1 == 4)
				return (1);
			j--;
			m++;
		}
		i++;
	}
	return (0);
}

int		win_diag4(int **tab, t_data data)
{
	int		i;
	int		j;
	int		k;
	int		l;
	int		m;
	int		win1;
	int		win2;

	i = data.line - 1;
	while (i >= 0)
	{
		m = i;
		j = data.col - 1;
		while (j >= 3 && m >= 3)
		{
			k = j;
			l = m;
			win1 = 0;
			win2 = 0;
			while (k + 3 >= j && l + 3 >= m)
			{
				tab[l][k] = 2;
				print_tab(tab, LINE, COL);
				usleep(PAUSE);
				/*
				if (tab[l][k] == 1)
					win1++;
				else if (tab[l][k] == 2)
					win2++;
				*/
				k--;
				l--;
				
			}
			init_tab(tab, LINE, COL);
			print_tab(tab, LINE, COL);
			usleep(PAUSE);
			if (win2 == 4)
				return (2);
			if (win1 == 4)
				return (1);
			j--;
			m--;
		}
		i--;
	}
	return (0);
}
