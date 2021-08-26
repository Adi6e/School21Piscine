/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 20:53:29 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/05 22:48:05 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int num)
{
	num += '0';
	write(1, &num, 4);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a < 99)
	{
		b = a + 1;
		while (b > a && b <= 99)
		{
			ft_putchar(a / 10);
			ft_putchar(a % 10);
			write(1, " ", 1);
			ft_putchar(b / 10);
			ft_putchar(b % 10);
			if (!(a == 98 && b == 99))
			{
				write(1, ",", 1);
				write(1, " ", 1);
			}
			++b;
		}
		++a;
	}
}
