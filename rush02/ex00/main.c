#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "pair.h"

# define DICT_ERROR 0
# define ERROR 1
# define BUF_SIZE 1024

char	**ft_split(char *str, char *set, int *cnt);
char	*ft_strjoin(int count, char **str, char *sep);	
char	*ft_strdup(char *s);
int		ft_strlen(char *s);

void	print_error(int error)
{
	if (error == DICT_ERROR)
		write(1, "Dict Error!\n", 12);
	else if (error == ERROR)
		write(1, "Error!\n", 7);
}

void	ft_map_copy(char **str, int count, char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (read(fd, *str, count) == -1)
	{
		//Error
	}
	(*str)[count] = '\0';
	close(fd);
}

char	*ft_map(char *file)
{
	int		fd;
	int		d;
	int		count;
	char	buf[BUF_SIZE];
	char	*str;

	fd = open(file, O_RDONLY);
	d = 1;
	count = 0;
	while (1)
	{
		d = read(fd, buf, BUF_SIZE);
		if (d > 0)
			count += d;
		if (d == 0)
			break;
	}
	str = (char *)malloc((count + 1) * sizeof(char));
	printf("count = %d\n", count);
	ft_map_copy(&str, count, file);
	close(fd);
	return (str);
}

int	ft_check_zeroes(char *s)
{
	int	i;

	i = 1;
	while (s[i] != '\0')
	{
		if (s[i] != '0')
			return (0);
		++i;
	}
	return (1);
}

void	init_struct(char *number, char *word, t_pair **arr)
{
	if (ft_strlen(number) == 1)
		arr[0][number[0] - '0'].value = ft_strdup(word);
	else if (ft_strlen(number) == 2)
	{
		if (number[0] == '1')
			arr[1][number[1] - '0'].value = ft_strdup(word);
		else
			arr[2][number[0] - '0'].value =  ft_strdup(word);
	}
	else if (number[0] == '1')
		if (ft_check_zeroes(number))
			arr[3][(ft_strlen(number) - 1) / 3 - '0'].value = ft_strdup(word);
}

void	parse(char *str, t_pair **arr)
{
	int		count;
	char	**lines;
	char	**words;
	char	*res;

	lines = ft_split(str, "\n", &count);
	while (*lines != 0)
	{
		words = ft_split(*lines, " :\0", &count);
		res = ft_strjoin(count - 1, words + 1, " ");
		printf("%s\n", res);
		init_struct(words[0], res, arr);
		//free (res);
		free (*lines);
		free (*words);
		++lines;
		++arr;
	}
	free(words);
}

t_pair	**structs_init(void)
{
	t_pair	**arr;

	arr = (t_pair **)malloc(4 * sizeof(t_pair *));
	arr[0] = (t_pair *)malloc(10 * sizeof(t_pair));
	arr[1] = (t_pair *)malloc(10 * sizeof(t_pair));
	arr[2] = (t_pair *)malloc(18 * sizeof(t_pair));
	arr[3] = (t_pair *)malloc(13 * sizeof(t_pair));
	return (arr);
}

void	structs_free(t_pair **arr)
{
	int	i;
	 i = 0;
	 while (i < 4)
		 free (arr[i++]);
	 free (arr);
}

int	main(int argc, char **argv)
{
	char	*str;
	t_pair	**arr;

	arr = structs_init();
	str = NULL;
	if (argc < 2 || argc > 3)
	{
		print_error(ERROR);
		return (1);
	}
	if (argc == 2)
		str = ft_map(argv[1]);
	else if (argc == 3)
		str = ft_map(argv[2]);
	parse(str, arr);
	structs_free(arr);
	return (0);
}
