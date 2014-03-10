/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 14:31:29 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/09 18:35:43 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		check_diag(int **tab, int line, int col, int P1, int P2);
int		check_col(int **tab, int line, int col, int P1, int P2);
int		check_line(int **tab, int line, int col, int P1, int P2);
int		check_marks(int **tab, int line, int col, int P1, int P2);

int		eval(int	**tab, int line, int col)
{
	int		mark;
	
	mark = 0;
	if (check_marks(tab, line, col, 4, 0))
		mark = 1000;
	else if (check_marks(tab, line, col, 3, 1))
		mark = 100;
	else if (check_marks(tab, line, col, 2, 2))
		mark = 10;
	else if (check_marks(tab, line, col, 1, 3))
		mark = 1;
	if (check_marks(tab, line, col, 0, 4))
		mark = -1000;
	else if (check_marks(tab, line, col, 1, 3))
		mark = -100;
	else if (check_marks(tab, line, col, 2, 2))
		mark = -10;
	else if (check_marks(tab, line, col, 3, 1))
		mark = -1;
	return (mark);
}

int		check_marks(int **tab, int line, int col, int P1, int P2)
{
	if (check_line(tab, line, col, P1, P2))
		return (1);
	else if (check_col(tab, line, col, P1, P2))
		return (1);
	else if (check_diag(tab, line, col, P1, P2))
		return (1);
	return (0);
}


int		check_col(int **tab, int line, int col, int P1, int P2)
{
	int		i;
	int		j;
	int		J1;
	int		J2;

	i = 0;
	while (i < line)
	{
		j = 0;
		while (j < col)
		{
			J1 = 0;
			J2 = 0;
			while (j < line && tab[i][j] == 1 && J1 != P1)
			{
				J1++;
				j++;
			}
			while (j < line && tab[i][j] == 2 && J2 != P2)
			{
				J2++;
				j++;
			}
			j++;
			if (J1 == P1 && J2 == P2)
				return (1);
		}
		i++;
	}
	//	printf("********************* DEBUG *****************\n");
	//	printf("i = [ %d ] \n j = [ %d ] \n J1 = [ %d ]\n J2 = [ %d ]\n", i, j, J1, J2);
	return (0);
}

int		check_line(int **tab, int line, int col, int P1, int P2)
{
	int		i;
	int		j;
	int		J1;
	int		J2;

	i = 0;
	while (i < line)
	{
		j = 0;
		while (j < col)
		{
			J1 = 0;
			J2 = 0;
			while (j < line && tab[j][i] == 1 && J1 != P1)
			{
				J1++;
				j++;
			}
			while (j < line && tab[j][i] == 2 && J2 != P2)
			{
				J2++;
				j++;
			}
			j++;
			if (J1 == P1 && J2 == P2)
				return (1);
		}
		i++;
	}
	//	printf("********************* DEBUG *****************\n");
	//	printf("i = [ %d ] \n j = [ %d ] \n J1 = [ %d ]\n J2 = [ %d ]\n", i, j, J1, J2);
	return (0);
}

// L'algo consiste a lancer des rayons en partant des deux colones extremes de la map.

int		check_diag(int **tab, int line, int col, int P1, int P2)
{
	int		i;
	int		j;
	int		k;
	int		J1;
	int		J2;

	// Lancer de rayons a partir de la gauche
	 i = 0;
	 while (i < line)
	 {
		k = i;
		j = 0;
		//vers le bas
		while (k < line && j < col)
		{
			J1 = 0;
			J2 = 0;
			while (k < line && j < col && tab[k][j] == 2 && J2 != P2)
			{
				J2++;
				j++;
				k++;
			}
			while (k < line && j < col && tab[k][j] == 1 && J1 != P1)
			{
				J1++;
				j++;
				k++;
			}
			if (J1 == P1 && J2 == P2)
				return (1);
			j++;
			k++;
		}
		//vers le haut
		k = i;
		j = 0;
		while (k >= 0 && j < col)
		{	
			J1 = 0;
			J2 = 0;
			while (k >= 0 && j < col && tab[k][j] == 2 && J2 != P2)
			{
				J2++;
				j++;
				k--;
			}
			while (k >= 0 && j < col && tab[k][j] == 1 && J1 != P1)
			{
				J1++;
				j++;
				k--;
			}
			if (J1 == P1 && J2 == P2)
				return (1);
			j++;
			k--;
		}
		i++;
	 }
	// Lancer de rayon a partir de la droite
	 i = 0;
	 j = col - 1;
	 while (i < line)
	 {
		k = i;
	 	j = col - 1;
		//vers le bas
		while (k < line && j >= 0)
		{
			J1 = 0;
			J2 = 0;
			while (k < line && j >= 0 && tab[k][j] == 2 && J2 != P2)
			{
				J2++;
				j--;
				k++;
			}
			while (k < line && j >= 0 && tab[k][j] == 1 && J1 != P1)
			{
				J1++;
				j--;
				k++;
			}
			if (J1 == P1 && J2 == P2)
				return (1);
			j--;
			k++;
		}
		//vers le haut
		k = i;
	 	j = col - 1;
		while (k >= 0 && j >= 0)
		{
			J1 = 0;
			J2 = 0;
			while (k >= 0 && j >= 0 && tab[k][j] == 2 && J2 != P2)
			{
				J2++;
				j--;
				k--;
			}
			while (k >= 0 && j >= 0 && tab[k][j] == 1 && J1 != P1)
			{
				J1++;
				j--;
				k--;
			}
			if (J1 == P1 && J2 == P2)
				return (1);
			j--;
			k--;
	//	printf("********************* DEBUG *****************\n");
	//	printf("i = [ %d ] \n j = [ %d ] \n k = [ %d ] \n J1 = [ %d ]\n J2 = [ %d ]\n", i, j, k, J1, J2);
		}
		i++;
	 }
	return (0);
}
