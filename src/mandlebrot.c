/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandlebrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:08:55 by rmatos            #+#    #+#             */
/*   Updated: 2017/01/14 16:20:21 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandlebrot_util(t_env *env, double c_re, double c_im)
{
	double	x;
	double	y;
	double	xx;
	double	yy;
	int		i;

	i = 0;
	x = 0;
	y = 0;
	xx = x * x;
	yy = y * y;
	while (i < env->man->max && xx + yy <= 4.0)
	{
		y = (x + y) * (x + y) - xx - yy;
		y += c_im;
		x = xx - yy + c_re;
		xx = x * x;
		yy = y * y;
		i++;
	}
	return (i);
}

void	mandlebrot(t_env *env, int x, int y)
{
	t_manvar *vars;

	vars = (t_manvar *)ft_memalloc(sizeof(t_manvar));
	vars->ir = y * env->half_height - 1;
	vars->ic_buff = x * env->half_width;
	vars->ir_max = y * env->half_width + env->half_width;
	vars->ic_max = x * env->half_width + env->half_width;
	while (++vars->ir < vars->ir_max)
	{
		vars->ic = vars->ic_buff;
		vars->c_im = (1.5 * (vars->ir - env->half_height)
				/ env->half_width * env->man->scale) + env->man->y_off;
		while (vars->ic < vars->ic_max)
		{
			vars->c_re = (1.5 * (vars->ic - env->half_width)
					/ env->half_width * env->man->scale) + env->man->x_off;
			if ((vars->i = mandlebrot_util(env, vars->c_re, vars->c_im))
					< env->man->max)
				pixel_to_img(env->man->img, vars->ic,
						vars->ir, get_color(vars->i));
			else
				pixel_to_img(env->man->img, vars->ic, vars->ir, RGB_BLACK);
			vars->ic++;
		}
	}
}
