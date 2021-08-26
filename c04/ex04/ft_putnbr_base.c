/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:58:29 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/10 20:00:53 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

int	ft_checkunique(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

int	ft_checkbase(char *base)
{
	int	i;

	i = 0;
	if (ft_strlen(base) == 0
		|| ft_strlen(base) == 1)
		return (0);
	if (!ft_checkunique(base))
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-'
			|| !(base[i] >= 32 && base[i] <= 126))
			return (0);
		++i;
	}
	return (1);
}

void	ft_checknum(long long *nbr, char *base)
{
	if (*nbr < 0)
	{	
		write(1, "-", 1);
		*nbr = *nbr * (-1);
	}
	if (*nbr == 0)
	{
		write(1, &base[0], 1);
	}
	return ;
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			cnt;
	int			base_size;
	char		num[32];
	long long	ll_nbr;

	ll_nbr = nbr;
	if (!ft_checkbase(base))
		return ;
	ft_checknum(&ll_nbr, base);
	base_size = ft_strlen(base);
	cnt = 0;
	while (ll_nbr)
	{
		num[cnt++] = base[ll_nbr % base_size];
		ll_nbr /= base_size;
	}
	while (cnt > 0)
	{
		write(1, &num[cnt - 1], 1);
		--cnt;
	}
}
