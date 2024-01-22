#include "fdf.h"

void	map_init(t_map **map)
{
	map->width = 0;
	map->height = 0;
	map->max_x = 0;
	map->max_y = 0;
	map->min_x = SCREEN_WIDTH;
	map->min_y = SCREEN_HEIGHT;
	map->max_z = 0;
	map->min_z = 0;
}
