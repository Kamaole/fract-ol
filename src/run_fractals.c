#include "fractol.h"

void 		*run_mandelbrot(void *param)
{
	t_thrarg *args;

	args = (t_thrarg *)param;
	mandlebrot(args->env, args->quad_x, args->quad_y);
	return (args);
}

void 		*run_julia(void *param)
{
	t_thrarg *args;

	args = (t_thrarg *)param;
	julia(args->env, args->quad_x, args->quad_y);
	return (args);
}

t_thrarg	*create_thread(t_env *env, int x, int y)
{
	t_thrarg *thr;

	thr = (t_thrarg *)ft_memalloc(sizeof(t_thrarg));
	thr->env = env;
	thr->quad_x = x;
	thr->quad_y = y;
	return (thr);
}

void 	man_thread(t_env *env)
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

void 	jul_thread(t_env *env)
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

void 	tree(t_env *env)
{
	t_line		*base;
	t_branch	*branch;

	base = make_line(env->half_width, env->height - 1, env->half_width, env->height - 1 - env->tree->len);
	put_line(env->tree->img, base, env->tree->len - 1);
	branch = make_branch(env->half_width, env->height - env->tree->len, env->tree->len, env->tree->rad);
	put_branch(env->tree->img, branch, 0, env->tree->max, env->tree->rad, 0);
	mlx_put_image_to_window(env->mlx, env->tree->win, env->tree->img->img, 0, 0);
}

void 	run_fractals(char **argv)
{
	t_env *env;

	env = make_env(ft_atoi(argv[1]), 1000, 1000, .5, 200);
	mlx_mouse_hook(env->man->win, man_mouse, env);
	mlx_mouse_hook(env->jul->win, jul_mouse, env);
	mlx_mouse_hook(env->tree->win, tree_mouse, env);
	mlx_key_hook(env->jul->win, jul_key, env);
	mlx_key_hook(env->man->win, man_key, env);
	mlx_key_hook(env->tree->win, tree_key, env);
	mlx_hook(env->jul->win, 6, 0, handle_mouse_motion, env);
	man_thread(env);
	jul_thread(env);
	tree(env);
	mlx_loop(env->mlx);
}
