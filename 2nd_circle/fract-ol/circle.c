/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:44:37 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/21 15:55:22 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define	WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000

void ft_put_pixel(t_data *data, int x, int y, int color)
{
    char *pxl;

    if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
    {
        pxl = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int *)pxl = color;
    }
}

void put_circle(t_data *data, int radius)
{
	int x;
	int y;

	x = 0;
	y = 0;
	int tx = x;
	int ty = y;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		tx = x - 500;
		while (y < WINDOW_HEIGHT)
		{
			ty = y - 500;
			if (pow(pow((tx), 2) + pow((ty), 2), 0.5) < (radius + 10 ) / 2 && pow(pow((tx), 2) + pow((ty), 2), 0.5) > (radius - 10 ) / 2)
				ft_put_pixel(data, x, y, 0X03c6fc);
			else
				ft_put_pixel(data, x, y, 0X002552);
			printf("x:%d y:%d\n", x, y);
			y++;
		}
		x++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	put_circle(&img, 1000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
