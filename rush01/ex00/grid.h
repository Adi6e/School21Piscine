/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leantoni <leantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 10:46:52 by leantoni          #+#    #+#             */
/*   Updated: 2021/08/15 14:09:12 by leantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H
# define SIZE 4

typedef struct s_params
{
	char	up[SIZE];
	char	down[SIZE];
	char	left[SIZE];
	char	right[SIZE];
}	t_params;
int	arg_is_exist(char *av, t_params *params);
int	possible(char grid[SIZE][SIZE], t_params *params);
int	search_empty_case(char grid[SIZE][SIZE], int *x, int *y);
int	can_put_value(char grid[SIZE][SIZE], int x, int y, int value);
int	line_is_exist(char grid[SIZE][SIZE], t_params *params, int y);
int	column_is_exist(char grid[SIZE][SIZE], t_params *params, int x);
int	calculate_views(char grid[SIZE][SIZE], int pos);
int	write_grid(char grid[SIZE][SIZE]);

#endif