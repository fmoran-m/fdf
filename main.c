#include "fdf.h"

static char	*full_read(int fd)
{
	t_read	data;

	data.str = ft_strdup("");
	if (!data.str)
		return (NULL);
	data.buf = (char *)ft_calloc(BUFFER_SIZE_FDF + 1, sizeof(char));
	if (!data.buf)
		return (NULL);
	data.buf_read = 1;
	while (data.buf_read > 0)
	{
		data.buf_read = read(fd, data.buf, BUFFER_SIZE_FDF);
		if (data.buf_read == -1)
			return (NULL);
		data.buf[data.buf_read] = 0;
		data.temp = ft_strjoin(data.str, data.buf);
		if (!data.temp)
			return (NULL);
		free(data.str);
		data.str = data.temp;
	}
	free(data.buf);
	return (data.str);
}

static t_map	*create_node(char *str, unsigned long long int *i, int x_counter, int y_counter)
{
	unsigned long long int		j;
	int		k;
	int		z_value;
	int		color;
	char	*temp;
	t_map	*new_node;

	z_value = 0;
	k = 0;
	color = 0;
	j = *i;
	while (str[*i] && str[*i] != ' ' && str[*i] != '\n' && str[*i] != ',')
		(*i)++;
	temp = (char *)ft_calloc(*i - j + 1, sizeof(char));
	while (j < *i)
	{
		temp[k] = str[j];
		j++;
		k++;
	}
	z_value = ft_atoi(temp);
	free(temp);
	k = 0;
	if (str[*i] == ',')
	{
		(*i)++;
		j++;
		while (str[*i] && str[*i] != ' ' && str[*i] != '\n')
			(*i)++;
		temp = (char *)ft_calloc(*i - j + 1, sizeof(char));
		while (j < *i)
		{
			temp[k] = str[j];
			j++;
			k++;
		}
		color = ft_atoi(temp);
		free(temp);
	}
	new_node = ft_lstnew_map(x_counter, y_counter, z_value, color);
	return (new_node);
}

static t_map	*create_map(char *str, int *y_counter)
{
	t_map						*head;
	t_map						*tail;
//	t_map						**ref_head;
//	t_map						**ref_tail;
	t_map						*new_node;
	int							x_counter;
	unsigned long long int		i;

	head = NULL;
	tail = NULL;
	//ref_head = &head;
	//ref_tail = &tail;
	i = 0;
	x_counter = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			if (str[i] == '\n')
			{
				(*y_counter)++;
				i++;
			}
			else
			{
				new_node = create_node(str, &i, x_counter, *y_counter);
				ft_lstadd_back_map(&tail, &head, new_node);
				x_counter++;
			}
		}
		else
			i++;
	}
	return (head);
}

static t_map	*parse_map(char *argv, int *y_counter)
{
	int		fd;
	char	*str;
	t_map	*lst;

	fd = open(argv, O_RDONLY);
	str = full_read(fd);
	lst = create_map(str, y_counter);
	return (lst);
}

int	main(int argc, char **argv)
{
	t_map	*lst;
	int		y_counter;

	y_counter = 0;
	if (argc != 2)
		return (-1);
	lst = parse_map(argv[1], &y_counter);
	while (lst) {
		printf("Node: x = %d, y = %d, z = %d, color = %d\n", lst->x, lst->y, lst->z, lst->color);
        lst = lst->next;
    }
	return 0;
}
