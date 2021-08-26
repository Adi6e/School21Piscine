/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:16:17 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/19 21:21:27 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)())
{
	t_list	*tmp;

	if (begin_list == NULL)
		return ;
	tmp = begin_list;
	while (tmp != NULL)
	{
		if (!(*cmp)(tmp->data, data_ref))
			(*f)(tmp->data);
		tmp = tmp->next;
	}
}
