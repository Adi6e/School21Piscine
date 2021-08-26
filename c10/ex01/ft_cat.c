/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:28:09 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/17 22:30:18 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <libgen.h>
#include <string.h>

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		write(2, &s[i++], 1);
}

void	ft_print_error(char *progname, char *filename)
{
	ft_putstr(basename(progname));
	write(2, ": ", 2);
	ft_putstr(filename);
	write(2, ": ", 2);
	ft_putstr(strerror(errno));
	write(2, "\n", 1);
}

void	ft_write_stdin(char *progname, char *filename, char *buf)
{
	int		d;
	int		d_prev;
	int		w;
	char	c;

	d = 1;
	d_prev = -1;
	while (d > 0)
	{
		d = read(0, buf, 1024);
		if (d == -1)
			ft_print_error(progname, filename);
		if (d == 0 && d_prev == -1)
			break ;
		if (d == 0 && (c == '\n' || d_prev < 1024))
			break ;
		if (d > 0)
			w = write(1, buf, d);
		if (w == -1)
			ft_print_error(progname, filename);
		c = buf[d - 1];
		d_prev = d;
	}
}

void	ft_write_file(char *progname, char *filename, char *buf)
{
	int		fd;
	int		ch_r;
	int		ch_w;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_print_error(progname, filename);
		return ;
	}
	ch_r = 1024;
	ch_w = 1024;
	while (ch_r == 1024 && ch_w == 1024)
	{
		ch_r = read(fd, buf, 1024);
		if (ch_r == -1)
			ft_print_error(progname, filename);
		if (ch_r > 0)
			ch_w = write(1, buf, ch_r);
		if (ch_w == -1)
			ft_print_error(progname, filename);
	}
	if (close(fd))
		ft_print_error(progname, filename);
}

int	main(int argc, char **argv)
{
	int		i;
	char	buf[1024];

	i = 1;
	if (argc == 1)
		ft_write_stdin(argv[0], "", buf);
	else if (argv[1][0] == '-' && argv[1][1] == '-')
	{
		if (argc == 2)
			ft_write_stdin(argv[0], argv[1], buf);
		++i;
	}
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '\0')
			ft_write_stdin(argv[0], argv[i], buf);
		else
			ft_write_file(argv[0], argv[i], buf);
		++i;
	}
	if (errno)
		return (1);
	return (0);
}
