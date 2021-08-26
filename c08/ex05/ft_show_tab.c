/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:57:01 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/14 23:32:31 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		write(1, &s[i++], 1);
	write(1, "\n", 1);
}

int	ft_count_digits(int n)
{
	int	cnt;

	cnt = 0;
	while (n)
	{
		++cnt;
		n /= 10;
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

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].size != 0)
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		ft_putstr(par[i].copy);
		++i;
	}
}
