/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:43:59 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/05 15:21:47 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	int	start;
	int	finish;

	start = 'z';
	finish = 'a';
	while (start > finish - 1)
	{
		write(1, &start, 4);
		--start;
	}
}
