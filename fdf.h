#ifndef FDF_H
# define FDF_H 

# include <math.h>
# include <errno.h>
# include "libft/libft.h"
//# include "mlx/mlx.h" //Comentar en 42
# include <mlx.h>   //Comentar en casa

# define SCREEN_WIDTH	1920
# define SCREEN_HEIGHT	1080
# define MAIN_COLOR		0xFFFFFF
# define ARG_ERR		"Incorrect number of arguments. This function requires exactly 1 argument."
# define FILE_ERR		"Invalid file extension."
# define MEM_ERR		"Memory allocation error."
# define READ_ERR		"Error reading the file."
# define MAP_ERR		"Incorrect map format. Could be a memory allocation error."

typedef	struct s_trans
{
	int		scale;
	int		z_scale;
	int		x_pos;
	int		y_pos;
	int		projection;
	int		mouse_pressed;
	int		last_x;
	int		last_y;
	int		x_rot_bool;
	int		y_rot_bool;
	int		z_rot_bool;
	double	x_mouse;
	double	y_mouse;
	double	x_rot_k;
	double	x_rot;
	double	y_rot;
	double	z_rot;
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
	int				x;
	int				y;
	int				z;
	unsigned int	color;
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
	t_node	**matrix;
	t_map	*map;
	t_mlx	*mlx;
	t_trans	*trans;
} t_control;
void		put_img_pixel(t_mlx *mlx, int x, int y, int color);
void		free_matrix(char **matrix, int y_counter);
int			rows_counter(char *argv, t_map *map);
int			count_words(char const *s, unsigned char c);
t_node		parse_node(char *temp, int x, int y, t_map *map);
t_node		**parse_map(char *argv, t_node **matrix, t_map *map);
t_node		*get_map_line(t_node *matrix, char *line, t_map *map, int y);
t_mlx 		*graphic_init(t_node **matrix, t_map *map, t_trans *trans);
t_node		*get_map_line(t_node *matrix, char *line, t_map *map, int y);
t_map		*map_init(void);
t_trans		*trans_init(t_node **matrix, t_map *map);
void		bressen(t_node node1, t_node node2, t_mlx *mlx);
void    	draw_map(t_node **matrix, t_map *map, t_mlx *mlx, t_trans *trans);
t_node		transformation(t_node node, t_trans *trans, t_map *map);
void		inputs(t_control *control);
t_control	*control_init(t_map *map, t_mlx *mlx, t_node **matrix, t_trans *trans);
void		exit_program(char *macro);
void		exit_free_map(char *macro, t_map *map);
void		exit_free_onlymatmap(t_node **matrix, t_map *map, int *fd);
void		exit_free_matmap_fd(t_map *map, t_node **matrix, int *fd, int y);
void		exit_free_matmap(t_map *map, t_node **matrix);
void		exit_free_matmaptrans(t_map *map, t_node **matrix, t_trans *trans);
void		exit_all(t_map *map, t_node **matrix, t_trans *trans, t_mlx *mlx);
void		free_all(t_map *map, t_node **matrix, t_trans *trans, t_mlx *mlx);
#endif
