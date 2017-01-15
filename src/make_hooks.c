/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 18:14:28 by rmatos            #+#    #+#             */
/*   Updated: 2017/01/14 18:14:29 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_hooks(t_env *env, int fractal)
{
	if (fractal == 0)
	{
		mlx_mouse_hook(env->man->win, man_mouse, env);
		mlx_key_hook(env->man->win, man_key, env);
		mlx_expose_hook(env->man->win, man_expose, env);
		man_thread(env);
	}
	if (fractal == 1)
	{
		mlx_mouse_hook(env->jul->win, jul_mouse, env);
		mlx_key_hook(env->jul->win, jul_key, env);
		mlx_hook(env->jul->win, 6, 0, handle_mouse_motion, env);
		mlx_expose_hook(env->jul->win, jul_expose, env);
		jul_thread(env);
	}
	if (fractal == 2)
	{
		mlx_mouse_hook(env->tree->win, tree_mouse, env);
		mlx_key_hook(env->tree->win, tree_key, env);
		mlx_expose_hook(env->tree->win, tree_expose, env);
		tree(env);
	}
}
