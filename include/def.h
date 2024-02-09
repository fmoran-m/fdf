/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:47:24 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/09 17:47:25 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_H
# define DEF_H 

typedef struct s_bressen
{
	int	dx;
	int	dy;
	int	err_x;
	int	err_y;
	int	sx;
	int	sy;
	int	x;
	int	y;
	int	color;
}	t_bressen;
typedef struct s_trans
{
	double	scale;
	double	z_scale;
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
}	t_trans;
typedef struct s_map
{
	int		max_z;
	int		min_z;
	int		width;
	int		height;
	char	*temp;
}	t_map;
typedef struct s_node
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_node;
typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bbp;
	int		line_length;
	int		endian;
}	t_mlx;
void		put_img_pixel(t_mlx *mlx, int x, int y, int color);
void		free_matrix(char **matrix, int y_counter);
int			rows_counter(char *argv, t_map *map);
int			count_words(char const *s, unsigned char c);
t_node		read_node(char *temp, int x, int y, t_map *map);
t_node		**read_map(char *argv, t_node **matrix, t_map *map);
t_node		*get_map_line(t_node *matrix, char *line, t_map *map, int y);
t_mlx		*graphic_init(t_node **matrix, t_map *map, t_trans *trans);
t_node		*get_map_line(t_node *matrix, char *line, t_map *map, int y);
t_map		*map_init(void);
t_trans		*trans_init(t_node **matrix, t_map *map);
void		bressen(t_node node1, t_node node2, t_mlx *mlx);
void		draw_map(t_node **matrix, t_map *map, t_mlx *mlx, t_trans *trans);
t_node		new_fig(t_node node, t_trans *trans, t_map *map);
void		esc_inputs(t_mlx *mlx);
int			isxdigit_fdf(char c);
void		exit_program(char *macro);
void		exit_free_map(char *macro, t_map *map);
void		exit_free_onlymatmap(t_node **matrix, t_map *map, int *fd);
void		exit_free_matmap_fd(t_map *map, t_node **matrix, int *fd);
void		exit_free_matmap(t_map *map, t_node **matrix);
void		exit_free_matmaptrans(t_map *map, t_node **matrix, t_trans *trans);
void		exit_all(t_map *map, t_node **matrix, t_trans *trans, t_mlx *mlx);
void		free_all(t_map *map, t_node **matrix, t_trans *trans, t_mlx *mlx);
void		file_checker(char *argv);
int			ft_abs(int num);
int			get_color(t_node node1, t_node node2, t_bressen vars);
int			get_blue(int color);
int			get_green(int color);
int			get_red(int color);
#endif
