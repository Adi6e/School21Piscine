/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 19:36:37 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/04 19:36:44 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	int	start;
	int	finish;

	start = '0';
	finish = '9';
	while (start != finish + 1)
	{
		write(1, &start, 4);
		++start;
	}
}
