/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:02:38 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/05 22:34:35 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_func(int *first, int *second, int *third)
{
	write(1, first, 4);
	write(1, second, 4);
	write(1, third, 4);
}

void	ft_print_comb(void)
{
	int	first;
	int	second;
	int	third;

	first = '0';
	while (first <= '7')
	{
		second = first + 1;
		while (second > first && second <= '8')
		{
			third = second + 1;
			while (third > second && third <= '9')
			{
				ft_write_func(&first, &second, &third);
				if (first != '7')
				{
					write(1, ",", 1);
					write(1, " ", 1);
				}
				++third;
			}
			++second;
		}
		++first;
	}
}
