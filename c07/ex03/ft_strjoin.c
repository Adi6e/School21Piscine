/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:07:55 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/12 19:24:05 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

char	*ft_strcat(char *dest, char *src, char *sep)
{
	int	dest_size;
	int	src_size;
	int	sep_size;
	int	i;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	sep_size = ft_strlen(sep);
	i = 0;
	while (i < sep_size)
	{
		dest[dest_size + i] = sep[i];
		++i;
	}
	i = 0;
	while (i < src_size)
	{
		dest[dest_size + sep_size + i] = src[i];
		++i;
	}
	dest[dest_size + sep_size + i] = '\0';
	return (dest);
}

char	*ft_malloc(char *s, int n)
{
	s = (char *)malloc(n * sizeof(char));
	if (s == NULL)
		return (NULL);
	*s = '\0';
	return (s);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*res;
	int		res_size;

	res = NULL;
	if (size == 0)
		return (ft_malloc(res, 1));
	i = 0;
	res_size = 0;
	while (i < size)
		res_size += ft_strlen(strs[i++]);
	res_size += (size - 1) * ft_strlen(sep);
	res = ft_malloc(res, res_size + 1);
	i = 0;
	while (i < size)
	{
		if (i == 0)
			res = ft_strcat(res, strs[i++], "\0");
		else
			res = ft_strcat(res, strs[i++], sep);
	}
	return (res);
}
