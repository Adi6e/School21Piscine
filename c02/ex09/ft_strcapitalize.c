/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:47:58 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/07 16:49:00 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_letter_numeric(char c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		while (!ft_is_letter_numeric(*(str + i)))
		{
			++i;
			continue ;
		}
		if (!ft_is_letter_numeric(*(str + i - 1)))
		{
			if (*(str + i) >= 'a' && *(str + i) <= 'z')
				*(str + i) -= 32;
		}
		else if (*(str + i) >= 'A' && *(str + i) <= 'Z')
			*(str + i) += 32;
		++i;
	}
	return (str);
}
