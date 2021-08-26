/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 20:44:54 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/08 20:44:56 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	i;
	int	src_size;

	src_size = 0;
	while (src[src_size] != '\0')
		++src_size;
	i = 0;
	while (i < (size - src_size - 1) && src[i] != '\0')
	{
		dest[size + i] = src[i];
		++i;
	}
	dest[size + i] = '\0';
	return (size + src_size);
}
