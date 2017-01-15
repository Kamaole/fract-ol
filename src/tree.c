/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 16:49:58 by rmatos            #+#    #+#             */
/*   Updated: 2017/01/14 17:15:01 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_branch	*make_branch(int x, int y, int len, double rad)
{
	t_branch *result;

	result = (t_branch *)ft_memalloc(sizeof(t_branch));
	result->x = x;
	result->y = y;
	result->len = len;
	result->rad = rad;
	return (result);
}

void		put_branch(t_env *env, t_branch *branch, int i, double start)
{
	t_line		*left;
	t_line		*right;
	t_branch	*left_branch;
	t_branch	*right_branch;

	if (i == env->tree->max)
		return ;
	left = make_line(branch->x, branch->y, branch->x, branch->y - branch->len);
	right = make_line(branch->x, branch->y, branch->x, branch->y - branch->len);
	apply_zrot(left, start - env->tree->rad);
	apply_zrot(right, start + env->tree->rad);
	put_line(env->tree->img, left, branch->len);
	put_line(env->tree->img, right, branch->len);
	left_branch = make_branch(left->end->x, left->end->y,
		branch->len * .666666, branch->rad + env->tree->rad);
	right_branch = make_branch(right->end->x, right->end->y,
		branch->len * .666666, branch->rad - env->tree->rad);
	put_branch(env, left_branch, i + 1, start - env->tree->rad);
	put_branch(env, right_branch, i + 1, start + env->tree->rad);
}
