/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:48:09 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/19 20:23:17 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*prev;
	t_list	*next;
	t_list	*curr;

	prev = NULL;
	next = NULL;
	curr = *begin_list;
	while (curr != NULL)
	{
		next = curr->next;
		if (!(*cmp)(curr->data, data_ref))
		{
			if (prev == NULL)
				*begin_list = (*begin_list)->next;
			else
			{
				prev->next = next;
			}
			(*free_fct)(curr->data);
			free(curr);
		}
		else
			prev = curr;
		curr = next;
	}
}
