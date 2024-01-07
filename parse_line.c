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

t_node	parse_line(char *temp, int x, int y, int x_counter)
{
	int		i;
	int		color;
	int		x_space = SCREEN_WIDTH / x_counter;
	t_node	new;

	i = 0;
	color = 0;
	new.x = x * x_space + 1;
	new.z = ft_atoi(temp) * x_space + 1;
	new.y = y * x_space + 1;
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