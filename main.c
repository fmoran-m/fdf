#include "fdf.h"

static int	ft_count_words(char const *s, unsigned char c)
{
	int	flag;
	int	i;
	int n;

	flag = 1;
	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 1)
		{
			n++;
			flag = 0;
		}
		if (s[i] == c)
			flag = 1;
		i++;
	}
	return (n);
}

static int	map_counter(char *argv)
{
	int		counter;
	int		fd;
	char	*temp;

	counter = 0;
	fd = open(argv, O_RDONLY);
	temp = get_next_line(fd);
	if (!temp)
		return (0);
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

static char	**matrix_allocation(int y_counter, char *argv)
{
	int		fd;
	int		i;
	char	*temp;
	char	**matrix;

	i = 0;
	matrix = (char **)ft_calloc(y_counter + 1, sizeof(char *));
	if (!matrix)
		return (NULL);
	fd = open(argv, O_RDONLY);
	temp = get_next_line(fd);
	if (temp != NULL)
		matrix[i] = temp;
	i++;
	while (temp != NULL)
	{
		temp = get_next_line(fd);
		if (temp != NULL)
		{
			matrix[i] = temp;
			i++;
		}
	}
	close(fd);
	return (matrix);
}

static void	free_matrix(char **matrix, int y_counter)
{
	int	i;

	i = 0;
	while (i < y_counter)
	{
		free(matrix[i]);
		i++;
	}
	free (matrix);
}


static void	free_nmatrix(t_node **n_matrix, int y_counter)
{
	int	i;

	i = 0;
	while (i < y_counter)
	{
		free(n_matrix[i]);
		i++;
	}
	free (n_matrix);
}

static int	get_color(char *str, int i)
{
	char	*res;
	int		j;
	int		color;

	j = i;
	while (str[j])
		j++;
	res = (char *)ft_calloc(j - i + 1, sizeof(char));
	j = 0;
	while (str[i])
	{
		res[j] = str[i];
		j++;
		i++;
	}
	color = ft_atoi_base(res);
	free(res);
	return (color);
}

t_node	parse_line(char *temp, int a, int b, int x_counter)
{
	int		i;
	int		color;
	int		x_space = (SCREEN_WIDTH / 5) / x_counter;
	t_node	new;

	i = 0;
	color = 0;
	new.x = b; //Tal vez haya que sumar 1
	new.z = ft_atoi(temp) * x_space;
	//new.z = ft_atoi(temp);
	new.y = a; //Tal vez haya que sumar 1
	while (temp[i] && temp[i] != ',')
		i++;
	if (temp[i] == ',')
	{
		i++;
		color = get_color(temp, i);
	}
	new.color = color;
	return (new);
}

static t_node	**massive_atoi(char **matrix, int y_counter, int x_counter)
{
	t_node		**n_matrix;
	char		**temp;
	int			a;
	int			b;
	int			j;
	int			i;

	n_matrix = (t_node **)ft_calloc(y_counter + 1, sizeof(t_node *));
	temp = NULL;
	i = 0;
	a = 0;
	while (matrix[i])
	{
		temp = ft_split(matrix[i], 32);
		j = 0;
		b = 0;
		n_matrix[a] =(t_node *)ft_calloc(x_counter + 1, sizeof(t_node));
		while (temp[j])
		{
			n_matrix[a][b] = parse_line(temp[j], a, b, x_counter);
			b++;
			j++;
		}
		free_matrix(temp, x_counter);
		a++;
		i++;
	}
	return (n_matrix);
}

int	main(int argc, char **argv)
{
	int			y_counter;
	int			x_counter;
	char		**matrix;
	t_node		**n_matrix;

	y_counter = 0;
	x_counter = 0;
	if (argc != 2)
		return (-1);
	y_counter = map_counter(argv[1]);
	if (y_counter == 0)
		return (0);
	matrix = matrix_allocation(y_counter, argv[1]);
	x_counter = ft_count_words(matrix[0], 32);
	n_matrix = massive_atoi(matrix, y_counter, x_counter);
	free_matrix(matrix, y_counter); //Puede que leak en pasar y_counter
	/*
	for (int i = 0; i < y_counter; i++)
	{
		for (int j = 0; j < x_counter; j++)
			printf("x = %d, y = %d, z = %d, color = %d\n", n_matrix[i][j].x, n_matrix[i][j].y, n_matrix[i][j].z, n_matrix[i][j].color);
	}
	*/
	print_fdf(x_counter, y_counter, n_matrix);
	free_nmatrix(n_matrix, y_counter); //Puede que leak en y_counter
//	system("leaks -q fdf");
	return 0;
}
