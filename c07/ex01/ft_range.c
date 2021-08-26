/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 10:19:37 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/12 20:03:08 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	size;
	int	*res;

	if (min >= max)
		return (NULL);
	size = max - min;
	i = 0;
	res = (int *)malloc(size * sizeof(int));
	if (res == NULL)
		return (NULL);
	while (i < size)
		res[i++] = min++;
	return (res);
}
