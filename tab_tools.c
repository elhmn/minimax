/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 16:27:59 by elhmn             #+#    #+#             */
/*   Updated: 2014/03/10 16:27:59 by elhmn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "tab_tools.h"

int		**copy_tab(int **tab, int line, int col)
{
	int		i;
	int		**new;
	int		j;

	i = 0;
	if (!(new = malloc(sizeof(int*) * line)))
		return (NULL);
	while (i < line)
		if (!(new[i++] = malloc(sizeof(int) * col)))
			return (NULL);
	i = 0;
	if (tab)
	{
		while (i < line)
		{
			j = 0;
			while (j < col)
			{
				new[i][j] = tab[i][j];
				j++;
			}
			i++;
		}
	}
	return (new);
}

int		**create_tab(int **tab, int line, int col)
{
	int		i;
	
	i = 0;
	if (!(tab = malloc(sizeof(int*) * line)))
		return (NULL);
	while (i < line)
		if (!(tab[i++] = malloc(sizeof(int) * col)))
			return (NULL);
	return (tab);
}

void	init_tab(int **tab, int line, int col)
{
	int		i;
	int		j;

	i = 0;
	if (tab)
	{
		while (i < line)
		{
			j = 0;
			while (j < col)
				tab[i][j++] = 0;
			i++;
		}
	}
}

void	print_piece(int	piece)
{
	if (piece == 0)
		printf(" . |");
	else if (piece == 1)
		printf(" X |");
	else
		printf(" O |");
}

void	print_tab(int **tab, int line, int col)
{
	int		i;
	int		j;

	i = 0;
	if (tab)
	{
		while (i < line)
		{
			j = 0;
			while (j < col)
			{
				print_piece(tab[i][j++]);
			}
			printf("\n\n");
			i++;
		}
	}
	printf("\n****************************\n\n");
}
