/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 14:28:22 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/07 14:41:32 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_low_letter(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (ft_is_low_letter(*(str + i)))
			*(str + i) -= 32;
		++i;
	}
	return (str);
}
