#ifndef FDF_H
# define FDF_H 

# include <math.h>
# include "libft/libft.h"
# include "mlx/mlx.h" //Comentar en 42
//# include <mlx.h>   //Comentar en casa

# define SCREEN_WIDTH	1920
# define SCREEN_HEIGHT	1080
# define MAIN_COLOR	0x00FFFFFF

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bbp;
	int		line_length;
	int		endian;
} t_data;
typedef	struct s_node
{
	int	x;
	int	y;
	int	z;
	int	color;
} t_node;
typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
} t_mlx;
typedef struct s_loop
{
	int	x_counter;
	int	y_counter;
	int	y;
	t_mlx graphic;
	t_node **matrix;
} t_loop;

void	print_fdf(int x_counter, int y_counter, t_node **n_matrix, t_mlx graphic);
void	bressen(t_data img, int x0, int x1, int y0, int y1, int color, int color2);
void	put_img_pixel(t_data img, int x, int y, int color);
void	free_matrix(char **matrix, int y_counter);
void	free_nmatrix(t_node **n_matrix, int y_counter);
int		rows_counter(char *argv);
int		count_words(char const *s, unsigned char c);
void	paint_image(t_loop loop);
t_node	parse_line(char *temp, int a, int b, int x_counter, int y_counter, int *max_x, int *max_y, int *min_x, int *min_y);
t_node	**fdf_map(char *argv, t_loop loop);
t_node	*get_map_line(t_node *matrix, char *line, int x_counter, int y, int y_counter, int *max_x,int *max_y, int *min_x, int *min_y);
t_mlx 	graphic_init(void);
#endif
