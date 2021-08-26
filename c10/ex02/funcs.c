/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 22:53:08 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/17 23:32:52 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <libgen.h>

void	ft_print_error(char *filename);
void	ft_putstr(char *s, int fd);

int	ft_from_stdin(char *buf, int n, int *j)
{
	int		d;
	int		d_prev;
	int		cnt;
	char	c;

	d = 1;
	d_prev = -1;
	*j = 0;
	cnt = 0;
	while (d > 0)
	{
		d = read(0, buf + *j, n - *j);
		if (d == n - *j)
			*j = 0;
		else if (d > 0)
			*j += d;
		if (d == 0 && d_prev == -1)
			break ;
		if (d == 0 && (c == '\n' || d_prev < n))
			break ;
		c = buf[d - 1];
		d_prev = d;
		++cnt;
	}
	return (cnt);
}

void	ft_write_stdin(char *buf, int n)
{
	int	i;
	int	cnt;
	int	w;

	w = 0;
	cnt = ft_from_stdin(buf, n, &i);
	if (i <= n)
	{
		if (cnt > 1)
			write(1, buf + i, n - i);
		write(1, buf, i);
	}
}

int	ft_from_file(int fd, char *buf, int n, int *j)
{
	int		d;
	int		d_prev;
	int		cnt;
	char	c;

	d = 1;
	d_prev = -1;
	*j = 0;
	cnt = 0;
	while (d > 0)
	{
		d = read(fd, buf + *j, n - *j);
		if (d == n - *j)
			*j = 0;
		else if (d > 0)
			*j += d;
		c = buf[d - 1];
		d_prev = d;
		++cnt;
	}
	return (cnt);
}

void	ft_write_file(char *buf, int n, char *filename, int cnt_ff)
{
	int	i;
	int	cnt;
	int	fd;

	if (cnt_ff > 1)
	{
		write(1, "==> ", 4);
		ft_putstr(filename, 1);
		write(1, " <==\n", 5);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_print_error(filename);
		return ;
	}
	cnt = ft_from_file(fd, buf, n, &i);
	if (i <= n)
	{
		if (cnt > 1)
			write(1, buf + i, n - i);
		write(1, buf, i);
	}	
	if (close(fd))
		ft_print_error(filename);
}
