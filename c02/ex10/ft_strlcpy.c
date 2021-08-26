/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 21:06:11 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/07 22:16:11 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_size;

	src_size = 0;
	while (*(src + src_size) != '\0')
	{
		++src_size;
	}
	if (size == 0)
	{
		return (src_size);
	}
	i = 0;
	while (i < size && *(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		++i;
	}
	if (i < size)
		*(dest + i) = '\0';
	else
		*(dest + size - 1) = '\0';
	return (src_size);
}
