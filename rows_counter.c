#include "fdf.h"

int	rows_counter(char *argv)
{
	int		counter;
	int		fd;
	char	*temp;

	counter = 0;
	fd = open(argv, O_RDONLY);
	temp = get_next_line(fd);
	if (!temp)
		return(0); // Control de errores, podemos hacer exit
	counter++;
	while (temp != NULL)
	{
		free(temp);
		temp = get_next_line(fd);
		if (temp != NULL)
			counter++;
	}
	close (fd);
	return (counter);
}
