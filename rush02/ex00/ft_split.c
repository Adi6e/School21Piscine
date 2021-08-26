/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:31:24 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/21 19:33:49 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_in_set(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
		if (c == charset[i++])
			return (1);
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i] != '\0' && !ft_is_in_set(str[i++], charset))
			++j;
		if (j > 0)
			++count;
	}
	return (count);
}

char	*ft_cpy(char *str, int i, int cnt)
{
	int		j;
	char	*res;

	res = (char *)malloc((cnt + 1) * sizeof(char));
	if (res == NULL)
		res = NULL;
	res[cnt] = '\0';
	j = 0;
	while (j < cnt)
	{
		res[j] = str[i - cnt + j];
		++j;
	}
	return (res);
}

char	**ft_split(char *str, char *charset, int *count)
{
	char	**res;
	int		i;
	int		cnt;
	int		j;

	*count = ft_count_words(str, charset);
	res = (char **)malloc((ft_count_words(str, charset) + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	res[ft_count_words(str, charset)] = 0;
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		cnt = 0;
		while (str[i] != '\0' && !ft_is_in_set(str[i], charset))
		{
			++cnt;
			++i;
		}
		if (cnt > 0)
			res[j++] = ft_cpy(str, i, cnt);
		++i;
	}
	return (res);
}
