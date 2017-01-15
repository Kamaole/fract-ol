/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fractals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:17:26 by rmatos            #+#    #+#             */
/*   Updated: 2017/01/14 18:08:51 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	tree(t_env *env)
{
	t_line		*base;
	t_branch	*branch;

	base = make_line(env->half_width, env->height - 1,
			env->half_width, env->height - 1 - env->tree->len);
	put_line(env->tree->img, base, env->tree->len - 1);
	branch = make_branch(env->half_width, env->height - env->tree->len,
			env->tree->len, env->tree->rad);
	put_branch(env, branch, 0, 0);
	mlx_put_image_to_window(env->mlx, env->tree->win,
			env->tree->img->img, 0, 0);
}

void	*run_mandelbrot(void *param)
{
	t_thrarg *args;

	args = (t_thrarg *)param;
	mandlebrot(args->env, args->quad_x, args->quad_y);
	return (args);
}

void	*run_julia(void *param)
{
	t_thrarg *args;

	args = (t_thrarg *)param;
	julia(args->env, args->quad_x, args->quad_y);
	return (args);
}

int		what_fractal(char **argv)
{
	if (ft_strcmp(argv[1], "man") == 0)
		return (0);
	if (ft_strcmp(argv[1], "jul") == 0)
		return (1);
	if (ft_strcmp(argv[1], "tree") == 0)
		return (2);
	return (-1);
}

void	run_fractals(char **argv)
{
	int		fractal;
	t_env	*env;

	fractal = what_fractal(argv);
	env = make_env(1000, 1000, fractal);
	make_hooks(env, fractal);
	mlx_loop(env->mlx);
}
