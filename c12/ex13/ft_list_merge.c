/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:43:38 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/19 21:22:12 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*head;

	head = *begin_list1;
	if (head == NULL)
	{
		head = begin_list2;
		return ;
	}
	while (head->next != NULL)
		head = head->next;
	head->next = begin_list2;
}
