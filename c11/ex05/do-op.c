/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:35:11 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/18 20:21:13 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long long	ft_plus(long long a, long long b);
long long	ft_minus(long long a, long long b);
long long	ft_mult(long long a, long long b);
long long	ft_div(long long a, long long b);
long long	ft_mod(long long a, long long b);
void		ft_putnbr(long long n);

int	ft_atoi(char *str)
{
	int	i;
	int	minus;
	int	num;

	i = 0;
	minus = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		++i;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		++i;
	}
	num *= minus;
	return (num);
}

int	ft_is_op(char *s)
{
	if (s[0] == '+' && s[1] == '\0')
		return (0);
	if (s[0] == '-' && s[1] == '\0')
		return (1);
	if (s[0] == '*' && s[1] == '\0')
		return (2);
	if (s[0] == '/' && s[1] == '\0')
		return (3);
	if (s[0] == '%' && s[1] == '\0')
		return (4);
	return (-1);
}

void	ft_init(long long (*arr[5])(long long, long long))
{	
	arr[0] = &ft_plus;
	arr[1] = &ft_minus;
	arr[2] = &ft_mult;
	arr[3] = &ft_div;
	arr[4] = &ft_mod;
}

int	main(int argc, char **argv)
{
	long	long	(*arr[5])(long long, long long);
	int				i;

	if (argc != 4)
		return (1);
	i = ft_is_op(argv[2]);
	if (i == -1)
	{
		write(1, "0\n", 2);
		return (2);
	}
	ft_init(arr);
	if (ft_atoi(argv[3]) == 0 && (argv[2][0] == '/'
		|| argv[2][0] == '%'))
	{
		if (argv[2][0] == '/')
			write(1, "Stop: division by zero\n", 23);
		if (argv[2][0] == '%')
			write(1, "Stop: modulo by zero\n", 21);
		return (3);
	}
	ft_putnbr((*arr[i])(ft_atoi(argv[1]), ft_atoi(argv[3])));
	return (0);
}
