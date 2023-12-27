#ifndef FDF_H
# define FDF_H 

# include <math.h>
# include "libft/libft.h"
//# include "mlx/mlx.h" //Comentar en 42
# include <mlx.h>   //Comentar en casa

# define SCREEN_WIDTH	1920
# define SCREEN_HEIGHT	1080
# define MAIN_COLOR	0x00FFFFFF

typedef struct s_data
{
	void	*img;
	char	*addr;
	int	bbp;
	int	line_length;
	int	endian;
} t_data;
typedef	struct s_node
{
	int	x;
	int	y;
	int	z;
	int	color;
} t_node;

void	pruebas (int x_counter, int y_counter);
void	print_fdf(int x_counter, int y_counter, t_node **n_matrix);
void	bressen(t_data img, int x0, int x1, int y0, int y1);
void	put_img_pixel(t_data img, int x, int y, int color);
#endif
