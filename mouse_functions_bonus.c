#include "fdf.h"

int	mouse_press(int key, int x, int y, t_control *control)
{
	if (key == 1)
		control->trans->mouse_pressed = 1;
	if (key == 4)
		control->trans->scale += 1;
	if (key == 5)
		control->trans->scale -= 1;
	control->trans->last_x = x;
	control->trans->last_y = y;
	return (0);
}

int	mouse_hold(int x, int y, t_control *control)
{
	if (control->trans->mouse_pressed == 0)
		return (0);
	control->trans->x_pos += (x - control->trans->last_x);
	control->trans->y_pos += (y - control->trans->last_y);
	control->trans->last_x = x;
	control->trans->last_y = y;
	return (0);
}

int	mouse_release(int key, int x, int y, t_control *control)
{
	control->trans->mouse_pressed = 0;
	return (0);
}