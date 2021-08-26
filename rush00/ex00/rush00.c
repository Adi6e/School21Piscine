/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 19:04:12 by latahbah          #+#    #+#             */
/*   Updated: 2021/08/08 19:04:14 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print__corner_borders(int row, int y)
{
	if (row == 0)
	{
		ft_putchar('o');
	}
	else if (row == y - 1)
	{
		ft_putchar('o');
	}
	else
	{
		ft_putchar('|');
	}
}

void	print__middle(int row, int y)
{
	if (row == 0 || row == y - 1)
	{
		ft_putchar('-');
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
