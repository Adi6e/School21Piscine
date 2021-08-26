/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 12:56:31 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/18 12:56:33 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*head;

	head = (t_list *)malloc(1 * sizeof(t_list));
	if (head == NULL)
		return (NULL);
	head->next = NULL;
	head->data = data;
	return (head);
}
