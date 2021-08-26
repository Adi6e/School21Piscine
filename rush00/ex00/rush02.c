/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 17:30:53 by crendeha          #+#    #+#             */
/*   Updated: 2021/08/07 17:30:54 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print__corner_borders(int row, int y)
{
	if (row == 0)
	{
		ft_putchar('A');
	}
	else if (row == y - 1)
	{
		ft_putchar('C');
	}
	else
	{
		ft_putchar('B');
	}
}

void	print__middle(int row, int y)
{
	if (row == 0 || row == y - 1)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int		row;
	int		col;

	if (x <= 0 || y <= 0)
	{
		return ;
	}
	row = 0;
	while (row < y)
	{
		print__corner_borders(row, y);
		col = 1;
		while (col < x - 1)
		{
			print__middle(row, y);
			col++;
		}
		if (x != 1)
		{
			print__corner_borders(row, y);
		}
		ft_putchar('\n');
		row++;
	}
}
