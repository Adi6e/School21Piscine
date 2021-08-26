/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:42:20 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/19 17:30:43 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin, void (*free_fct)(void *))
{
	t_list	*temp;

	temp = NULL;
	while (begin != NULL)
	{
		temp = begin->next;
		(*free_fct)(begin->data);
		free (begin);
		begin = temp;
	}
}
