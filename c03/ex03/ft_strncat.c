/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 19:41:09 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/08 19:41:11 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	dest_size;

	dest_size = 0;
	while (dest[dest_size] != '\0')
		++dest_size;
	i = 0;
	while (i < nb && src[i] != '\0')
	{
		dest[dest_size + i] = src[i];
		++i;
	}
	dest[dest_size + i] = '\0';
	return (dest);
}
