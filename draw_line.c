#include "fdf.h"

static void	ft_rot_z(t_node	*node, t_trans *trans)
{
	int	x;
	int	y;
	int	theta;

	theta = ((trans->z_rot) * M_PI) / 180;
	x = (node->x * cos(theta)) - (node->y * sin(theta));
	y = (node->x * sin(theta)) + (node->y * cos(theta));
	node->x = x;
	node->y = y;
}

static void	ft_rot_y(t_node	*node, t_trans *trans)
{
	int	x;
	int	z;
	int	theta;

	theta = ((trans->y_rot) * M_PI) / 180;
	x = (node->x * cos(theta)) + (node->y * sin(theta));
	z = (node->z * -sin(theta)) + (node->z * cos(theta));
	node->x = x;
	node->z = z;
}

static void	ft_rot_x(t_node	*node, t_trans *trans)
{
	int	y;
	int	z;
	int	theta;

	theta = ((trans->x_rot) * M_PI) / 180;
	y = (node->y * cos(theta)) - (node->z * sin(theta));
	z = (node->y * sin(theta)) + (node->z * cos(theta));
	node->y = y;
	node->z = z;
}

static void	ft_rotation(t_node *node, t_trans *trans)
{
	if (trans->x_rot != 0)
		ft_rot_x(node, trans);
	if (trans->y_rot != 0)
		ft_rot_y(node, trans);
	if (trans->z_rot != 0)
		ft_rot_z(node, trans);
}

static void	ft_isometric(t_node *node)
{
	double theta;
	int		x;
	int		y;

	theta = (30 * M_PI) / 180;
	x = (node->x * cos(theta)) - (node->y * cos(theta));
	y = ((node->x * sin(theta)) + (node->y * sin(theta)) - node->z);
	node->x = x;
	node->y = y;
}

static double ft_min(int width, int height)
{
	double x;
	double y; 

	x = SCREEN_WIDTH / width;
	y = SCREEN_HEIGHT / height;
	if (x < y)
		return (x);
	else
		return (y);
}

static void	ft_scale_position(t_node *node, t_trans *trans, t_map *map)
{
	int		x;
	int		y;
	double	zoom;

	zoom = ft_min(map->width, map->height) * trans->scale;
	x = node->x * zoom; //Escala
	y = node->y * zoom;
	x -= (map->width * zoom) / 2; //Centrado
	y -= (map->height * zoom) / 2;
	node->x = x;
	node->y = y;
}

static t_node	transformation(t_node node, t_trans *trans, t_map *map)
{
	ft_scale_position(&node, trans, map);
	ft_rotation(&node, trans);
	ft_isometric(&node);
	node.x += SCREEN_WIDTH / 2 + trans->x_pos;
	node.y += ((SCREEN_HEIGHT + map->height * (trans->scale / 2)) / 2) + trans->y_pos;
	return (node);
}

void	draw_line(t_node *matrix, t_map *map, t_mlx *mlx, t_trans *trans)
{
	int		i;
	t_node	node1;
	t_node	node2;

	i = 0;
	while (i + 1 < map->height)
	{
		node1 = transformation(matrix[i], trans, map);
		node2 = transformation(matrix[i + 1], trans, map);
		bressen(node1, node2, mlx);
		i++;
	}
}