/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:05:10 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/14 23:28:09 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		size;
	int		i;
	char	*res;

	size = ft_strlen(s);
	res = (char *)malloc((size + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = s[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}

void	ft_struct_init(t_stock_str *st, int size, char *str)
{
	st->size = size;
	st->str = str;
	if (str == NULL)
		st->copy = NULL;
	else
		st->copy = ft_strdup(str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **v)
{
	int			i;
	t_stock_str	*res;

	if (ac < 0)
		return (NULL);
	res = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (res == NULL)
		return (NULL);
	ft_struct_init(res + ac, 0, NULL);
	i = 0;
	while (i < ac)
	{
		ft_struct_init(res + i, ft_strlen(v[i]), v[i]);
		++i;
	}
	return (res);
}
