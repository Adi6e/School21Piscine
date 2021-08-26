/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fanction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leantoni <leantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 06:18:22 by leantoni          #+#    #+#             */
/*   Updated: 2021/08/15 14:09:05 by leantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "grid.h"

int	column_is_exist(char grid[SIZE][SIZE], t_params *params, int x)
{
	int	arr[3];

	arr[1] = 0;
	arr[2] = 0;
	arr[0] = -1;
	while (++arr[0] < SIZE)
	{
		arr[2] += grid[arr[0]][x] > arr[1];
		if (grid[arr[0]][x] > arr[1])
			arr[1] = grid[arr[0]][x];
	}
	if (arr[2] != params->up[x])
		return (0);
	return (1);
}

int	line_is_exist(char grid[SIZE][SIZE], t_params *params, int y)
{
	int	arr[3];

	arr[1] = 0;
	arr[2] = 0;
	arr[0] = -1;
	while (++arr[0] < SIZE)
	{
		arr[2] += grid[y][arr[0]] > arr[1];
		if (grid[y][arr[0]] > arr[1])
			arr[1] = grid[y][arr[0]];
	}
	if (arr[2] != params->left[y])
		return (0);
	arr[1] = 0;
	arr[2] = 0;
	while (--arr[0] >= 0)
	{
		arr[2] += grid[y][arr[0]] > arr[1];
		if (grid[y][arr[0]] > arr[1])
			arr[1] = grid[y][arr[0]];
	}
	if (arr[2] != params->right[y])
		return (0);
	return (1);
}

int	can_put_value(char grid[SIZE][SIZE], int x, int y, int value)
{
	int	i;

	i = -1;
	while (++i < SIZE)
		if (grid[y][i] == value || grid[i][x] == value)
			return (0);
	return (1);
}

int	search_empty_case(char grid[SIZE][SIZE], int *x, int *y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
		{
			if (grid[i][j] == 0)
			{
				*x = j;
				*y = i;
				return (1);
			}
		}
	}
	return (0);
}
