#include "fdf.h"

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

t_node	parse_line(char *temp, int x, int y, t_map **map)
{
	int		i;
	int		color;
	t_node	new;

	i = 0;
	color = 0;
	new.x = x;
	new.z = ft_atoi(temp);
	new.y = y;
	while (temp[i] && temp[i] != ',')
		i++;
	if (temp[i] == ',')
	{
		i++;
		color = get_color(temp, i);
	}
	new.color = color;
	if (new.x > (map->max_x))
		map->max_x = new.x;	
	if (new.y > (map->max_y))
		map->max_y = new.y;
	if (new.x < (map->min_x))
		map->min_x = new.x;
	if (new.y < (map->min_y))
		map->min_y = new.y;
	return (new);
}
