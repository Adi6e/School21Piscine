/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:41:10 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/17 12:48:38 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int(*f)(char *))
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (i < length)
		if ((*f)(tab[i++]))
			++cnt;
	return (cnt);
}
