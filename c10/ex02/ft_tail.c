/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldarlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 23:04:53 by ldarlene          #+#    #+#             */
/*   Updated: 2021/08/17 23:36:22 by ldarlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <errno.h>

char	*g_progname;
int		g_flag;

int		ft_from_stdin(char *buf, int n, int *j);
void	ft_write_stdin(char *buf, int n, char *filename);
int		ft_from_file(int fd, char *buf, int n, int *j);
void	ft_write_file(char *buf, int n, char *filename, int ff);
int		ft_atoi(char *s);

void	ft_putstr(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		write(fd, &s[i++], 1);
}

void	ft_print_error(char *filename)
{
	ft_putstr(basename(g_progname), 2);
	write(2, ": ", 2);
	ft_putstr(filename, 2);
	write(2, ": ", 2);
	ft_putstr(strerror(errno), 2);
	g_flag = 1;
}

int	main(int argc, char **argv)
{
	char	*buf;
	int		a[3];

	g_flag = 0;
	g_progname = argv[0];
	a[1] = 1;
	if (argv[1][2] == '\0')
	{
		a[0] = ft_atoi(argv[++a[1]]);
		++a[1];
	}
	else
		a[0] = ft_atoi(argv[a[1]++] + 2);
	buf = (char *)malloc(a[0] * sizeof(char));
	if (a[1] == argc)
		ft_write_stdin(buf, a[0], "\0");
	a[2] = argc - a[1];
	while (a[1] < argc)
	{
		ft_write_file(buf, a[0], argv[a[1]++], a[2]);
		if (a[1] - 1 != argc - 1)
			write(1, "\n", 1);
	}
	free (buf);
	return (g_flag);
}
