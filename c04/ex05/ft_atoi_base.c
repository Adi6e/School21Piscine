/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 21:53:22 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/26 12:51:36 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_inbase(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (1);
		++i;
	}
	return (0);
}

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
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
			|| !(base[i] > 32 && base[i] <= 126))
			return (0);
		++i;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	flag;
	int	res;
	int	j;

	i = 0;
	flag = 1;
	if (!ft_checkbase(base))
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		++i;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			flag *= -1;
	}
	res = 0;
	while (ft_is_inbase(str[i], base))
	{
		j = 0;
		while (str[i] != base[j])
			++j;
		res = res * ft_strlen(base) + j;
		++i;
	}
	res *= flag;
	return (res);
}
