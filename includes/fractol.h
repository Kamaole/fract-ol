/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:44:29 by rmatos            #+#    #+#             */
/*   Updated: 2016/12/19 16:08:11 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
#include <pthread.h>

# define RGB_BLACK 0x000000
# define RGB_PURP 0xBE00FF

typedef struct	s_img
{
	void 		*img;
	char 		*data;
	int 		bits;
	int 		size_line;
	int 		endian;
	int 		width;
	int 		height;
}				t_img;

typedef struct 	s_jul
{
	void 		*win;
	t_img 		*img;
	double 		scale;
	double		x_off;
	double 		y_off;
	double 		c_re;
	double 		c_im;
	int 		freeze;
	int 		max;
} 				t_jul;

typedef struct 	s_tree
{
	void 		*win;
	t_img 		*img;
	double 		rad;
	int 		len;
	int 		max;
}				t_tree;

typedef struct 	s_man
{
	void 		*win;
	t_img 		*img;
	double 		scale;
	double 		x_off;
	double 		y_off;
	int 		max;
}				t_man;

typedef	struct	s_env
{
	void		*mlx;
	t_man 		*man;
	t_jul		*jul;
	t_tree 		*tree;
	int 		max;
	int			width;
	int			height;
	int			half_width;
	int			half_height;
}				t_env;



typedef struct	s_thrarg
{
	t_env		*env;
	int			quad_x;
	int			quad_y;
}				t_thrarg;

typedef struct	s_linevars
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			err_tmp;
	int 		cur_x;
	int 		cur_y;
}				t_linevars;

typedef struct 	s_point
{
	int 		x;
	int			y;
}				t_point;

typedef struct	s_line
{
	t_point 	*start;
	t_point 	*end;
}				t_line;

typedef	struct	s_pointmath
{
	double		x;
	double		y;
	double		z;
	double		d;
	double		theta;
}				t_pointmath;

typedef struct	s_branch
{
	int			x;
	int 		y;
	int 		len;
	double 		rad;
}				t_branch;

void 	pixel_to_img(t_img *img_data, int x, int y, int color);
void	mandlebrot(t_env *env, int x, int y);
void	julia(t_env *env, int x, int y);
t_img 	*make_img(void *mlx, int x, int y);
t_line 	*make_line(int x0, int y0, int x1, int y1);
void 	put_line(t_img *img_data, t_line *line, int len);
void	apply_zrot(t_line *line, double radians);
int 	line_len(int x0, int y0, int x1, int y1);
t_branch *make_branch(int x, int y, int len, double rad);
void 	put_branch(t_img *img_data, t_branch *branch, int i, int max, double rad, double start);
t_env	*make_env(int max, int x, int y, double rad, int len);
t_line 	*make_line(int x0, int y0, int x1, int y1);
int jul_key(int keycode, t_env *env);
int man_key(int keycode, t_env *env);
int tree_key(int keycode, t_env *env);
int	tree_mouse(int button, int x, int y, void *param);
int handle_mouse_motion(int x, int y, t_env *env);
int	jul_mouse(int button, int x, int y, void *param);
int	man_mouse(int button, int x, int y, void *param);
void 		*run_mandelbrot(void *param);
void 		*run_julia(void *param);
t_thrarg	*create_thread(t_env *env, int x, int y);
void 	man_thread(t_env *env);
void 	jul_thread(t_env *env);
void 	tree(t_env *env);
void 	run_fractals(char **argv);

#endif
