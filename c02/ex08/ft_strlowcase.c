/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 14:43:43 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/07 15:02:36 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_upper_letter(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (ft_is_upper_letter(*(str + i)))
			*(str + i) += 32;
		++i;
	}
	return (str);
}
