/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:51:00 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/19 21:19:17 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*tmp;

	if (begin_list == NULL)
		return (NULL);
	tmp = begin_list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
