/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:32:56 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/11 18:32:58 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_check(int col, int *rows)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (rows[i] == rows[col])
			return (0);
		if (ft_abs(rows[i] - rows[col]) == ft_abs(i - col))
			return (0);
		++i;
	}
	return (1);
}

void	ft_print(int *arr)
{
	int		i;
	char	digit;

	i = 0;
	while (i < 10)
	{
		digit = arr[i] + '0';
		write(1, &digit, 1);
		++i;
	}
	write(1, "\n", 1);
}

void	ft_count(int n, int *rows, int *count)
{
	rows[n] = 0;
	while (rows[n] < 10)
	{
		if (ft_check(n, rows))
		{
			if (n == 9)
			{
				ft_print(rows);
				++*count;
			}
			else
				ft_count(n + 1, rows, count);
		}
		++rows[n];
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	rows[10];
	int	count;

	count = 0;
	ft_count(0, rows, &count);
	return (count);
}
