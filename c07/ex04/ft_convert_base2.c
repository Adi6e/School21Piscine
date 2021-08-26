/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 23:23:58 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/13 23:40:59 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *n, char *s);
int	ft_strlen(char *s);

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
			|| !(base[i] > 32 && base[i] <= 126))
			return (0);
		++i;
	}
	return (1);
}

char	*ft_copy(char *res, char *num, int cnt, int i)
{
	res = (char *) malloc((cnt + i + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[cnt + i] = '\0';
	if (i == -2)
	{
		*res = num[0];
		return (res);
	}
	if (i == 1)
	{
		i = 0;
		res[i++] = '-';
	}
	while (cnt-- >= 0)
		res[i++] = num[cnt];
	return (res);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int			cnt;
	int			i;
	char		num[32];
	char		*res;

	if (!ft_checkbase(base))
		return (NULL);
	i = 0;
	res = NULL;
	if (nbr == 0)
		return (ft_copy(res, base, 3, -2));
	if (nbr < 0)
	{
		i = 1;
		nbr *= -1;
	}
	cnt = 0;
	while (nbr)
	{
		num[cnt++] = base[nbr % ft_strlen(base)];
		nbr /= ft_strlen(base);
	}
	res = ft_copy(res, num, cnt, i);
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;
	char	*str;

	if (!ft_checkbase(base_from))
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	str = ft_putnbr_base(n, base_to);
	return (str);
}
