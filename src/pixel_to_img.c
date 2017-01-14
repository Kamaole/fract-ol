#include "fractol.h"

void 	pixel_to_img(t_img *img_data, int x, int y, int color)
{
	int p;

	if (x < 0 || y < 0 || x >= img_data->width || y >= img_data->height)
		return ;
	p = (x * 4) + (y * img_data->size_line);
	img_data->data[p] = color & 0xFF;
	img_data->data[++p] = (color >> 8) & 0xFF;
	img_data->data[++p] = (color >>  16) & 0xFF;
}
