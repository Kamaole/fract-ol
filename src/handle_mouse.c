/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 19:28:41 by rmatos            #+#    #+#             */
/*   Updated: 2017/01/13 19:31:32 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	jul_mouse(int button, int x, int y, void *param)
{
	t_env *env;

	env = (t_env *)param;
	if (button == 5)
	{
		env->jul->scale *= .92;
		env->jul->x_off += (x - env->half_width) /
			(env->half_width / env->jul->scale) / 8;
		env->jul->y_off += (y - env->half_height) /
			(env->half_height / env->jul->scale) / 8;
	}
	if (button == 4)
	{
		env->jul->scale /= .92;
		env->jul->x_off -= (x - env->half_width)
			/ (env->half_width / env->jul->scale) / 8;
		env->jul->y_off -= (y - env->half_height)
			/ (env->half_height / env->jul->scale) / 8;
	}
	mlx_clear_window(env->mlx, env->jul->win);
	jul_thread(env);
	return (0);
}

int	man_mouse(int button, int x, int y, void *param)
{
	t_env *env;

	env = (t_env *)param;
	if (button == 5)
	{
		env->man->scale *= .92;
		env->man->x_off += (x - env->half_width)
			/ (env->half_width / env->man->scale) / 8;
		env->man->y_off += (y - env->half_height)
			/ (env->half_height / env->man->scale) / 8;
	}
	if (button == 4)
	{
		env->man->scale /= .92;
		env->man->x_off -= (x - env->half_width)
			/ (env->half_width / env->man->scale) / 8;
		env->man->y_off -= (y - env->half_height)
			/ (env->half_height / env->man->scale) / 8;
	}
	mlx_clear_window(env->mlx, env->man->win);
	man_thread(env);
	return (0);
}

int	handle_mouse_motion(int x, int y, t_env *env)
{
	if (env->jul->freeze)
		return (0);
	env->jul->c_re = (x - env->half_width)
		/ (env->half_width * env->jul->scale) + env->jul->x_off;
	env->jul->c_im = (y - env->half_height)
		/ (env->half_height * env->jul->scale) + env->jul->y_off;
	mlx_clear_window(env->mlx, env->jul->win);
	jul_thread(env);
	return (0);
}

int	tree_mouse(int button, int x, int y, void *param)
{
	t_env *env;

	x++;
	y--;
	env = (t_env *)param;
	if (button == 5)
		env->tree->rad -= .04;
	if (button == 4)
		env->tree->rad += .04;
	env->tree->img = make_img(env->mlx, env->width, env->height);
	tree(env);
	return (0);
}
