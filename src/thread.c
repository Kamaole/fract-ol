/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 16:25:04 by rmatos            #+#    #+#             */
/*   Updated: 2017/01/14 16:25:59 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_thrarg	*create_thread(t_env *env, int x, int y)
{
	t_thrarg *thr;

	thr = (t_thrarg *)ft_memalloc(sizeof(t_thrarg));
	thr->env = env;
	thr->quad_x = x;
	thr->quad_y = y;
	return (thr);
}

void		man_thread(t_env *env)
{
	static pthread_t *thrs;

	if (!thrs)
		thrs = (pthread_t *)ft_memalloc(sizeof(pthread_t ) * 4);
	pthread_create(&thrs[0], NULL, run_mandelbrot, create_thread(env, 0, 0));
	pthread_create(&thrs[1], NULL, run_mandelbrot, create_thread(env, 0, 1));
	pthread_create(&thrs[2], NULL, run_mandelbrot, create_thread(env, 1, 0));
	pthread_create(&thrs[3], NULL, run_mandelbrot, create_thread(env, 1, 1));
	pthread_join(thrs[0], NULL);
	pthread_join(thrs[1], NULL);
	pthread_join(thrs[2], NULL);
	pthread_join(thrs[3], NULL);
	mlx_put_image_to_window(env->mlx, env->man->win, env->man->img->img, 0, 0);
}

void		jul_thread(t_env *env)
{
	static pthread_t *thrs;

	if (!thrs)
		thrs = (pthread_t *)ft_memalloc(sizeof(pthread_t ) * 4);
	pthread_create(&thrs[0], NULL, run_julia, create_thread(env, 0, 0));
	pthread_create(&thrs[1], NULL, run_julia, create_thread(env, 0, 1));
	pthread_create(&thrs[2], NULL, run_julia, create_thread(env, 1, 0));
	pthread_create(&thrs[3], NULL, run_julia, create_thread(env, 1, 1));
	pthread_join(thrs[0], NULL);
	pthread_join(thrs[1], NULL);
	pthread_join(thrs[2], NULL);
	pthread_join(thrs[3], NULL);
	mlx_put_image_to_window(env->mlx, env->jul->win, env->jul->img->img, 0, 0);
}
