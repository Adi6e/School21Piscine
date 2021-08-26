/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:36:33 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/18 13:33:20 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_check_num(long long *num)
{
	if (*num < 0)
	{
		write(1, "-", 1);
		*num = *num * (-1);
	}
}

int	ft_count_digits(long long num)
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

long long	ft_count_factor(int count)
{
	long long	factor;

	factor = 1;
	while (count != 1)
	{
		factor *= 10;
		--count;
	}
	return (factor);
}

void	ft_putnbr(long long nb)
{
	char			digit;
	int				count;
	long long		factor;

	ft_check_num(&nb);
	count = ft_count_digits(nb);
	factor = ft_count_factor(count);
	while (count)
	{
		digit = (nb / factor) + '0';
		write(1, &digit, 1);
		nb %= factor;
		factor /= 10;
		--count;
	}
	write(1, "\n", 1);
}
