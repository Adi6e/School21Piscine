/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 22:17:50 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/07 22:17:53 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

void	ft_decimal_to_hex(char c)
{
	char	div;
	char	mod;

	div = c / 16 + '0';
	mod = c % 16;
	write(1, &div, 1);
	if (mod < 10)
	{
		mod += '0';
		write(1, &mod, 1);
	}
	else
	{
		mod += 87;
		write(1, &mod, 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (!ft_is_printable(*(str + i)))
		{
			write(1, "\\", 1);
			ft_decimal_to_hex(*(str + i));
		}
		else
		{
			write(1, &(*(str + i)), 1);
		}
		++i;
	}
}
