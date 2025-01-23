/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:36:24 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/23 17:04:21 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void error_output()
{
	ft_printf("[USAGE] ./fractol mandelbrot");
	exit (1);
}

void ft_put_pixel(t_data *data, int x, int y, int color)
{
    char *pxl;

    if (x >= 0 && x < WINDOW_WIDTH  && y >= 0 && y < WINDOW_HEIGHT )
    {
        pxl = data->addr + (y  * data->line_length + x  * (data->bits_per_pixel / 8));
        *(unsigned int *)pxl = color;
    }
}

int main(int argc, char **argv)
{
	t_data img;
    void *mlx;
    void *mlx_win;
	
	if (!ft_strncmp(argv[0], "mandelbrot", 12) || argc != 2)
		error_output();
	mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fractol");
    img.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mandelbrot(&img);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);


}