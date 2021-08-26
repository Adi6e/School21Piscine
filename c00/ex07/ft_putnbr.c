/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 22:06:57 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/05 22:37:07 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_check_num(int *num)
{
	if (*num == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (*num < 0)
	{
		write(1, "-", 1);
		*num = *num * (-1);
	}
	if (*num == -2147483648)
	{
		write(1, "2147483648", 10);
		return ;
	}
}

int	ft_count_digits(int num)
{
	int	cnt;

	cnt = 1;
	while (num / 10)
	{
		num /= 10;
		++cnt;
	}
	return (cnt);
}

void	ft_putchar(int num)
{
	write(1, &num, 4);
}

void	ft_putnbr(int nb)
{
	int	digit;
	int	count;
	int	tmp_cnt;
	int	factor;

	ft_check_num(&nb);
	count = ft_count_digits(nb);
	while (count && nb != 0 && nb != -2147483648)
	{
		factor = 1;
		tmp_cnt = count;
		while (tmp_cnt - 1)
		{
			factor *= 10;
			--tmp_cnt;
		}
		digit = (nb / factor) + '0';
		ft_putchar(digit);
		nb %= factor;
		--count;
	}
	write(1, "\n", 1);
}
