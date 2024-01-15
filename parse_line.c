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

static t_node	rotate_node(t_node new)
{
	int x;
	int y;
	double theta;

	theta = (-90 * M_PI) / 180;
	x = (new.x * cos(theta)) - (new.y * sin(theta));
	y = (new.x * sin(theta)) + (new.x * cos(theta));
	new.x = x;
	new.y = y;
	return (new);
}

static t_node	iso_node(t_node new, int x_counter, int y_counter)
{
	int		x;
	int		y;
	double	theta;

	theta = (30 * M_PI) / 180;
	x = (new.x * cos(theta)) - (new.y * cos(theta)) + ((SCREEN_WIDTH / 2) - (x_counter / 2));
	y = ((new.x * sin(theta)) + (new.y * sin(theta)) - new.z) + ((SCREEN_HEIGHT / 2) - (y_counter / 2));
	new.x = x;
	new.y = y;
	return (new);
}

t_node	parse_line(char *temp, int x, int y, int x_counter, int y_counter, int *max_x, int *max_y)
{
	int		i;
	int		color;
	int		x_space;
	t_node	new;

	//x_space = SCREEN_WIDTH / x_counter;
	x_space = 1;
	i = 0;
	color = 0;
	new.x = x * x_space;
	new.z = ft_atoi(temp) * x_space;
	new.y = y * x_space;
	while (temp[i] && temp[i] != ',')
		i++;
	if (temp[i] == ',')
	{
		i++;
		color = get_color(temp, i);
	}
	new.color = color;
	new = rotate_node(new);
	new = iso_node(new, x_counter, y_counter);
	if (new.x > (*max_x))
		*max_x = new.x;	
	if (new.y > (*max_y))
		*max_y = new.y;
//	printf("%d, %d\n", new.x, new.y);
	return (new);
}
