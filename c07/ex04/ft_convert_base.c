/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 20:40:10 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/13 23:37:43 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_checkunique(char *base);
int	ft_checkbase(char *base);

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

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

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	flag;
	int	res;
	int	j;

	if (!ft_checkbase(base))
		return (0);
	i = 0;
	flag = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		++i;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			flag *= -1;
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
