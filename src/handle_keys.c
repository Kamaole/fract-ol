#include "fractol.h"
#include "stdio.h"

int 	jul_key(int keycode, t_env *env)
{
		if (keycode == 3)
		{
			if (env->jul->freeze)
				env->jul->freeze = 0;
			else
				env->jul->freeze = 1;
		}
		if (keycode == 69)
			env->jul->max += 10;
		if (keycode == 78)
			env->jul->max -= 10;
		mlx_clear_window(env->mlx, env->jul->win);
		jul_thread(env);
		printf("keycode: %i\n", keycode);
		return (0);
}

int 	man_key(int keycode, t_env *env)
{
	if (keycode == 69)
		env->man->max += 10;
	if (keycode == 78)
		env->man->max -= 10;
	mlx_clear_window(env->mlx, env->man->win);
	man_thread(env);
	printf("keycode: %i\n", keycode);
	return (0);
}

int 	tree_key(int keycode, t_env *env)
{
	if (keycode == 69 && env->tree->max <= 12)
		env->tree->max += 1;
	if (keycode == 78 && env->tree->max > 0)
		env->tree->max -= 1;
	env->tree->img = make_img(env->mlx, env->width, env->height);
	tree(env);
	return (0);
}
