/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:21:59 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/19 21:21:46 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;

	if (begin_list == NULL)
		return (NULL);
	tmp = begin_list;
	while (tmp != NULL)
	{
		if (!(*cmp)(tmp->data, data_ref))
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}
