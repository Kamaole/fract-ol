#include "fractol.h"
#include <stdio.h>

void	apply_zrot(t_line *line, double radians)
{
	t_pointmath *math;
	math = (t_pointmath *)ft_memalloc(sizeof(t_pointmath));
	if (radians == .0)
		return ;
	math->x = line->end->x - line->start->x;
	math->y = line->end->y - line->start->y;
	math->d = hypot(math->y, math->x);
	math->theta = atan2(math->y, math->x) + radians;
	line->end->x = line->start->x + math->d * cos(math->theta);
	line->end->y = line->start->y + math->d * sin(math->theta);
}
