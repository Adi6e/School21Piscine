/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 22:06:57 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/10 20:00:38 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_check_num(int *num)
{
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

int	ft_count_factor(int count)
{
	int	factor;

	factor = 1;
	while (count != 1)
	{
		factor *= 10;
		--count;
	}
	return (factor);
}

void	ft_putnbr(int nb)
{
	char	digit;
	int		count;
	int		factor;

	ft_check_num(&nb);
	count = ft_count_digits(nb);
	factor = ft_count_factor(count);
	while (count && nb != -2147483648)
	{
		digit = (nb / factor) + '0';
		write(1, &digit, 1);
		nb %= factor;
		factor /= 10;
		--count;
	}
}
