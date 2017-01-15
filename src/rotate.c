/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 16:26:13 by rmatos            #+#    #+#             */
/*   Updated: 2017/01/14 16:26:44 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	apply_zrot(t_line *line, double radians)
{
	t_pointmath *math;

	math = (t_pointmath *)ft_memalloc(sizeof(t_pointmath));
	if (radians == .0)
		return ;
	math->x = line->end->x - line->start->x;
	math->y = line->end->y - line->start->y;
	math->d = hypot(math->y, math->x);
	math->theta = atan2(math->y, math->x) + radians;
	line->end->x = line->start->x + math->d * cos(math->theta);
	line->end->y = line->start->y + math->d * sin(math->theta);
}
