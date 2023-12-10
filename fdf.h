#ifndef FDF_H
# define FDF_H 

# include <math.h>
# include "libft/libft.h"
# include "mlx/mlx.h" //Comentar en 42
//# include <mlx.h>   //Comentar en casa

# define BUFFER_SIZE_FDF	256
# define SCREEN_WIDTH		720
# define SCREEN_HEIGHT		480
# define MAIN_COLOR			0x00FFFFFF

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bbp;
	int		line_length;
	int		endian;
}				t_data;
typedef struct s_map
{
	int		x;
	int		y;
	int		z;
	int		color;
	char	*next;
}				t_map;
typedef struct s_read
{
	char	*buf;
	char	*str;
	char	*temp;
	ssize_t	buf_read;
}				t_read;

void	pruebas(int x_counter, int y_counter);
#endif
