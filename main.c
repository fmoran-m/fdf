#include "fdf.h"

static int  map_counter(char *argv)
{
    int	    counter;
    int	    fd;
    char    *temp;

    counter = 0;
    fd = open(argv, O_RDONLY);
    temp = get_next_line(fd);
    if (temp != 0)
	counter++;
    while (temp != NULL)
    {
	free(temp);
	temp = get_next_line(fd);
	if (temp != 0)
	    counter++;
    }
    close (fd);
    return (counter);
}

static char	**matrix_allocation(int y_counter, char *argv)
{
    int	    fd;
    int	    i;
    char    *temp;
    char    **matrix;

    i = 0;
    matrix = (char **)ft_calloc(y_counter + 1, sizeof(char *));
    if (!matrix)
	return (NULL);
    fd = open(argv, O_RDONLY);
    temp = get_next_line(fd);
    if (temp != 0)
	matrix[i] = temp;
    i++;
    while (temp != NULL)
    {
	temp = get_next_line(fd);
	if (temp != 0)
	{
	    matrix[i] = temp;
	    i++;
	}
    }
    close(fd);
    return (matrix);
}

static void free_matrix(char **matrix, int y_counter)
{
    int	i;

    i = 0;
    while (i < y_counter)
    {
	free(matrix[i]);
	i++;
    }
    free (matrix);
}

static void free_nmatrix(int **n_matrix, int y_counter)
{
    int	i;

    i = 0;
    while (i < y_counter)
    {
	free(n_matrix[i]);
	i++;
    }
    free (n_matrix);
}

static int  **massive_atoi(char **matrix, int y_counter, int x_counter)
{
    int     **n_matrix;
    char    **temp;
    int     a;
    int     b;
    int     j;
    int     i;

    n_matrix = ft_calloc(y_counter + 1, sizeof(int *));
    temp = NULL;
    i = 0;
    a = 0;
    while (matrix[i])
    {
        temp = ft_split(matrix[i], ' ');
        j = 0;
        b = 0;
        n_matrix[a] =(int *)ft_calloc(x_counter + 1, sizeof(int));
        while (temp[j])
        {
            n_matrix[a][b] = ft_atoi(temp[j]);
            b++;
            j++;
        }
	free_matrix(temp, x_counter);
        a++;
        i++;
    }
    return (n_matrix);
}

int main (int argc, char **argv)
{
    int	    y_counter;
    int	    x_counter;
    int	    i;
    char    **matrix;
    int	    **n_matrix;

    y_counter = 0;
    x_counter = 1;
    i = 0;
    if (argc != 2)
	return (-1);
    y_counter = map_counter(argv[1]);
    matrix = matrix_allocation(y_counter, argv[1]);
    while(matrix[0][i])
    {
	if (matrix[0][i] == ' ')
	    x_counter++;
	i++;
    }
    n_matrix = massive_atoi(matrix, y_counter, x_counter);
    free_matrix(matrix, y_counter);
    int a = 0;
    while (n_matrix[a] != NULL)
    {
	int b = 0;
	while (b < x_counter)
	{
	    printf("%d\n", n_matrix[a][b]);
	    b++;
	}
	a++;
    }
    free_nmatrix(n_matrix, y_counter);
    //ft_printf("%d\n%d\n", x_counter, y_counter);
    return (0);
}
