/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:48:05 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/11 13:53:18 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		write(1, &s[i++], 1);
	write(1, "\n", 1);
}

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

void	ft_sort(char **arr, int size)
{
	int		i;
	int		flag;
	char	*swap;

	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 1;
		while (i < size - 1)
		{
			if (ft_strcmp(arr[i], arr[i + 1]) > 0)
			{
				swap = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = swap;
				flag = 1;
			}
			++i;
		}
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	ft_sort(argv, argc);
	while (i < argc)
		ft_putstr(argv[i++]);
	return (0);
}
