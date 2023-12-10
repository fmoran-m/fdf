#include "fdf.h"

char	*full_read(int fd)
{
	t_read	data;

	data.str = ft_strdup("");
	if (!data.str)
		return (NULL);
	data.buf = (char *)ft_calloc(BUFFER_SIZE_FDF + 1, sizeof(char));
	if (!data.buf)
		return (NULL);
	data.buf_read = 1;
	while (data.buf_read > 0)
	{
		data.buf_read = read(fd, data.buf, BUFFER_SIZE_FDF);
		if (data.buf_read == -1)
			return (NULL);
		data.buf[data.buf_read] = 0;
		data.temp = ft_strjoin(data.str, data.buf);
		if (!data.temp)
			return (NULL);
		free(data.str);
		data.str = data.temp;
	}
	free(data.buf);
	return (data.str);
}

t_map	**create_map(char *str)
{
	t_map **lst;

t_map	**parse_map(char *argv)
{
	int		fd;
	char	*str;
	t_map	**lst;

	fd = open(argv, O_RDONLY);
	str = full_read(fd);
	printf("%s", str); //Acordarse de borrar
	lst = create_map(str);
	return (lst);
}

int	main(int argc, char **argv)
{
	t_map	**lst;

	if (argc != 2)
		return (-1);
	parse_map(argv[1]);
	return 0;
}
