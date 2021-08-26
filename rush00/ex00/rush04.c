#include <unistd.h>

void	print_line(int cnt, char first, char last , char middle)
{
	int	i;

	i = 0;
	write(1, &first, 1);
	while (i < cnt - 2)
	{
		write(1, &middle, 1);
		++i;
	}
	write(1, &last, 1);
	write(1, "\n", 1);
}

void	rush(int x, int y)
{
	int	row;

	if (x <= 0 || y <= 0)
		return;
	row = 0;
	while (row < x)
	{
		if (row == 0)
			print_line(y, 'A', 'C', 'B');
		else if (row == y - 1)
			print_line(y, 'C', 'A', 'B');
		else
			print_line(y, 'B', 'B', ' ');
		++row;
	}
}
