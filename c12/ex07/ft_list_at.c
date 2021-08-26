/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:42:59 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/19 21:20:28 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*tmp;
	unsigned int	i;

	i = 0;
	tmp = begin_list;
	while (i != nbr && tmp != NULL)
	{
		tmp = tmp->next;
		++i;
	}
	if (i == nbr)
		return (tmp);
	return (NULL);
}
