/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:15:17 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/09 21:58:27 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n'
		|| c == '\f' || c == '\r'
		|| c == ' ' || c == '\v');
}

int	ft_isminus(char c)
{
	return (c == '-');
}

int	ft_isplus(char c)
{
	return (c == '+');
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	int	i;
	int	have_minus;
	int	num;

	i = 0;
	have_minus = 1;
	num = 0;
	while (ft_isspace(str[i]))
		++i;
	while (ft_isplus(str[i]) || ft_isminus(str[i]))
	{
		if (ft_isminus(str[i]))
			have_minus *= -1;
		++i;
	}
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		++i;
	}
	num *= have_minus;
	return (num);
}
