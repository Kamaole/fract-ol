/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:44:29 by rmatos            #+#    #+#             */
/*   Updated: 2017/01/14 17:41:02 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <pthread.h>

# define RGB_BLACK 0x000000
# define RGB_PURP 0xBE00FF

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bits;
	int			size_line;
	int			endian;
	int			height;
	int			width;
}				t_img;

typedef	struct	s_jul
{
	void		*win;
	t_img		*img;
	double		scale;
	double		x_off;
	double		y_off;
	double		c_re;
	double		c_im;
	int			freeze;
	int			max;
}				t_jul;

typedef	struct	s_tree
{
	void		*win;
	t_img		*img;
	double		rad;
	int			len;
	int			max;
}				t_tree;

typedef	struct	s_man
{
	void		*win;
	t_img		*img;
	double		scale;
	double		x_off;
	double		y_off;
	int			max;
}				t_man;

typedef	struct	s_manvar
{
	int			i;
	int			ir;
	int			ic;
	double		c_re;
	double		c_im;
	double		ic_buff;
	double		ic_max;
	double		ir_max;
}				t_manvar;

typedef	struct	s_env
{
	void		*mlx;
	t_man		*man;
	t_jul		*jul;
	t_tree		*tree;
	int			max;
	int			height;
	int			width;
	int			half_height;
	int			half_width;
}				t_env;

typedef	struct	s_linevars
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			err_tmp;
	int			cur_x;
	int			cur_y;
}				t_linevars;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef	struct	s_line
{
	t_point		*start;
	t_point		*end;
}				t_line;

typedef	struct	s_pointmath
{
	double		x;
	double		y;
	double		z;
	double		d;
	double		theta;
}				t_pointmath;

typedef	struct	s_branch
{
	int			x;
	int			y;
	int			len;
	double		rad;
}				t_branch;

typedef	struct	s_thrarg
{
	t_env		*env;
	int			quad_x;
	int			quad_y;
}				t_thrarg;

int				jul_key(int keycode, t_env *env);
int				man_key(int keycode, t_env *env);
int				tree_key(int keycode, t_env *env);
int				jul_mouse(int button, int x, int y, void *param);
int				man_mouse(int button, int x, int y, void *param);
int				handle_mouse_motion(int x, int y, t_env *env);
int				tree_mouse(int button, int x, int y, void *param);
int				julia_util(t_env *env, double x, double y);
void			julia(t_env *env, int x, int y);
t_point			*make_point(int x, int y);
t_line			*make_line(int x0, int y0, int x1, int y1);
int				line_len(int x0, int y0, int x1, int y1);
t_linevars		*get_linevars(t_line *line);
void			put_line(t_img *img_data, t_line *line, int len);
t_img			*make_img(void *mlx, int x, int y);
t_jul			*make_jul(void *mlx, int x, int y);
t_man			*make_man(void *mlx, int x, int y);
t_tree			*make_tree(void *mlx, int x, int y);
t_env			*make_env(int x, int y, int fractal);
int				mandlebrot_util(t_env *env, double c_re, double c_im);
void			mandlebrot(t_env *env, int x, int y);
void			pixel_to_img(t_img *img_data, int x, int y, int color);
void			apply_zrot(t_line *line, double radians);
void			tree(t_env *env);
void			*run_mandelbrot(void *param);
void			*run_julia(void *param);
int				what_fractal(char **argv);
void			run_fractals(char **argv);
t_thrarg		*create_thread(t_env *env, int x, int y);
void			man_thread(t_env *env);
void			jul_thread(t_env *env);
t_branch		*make_branch(int x, int y, int len, double rad);
void			put_branch(t_env *env, t_branch *branch, int i, double start);
int				get_color(int i);

#endif
