/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 19:40:11 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/08 19:40:13 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_size;

	dest_size = 0;
	while (dest[dest_size] != '\0')
		++dest_size;
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_size + i] = src[i];
		++i;
	}
	dest[dest_size + i] = '\0';
	return (dest);
}
