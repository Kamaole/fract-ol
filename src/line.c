#include "fractol.h"
#include <stdio.h>
t_point *make_point(int x, int y)
{
	t_point *result;

	result = (t_point *)ft_memalloc(sizeof(t_point));
	result->x = x;
	result->y = y;
	return (result);
}

t_line 	*make_line(int x0, int y0, int x1, int y1)
{
	t_line	*result;

	result = (t_line *)ft_memalloc(sizeof(t_line));
	result->start = make_point(x0, y0);
	result->end = make_point(x1, y1);
	return (result);
}

int 	line_len(int x0, int y0, int x1, int y1)
{
	int xx;
	int yy;

	xx = (x1 - x0) * (x1 - x0);
	yy = (y1 - y0) * (y1 - y0);
	return sqrt(xx + yy);
}

void 	put_line(t_img *img_data, t_line *line, int len)
{
	t_linevars *vars;

	if (line_len(line->start->x, line->start->y, line->end->x, line->end->y) == 0)
		return;
	vars = (t_linevars *)ft_memalloc(sizeof(t_linevars));
	vars->dx = abs(line->end->x - line->start->x);
	vars->dy = abs(line->end->y - line->start->y);
	vars->sx = (line->start->x < line->end->x) ? 1 : -1;
	vars->sy = (line->start->y < line->end->y) ? 1 : -1;
	vars->err = (vars->dx > vars->dy ? vars->dx : -(vars->dy)) / 2;
	vars->cur_x = line->start->x;
	vars->cur_y = line->start->y;
	while(!(vars->cur_x == line->end->x && vars->cur_y == line->end->y)
		&& line_len(line->start->x, line->start->y, vars->cur_x, vars->cur_y) < len)
	{
		pixel_to_img(img_data, vars->cur_x, vars->cur_y, RGB_PURP);
		vars->err_tmp = vars->err;
		if (vars->err_tmp > -(vars->dx))
		{
			vars->err -= vars->dy;
			vars->cur_x += vars->sx;
		}
		if (vars->err_tmp < vars->dy)
		{
			vars->err += vars->dx;
			vars->cur_y += vars->sy;
		}
	}
	pixel_to_img(img_data, vars->cur_x, vars->cur_y, RGB_PURP);
	line->end->x = vars->cur_x;
	line->end->y = vars->cur_y;

}

t_branch *make_branch(int x, int y, int len, double rad)
{
	t_branch *result;

	result = (t_branch *)ft_memalloc(sizeof(t_branch));
	result->x = x;
	result->y = y;
	result->len = len;
	result->rad = rad;
	return (result);
}

void 	put_branch(t_img *img_data, t_branch *branch, int i, int max, double rad, double start)
{
	t_line *left;
	t_line *right;
	t_branch *left_branch;
	t_branch *right_branch;

	if (i == max)
		return ;
	left = make_line(branch->x, branch->y, branch->x, branch->y - branch->len);
	right = make_line(branch->x, branch->y, branch->x, branch->y - branch->len);
	apply_zrot(left, start - rad);
	apply_zrot(right, start + rad);

	put_line(img_data, left, branch->len);
	put_line(img_data, right, branch->len);
	left_branch = make_branch(left->end->x, left->end->y, branch->len * .666666, branch->rad + rad);
	right_branch = make_branch(right->end->x, right->end->y, branch->len * .666666, branch->rad - rad);
	put_branch(img_data, left_branch, i + 1, max, rad, start - rad);
	put_branch(img_data, right_branch, i + 1, max, rad, start + rad);

}
