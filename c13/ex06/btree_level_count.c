/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:29:40 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/20 21:29:49 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	btree_level_count(t_btree *root)
{
	if (root == (void *) 0)
		return (0);
	return (ft_max(btree_level_count(root->left),
			btree_level_count(root->right)) + 1);
}
