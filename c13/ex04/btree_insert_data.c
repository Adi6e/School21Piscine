/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:06:58 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/20 21:11:30 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
int (*cmpf)(void *, void *))
{
	if (*root == (void *) 0)
	{
		*root = btree_create_node(item);
		return ;
	}
	if ((*cmpf)((*root)->item, item) > 0)
		btree_insert_data(&((*root)->left), item, cmpf);
	if ((*cmpf)((*root)->item, item) <= 0)
		btree_insert_data(&((*root)->right), item, cmpf);
}
