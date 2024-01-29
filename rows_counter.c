#include "fdf.h"

int	rows_counter(char *argv, t_map *map)
{
	int		counter;
	int		fd;
	char	*temp;

	counter = 0;
	fd = open(argv, O_RDONLY);
	temp = get_next_line(fd);
	if (!temp)
	{
		close(fd);
		exit_free_map(READ_ERR, map);
	}
	counter++;
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		if (temp != NULL)
			counter++;
	}
	close (fd);
	return (counter);
}
