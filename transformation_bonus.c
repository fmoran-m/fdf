#include "fdf.h"

static t_node	isometric_perspective(t_node node, t_trans *trans)
{
	double theta;
	int		x;
	int		y;

	theta = (30 * M_PI) / 180;
	x = (node.x * cos(theta)) - (node.y * cos(theta));
	y = ((node.x * sin(theta)) + (node.y * sin(theta)) - (node.z + trans->z_scale));
	node.x = x;
	node.y = y;
	return (node);
}

double min_vector(int width, int height)
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

static t_node	scale_position(t_node node, t_trans *trans, t_map *map)
{
	int		x;
	int		y;
	double	zoom;

	zoom = min_vector(map->width, map->height) + trans->scale;
	x = node.x * zoom;
	y = node.y * zoom;
	x -= (map->width * zoom) / 2;
	y -= (map->height * zoom) / 2;
	node.x = x;
	node.y = y;
	node.z *= trans->z_scale;
	return (node);
}

t_node	new_fig(t_node node, t_trans *trans, t_map *map)
{ 
	node = scale_position(node, trans, map);
	trans->z_scale = (SCREEN_HEIGHT / (map->max_z - map->min_z)) / 5;
	if (trans->z_scale < 1)
		trans->z_scale = 1;
	node = isometric_perspective(node, trans);
	node.x += SCREEN_WIDTH / 2 + trans->x_pos;
	node.y += ((SCREEN_HEIGHT + map->height * (trans->scale / 2)) / 2) + trans->y_pos;
	return (node);
}