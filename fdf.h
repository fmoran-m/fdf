#ifndef FDF_H
# define FDF_H 

# include <math.h>
# include "libft/libft.h"
//# include "mlx/mlx.h" //Comentar en 42
# include <mlx.h>   //Comentar en casa

# define SCREEN_WIDTH	1920
# define SCREEN_HEIGHT	1080
# define MAIN_COLOR	0x00FFFFFF
/*
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bbp;
	int		line_length;
	int		endian;
} t_data;
*/
typedef	struct s_trans
{
	int	scale;
	int	z_scale;
	int	x_pos;
	int	y_pos;
	int	x_rot;
	int	y_rot;
	int	z_rot;
} t_trans;
typedef struct s_map
{
	int	width;
	int	height;
	int	max_x;
	int	min_x;
	int	max_y;
	int	min_y;
	int	max_z;
	int	min_z;	
} t_map;
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
	void	*img;
	char	*addr;
	int		bbp;
	int		line_length;
	int		endian;
} t_mlx;
typedef struct s_control
{
	t_trans *trans;
	t_map	*map;
	t_mlx	*mlx;
	t_node **matrix;
} t_control;
void	put_img_pixel(t_mlx *mlx, int x, int y, int color);
void	free_matrix(char **matrix, int y_counter);
void	free_nmatrix(t_node **n_matrix, int y_counter);
int		rows_counter(char *argv);
int		count_words(char const *s, unsigned char c);
t_node	parse_line(char *temp, int x, int y, t_map *map);
t_node	**parse_map(char *argv, t_node **matrix, t_map *map);
t_node	*get_map_line(t_node *matrix, char *line, t_map *map, int y);
t_mlx 	graphic_init(void);
t_node	*get_map_line(t_node *matrix, char *line, t_map *map, int y);
t_map	map_init(void);
t_trans	trans_init(void);
void	bressen(t_node node1, t_node node2, t_mlx *mlx);
void    draw_map(t_node **matrix, t_map map, t_mlx *mlx, t_trans trans);
t_node	transformation(t_node node, t_trans *trans, t_map *map);
void	inputs(t_mlx *mlx);
#endif
