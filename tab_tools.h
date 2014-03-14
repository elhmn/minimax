/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 16:28:53 by elhmn             #+#    #+#             */
/*   Updated: 2014/03/10 16:28:53 by elhmn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAB_TOOLS_H
# define TAB_TOOLS_H
# define LINE	10
# define COL	15
# define DEPHT	5

int		**copy_tab(int **tab, int line, int col);
void	print_tab(int **tab, int line, int col);
void	print_piece(int	piece);
void	init_tab(int **tab, int line, int col);
int		**create_tab(int **tab, int line, int col);

#endif /* !TAB_TOOLS_H */
