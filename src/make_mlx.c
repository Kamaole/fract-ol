/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:34:33 by rmatos            #+#    #+#             */
/*   Updated: 2016/12/19 16:11:49 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img 	*make_img(void *mlx, int x, int y)
{
	t_img *result;

	result = (t_img *)ft_memalloc(sizeof(t_img));
	result->img = mlx_new_image(mlx, x, y);
	result->data = mlx_get_data_addr(result->img, &result->bits, &result->size_line, &result->endian);
	result->width = x;
	result->height = y;
	return (result);
}

t_jul 	*make_jul(void *mlx, int max, int x, int y)
{
	t_jul *result;
	result = (t_jul *)ft_memalloc(sizeof(t_jul));
	result->win = mlx_new_window(mlx, x, y, "julia");
	result->img = make_img(mlx, x, y);
	result->scale = 1.0;
	result->x_off= 0.0;
	result->y_off = 0.0;
	result->c_re = 0.0;
	result->c_im = 0.0;
	result->freeze = 0;
	result->max = max;
	return (result);
}

t_man 	*make_man(void *mlx, int max, int x, int y)
{
	t_man *result;

	result = (t_man *)ft_memalloc(sizeof(t_man));
	result->win = mlx_new_window(mlx, x, y, "mandelbrot");
	result->img = make_img(mlx, x, y);
	result->scale = 1.0;
	result->x_off = 0.0;
	result->y_off = 0.0;
	result->max = max;
	return (result);
}

t_tree 	*make_tree(void *mlx, double rad, int len, int max, int x, int y)
{
	t_tree *result;

	result = (t_tree *)ft_memalloc(sizeof(t_tree));
	result->win = mlx_new_window(mlx, x, y, "tree");
	result->img = make_img(mlx, x, y);
	result->rad = rad;
	result->len = len;
	result->max = max;
	return (result);
}

t_env	*make_env(int max, int x, int y, double rad, int len)
{
	void	*mlx;
	t_env	*result;

	mlx = mlx_init();
	result = (t_env *)ft_memalloc(sizeof(t_env));
	result->mlx = mlx;
	result->man = make_man(mlx, max, x, y);
	result->jul = make_jul(mlx, max, x, y);
	result->tree = make_tree(mlx, rad, len, 10, x, y);
	result->max = max;
	result->width = x;
	result->height = y;
	result->half_width = x / 2;
	result->half_height = y / 2;
	return (result);
}
