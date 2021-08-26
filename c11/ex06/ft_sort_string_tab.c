/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 09:29:58 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/18 09:29:59 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			break ;
		++i;
	}
	return (s1[i] - s2[i]);
}

int	ft_arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != (void *) 0)
		++i;
	return (i);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		flag;
	int		size;
	char	*swap;

	size = ft_arr_len(tab);
	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 0;
		while (i < size - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				swap = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = swap;
				flag = 1;
			}
			++i;
		}
	}
}
