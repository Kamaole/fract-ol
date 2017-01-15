/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_expose.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 18:14:40 by rmatos            #+#    #+#             */
/*   Updated: 2017/01/14 18:14:42 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	tree_expose(void *param)
{
	tree((t_env *)param);
	return (0);
}

int	man_expose(void *param)
{
	t_env *env;

	env = (t_env *)param;
	mlx_clear_window(env->mlx, env->man->win);
	man_thread(env);
	return (0);
}

int	jul_expose(void *param)
{
	t_env *env;

	env = (t_env *)param;
	mlx_clear_window(env->mlx, env->jul->win);
	jul_thread(env);
	return (0);
}
