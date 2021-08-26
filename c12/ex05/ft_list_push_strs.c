/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 21:57:45 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/18 21:57:47 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*temp;

	if (*begin_list == NULL)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	temp = *begin_list;
	*begin_list = ft_create_elem(data);
	(*begin_list)->next = temp;
}

t_list	*ft_list_push_strs(int size, char	**strs)
{
	t_list	*res;
	int		i;

	if (size == 0)
		return (NULL);
	res = ft_create_elem(strs[0]);
	i = 1;
	while (i < size)
		ft_list_push_front(&res, strs[i++]);
	return (res);
}
