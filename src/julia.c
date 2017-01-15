/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 16:23:22 by rmatos            #+#    #+#             */
/*   Updated: 2017/01/14 16:24:47 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia_util(t_env *env, double x, double y)
{
	double	xx;
	double	yy;
	int		i;

	i = 0;
	x = 2 * (x - env->half_width) / (env->half_width)
		* env->jul->scale + env->jul->x_off;
	y = 2 * (y - env->half_height) / (env->half_height)
		* env->jul->scale + env->jul->y_off;
	xx = x * x;
	yy = y * y;
	while (i < env->jul->max && x * x + y * y <= 4)
	{
		y = (x + y) * (x + y) - xx - yy;
		y += env->jul->c_im;
		x = xx - yy + env->jul->c_re;
		xx = x * x;
		yy = y * y;
		i++;
	}
	return (i);
}

void	julia(t_env *env, int x, int y)
{
	int		i;
	int		ir;
	int		ic;
	double	ic_max;
	double	ir_max;

	ir = y * env->half_height;
	ir_max = y * env->half_width + env->half_width;
	ic_max = x * env->half_width + env->half_width;
	while (ir < ir_max)
	{
		ic = x * env->half_width;
		while (ic < ic_max)
		{
			i = julia_util(env, ic, ir);
			if (i < env->jul->max)
				pixel_to_img(env->jul->img, ic, ir, get_color(i));
			else
				pixel_to_img(env->jul->img, ic, ir, 0);
			ic++;
		}
		ir++;
	}
}
