#include "fdf.h"

void	exit_program(char *macro)
{
	ft_putendl_fd(macro, 2);
	exit (-1);
}

void	exit_free_map(char *macro, t_map *map)   
{
		free(map);
		ft_putendl_fd(macro, 2);
		exit (-1);
}

void	exit_free_onlymatmap(t_node **matrix, t_map *map, int *fd)
{
	close(*fd);
	free(map);
	free(matrix);
	ft_putendl_fd(READ_ERR, 2);
	exit (-1);
}

void	exit_free_matmap_fd(t_map *map, t_node **matrix, int *fd, int y)
{
	int	i;

	i = 0;
	close(*fd);
	free(map);
	while (i < y)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	ft_putendl_fd(MAP_ERR, 2);
	exit (-1);
}

void	exit_free_matmap(t_map *map, t_node **matrix)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	free(map);
	ft_putendl_fd(MEM_ERR, 2);
	exit (-1);
}