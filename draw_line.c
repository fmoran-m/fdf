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
	int	x;
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
	return (new);
}

static void	ft_isometric(t_node *node, t_trans *trans)
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

static void ft_min(int width, int height)
{
	int x;
	int y; 

	x = SCREEN_WIDTH / width;
	y = SCREEN_HEIGHT / height;
	if (x < y)
		return (x);
	else
		return (y);
}

static void	ft_scale_position(t_node *node, t_trans *trans)
{
	int	zoom;
	int	x;
	int	y;

	zoom = ft_min(node->width, node->height);
	zoom * trans->scale;
	x = node->x * scale; //Escala
	y = node->y * scale;
	x -= (node->width * scale) / 2; //Centrado
	y -= (node->height * scale) / 2;
	node->x = x;
	node->y = y;
}

static t_node	transformation(t_node *node, t_trans *trans)
{
	ft_scale_position(&node, trans);
	ft_rotation(&node, trans);
	ft_isometric(&node, trans);
	node->x += SCREEN_WIDTH / 2 + trans->x_pos;
	node->y += ((SCREEN_HEIGHT + node->height * (trans->scale / 2)) / 2) + trans->y_pos;
}

void	draw_line(t_node *matrix, t_map *map, t_mlx *mlx, t_trans *trans)
{
	int		i;
	t_node	node1;
	t_node	node2;

	i = 0;
	while (i + 1 < map->height)
	{
		node1 = transformation(matrix[i], trans);
		node2 = transformation(matrix[i + 1], trans);
		bressen(node1, node2, mlx);
		i++;
	}
}