#include "fdf.h"

void	control_reset(t_control *control)
{
	control->trans->scale = 0;
	control->trans->z_scale = 1;
	control->trans->x_pos = 0;
	control->trans->y_pos = 0;
	control->trans->x_rot = 0;
	control->trans->y_rot = 0;
	control->trans->z_rot = 0;
}
