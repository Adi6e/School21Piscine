/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:33:45 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/20 23:36:51 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
int (*cmpf)(void *, void *))
{
	void	*res;

	res = (void *) 0;
	if (root == (void *) 0)
		return (res);
	if ((*cmpf)(root->item, data_ref) > 0)
		res = btree_search_item(root->left, data_ref, cmpf);
	if (res)
		return (res);
	else if (!(*cmpf)(root->item, data_ref))
		return (root->item);
	else if ((*cmpf)(root->item, data_ref) < 0)
		res = btree_search_item(root->right, data_ref, cmpf);
	return (res);
}
