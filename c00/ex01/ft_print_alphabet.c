/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:14:03 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/04 18:14:14 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	int	start;
	int	finish;

	start = 'a';
	finish = 'z';
	while (start != finish + 1)
	{
		write(1, &start, 4);
		++start;
	}
}
