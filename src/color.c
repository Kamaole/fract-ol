/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 17:40:21 by rmatos            #+#    #+#             */
/*   Updated: 2017/01/14 17:40:23 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color1(int i)
{
	static int map[64] = {
	0xFF0005, 0xFE1100, 0xFE2900, 0xFE4100,
	0xFD5800, 0xFD7000, 0xFD8700, 0xFD9F00,
	0xFCB600, 0xFCCE00, 0xFCE500, 0xFBFB00,
	0xE3FB00, 0xCBFB00, 0xB4FB00, 0x9CFA00,
	0x85FA00, 0x6DFA00, 0x56F900, 0x3FF900,
	0x27F900, 0x10F900, 0x00F808, 0x00F81F,
	0x00F836, 0x00F74D, 0x00F764, 0x00F77B,
	0x00F791, 0x00F6A8, 0x00F6BF, 0x01F6D6,
	0x01F5EC, 0x01E7F5, 0x01D0F5, 0x01B9F5,
	0x01A2F4, 0x018CF4, 0x0175F4, 0x015EF3,
	0x0147F3, 0x0131F3, 0x011AF3, 0x0104F2,
	0x1501F2, 0x2B01F2, 0x4201F1, 0x5801F1,
	0x6E01F1, 0x8501F0, 0x9B01F0, 0xB101F0,
	0xC701F0, 0xDD01EF, 0xEF01EB, 0xEF01D5,
	0xEF01BF, 0xEE01A8, 0xEE0192, 0xEE017C,
	0xED0166, 0xED0150, 0xED0139, 0xED0123};

	return (map[i]);
}

int		get_color(int i)
{
	if (i <= 63)
		return (get_color1(i));
	if (i >= 64 && i <= 127)
		return (get_color1(i - 64));
	if (i >= 128 && i <= 191)
		return (get_color1(i - 128));
	if (i >= 192 && i <= 255)
		return (get_color1(i - 192));
	return (0);
}
