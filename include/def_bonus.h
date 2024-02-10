/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:47:38 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/02/09 17:47:40 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_BONUS_H
# define DEF_BONUS_H 

typedef struct s_control
{
	t_node	**matrix;
	t_map	*map;
	t_mlx	*mlx;
	t_trans	*trans;
}	t_control;
void		inputs(t_control *control);
t_control	*control_init(t_map *map, t_mlx *mlx,
				t_node **matrix, t_trans *trans);
t_node		rot_x(t_node node, t_trans *trans);
t_node		rot_y(t_node node, t_trans *trans);
t_node		rot_z(t_node node, t_trans *trans);
t_bressen	bressen_vars_init(t_node node1, t_node node2);
int			mouse_press(int key, int x, int y, t_control *control);
int			mouse_hold(int x, int y, t_control *control);
int			key_input(int key, t_control *control);
int			mouse_release(int x, int y, int key, t_control *control);
void		control_reset(t_control *control);
void		negative_rotation_z(t_control *trans);
void		negative_rotation_y(t_control *trans);
void		negative_rotation_x(t_control *trans);
void		constant_rotation_x(t_control *control);
void		constant_rotation_y(t_control *control);
t_node		new_fig_bonus(t_node node, t_trans *trans, t_map *map);
int			render_frame(t_control *control);
#endif
