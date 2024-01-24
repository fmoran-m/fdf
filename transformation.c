#include "fdf.h"

static t_node	ft_rot_z(t_node	node, t_trans *trans)
{
	int	x;
	int	y;
	int	theta;

	theta = ((trans->z_rot) * M_PI) / 180;
	x = (node.x * cos(theta)) - (node.y * sin(theta));
	y = (node.x * sin(theta)) + (node.y * cos(theta));
	node.x = x;
	node.y = y;
	return (node);
}

static t_node	ft_rot_y(t_node	node, t_trans *trans)
{
	int	x;
	int	z;
	int	theta;

	theta = ((trans->y_rot) * M_PI) / 180;
	x = (node.x * cos(theta)) + (node.y * sin(theta));
	z = (node.z * -sin(theta)) + (node.z * cos(theta));
	node.x = x;
	node.z = z;
	return (node);
}

static t_node	ft_rot_x(t_node	node, t_trans *trans)
{
	int	y;
	int	z;
	int	theta;

	theta = ((trans->x_rot) * M_PI) / 180;
	y = (node.y * cos(theta)) - (node.z * sin(theta));
	z = (node.y * sin(theta)) + (node.z * cos(theta));
	node.y = y;
	node.z = z;
	return (node);
}

static t_node	ft_rotation(t_node node, t_trans *trans)
{
	if (trans->x_rot != 0)
		ft_rot_x(node, trans);
	if (trans->y_rot != 0)
		ft_rot_y(node, trans);
	if (trans->z_rot != 0)
		ft_rot_z(node, trans);
	return (node);
}

static t_node	ft_isometric(t_node node)
{
	double theta;
	int		x;
	int		y;

	theta = (30 * M_PI) / 180;
	x = (node.x * cos(theta)) - (node.y * cos(theta));
	y = ((node.x * sin(theta)) + (node.y * sin(theta)) - node.z);
	node.x = x;
	node.y = y;
	return (node);
}

static double ft_min(int width, int height)
{
	double x;
	double y; 

	x = SCREEN_WIDTH / width / 2;
	y = SCREEN_HEIGHT / height / 2;
	if (x < y)
		return (x);
	else
		return (y);
}

static t_node	ft_scale_position(t_node node, t_trans *trans, t_map *map)
{
	int		x;
	int		y;
	double	zoom;

	zoom = ft_min(map->width, map->height) * trans->scale;
	x = node.x * zoom; //Escala
	y = node.y * zoom;
	x -= (map->width * zoom) / 2; //Centrado
	y -= (map->height * zoom) / 2;
	node.x = x;
	node.y = y;
	return (node);
}

t_node	transformation(t_node node, t_trans *trans, t_map *map)
{
	node = ft_scale_position(node, trans, map);
	node = ft_rotation(node, trans);
	node = ft_isometric(node);
	node.x += SCREEN_WIDTH / 2 + trans->x_pos;
	node.y += ((SCREEN_HEIGHT + map->height * (trans->scale / 2)) / 2) + trans->y_pos;
	return (node);
}
