/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:58:18 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/23 18:03:09 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double ft_map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

static void	ft_mandelbrot_it(t_coordinate count, t_data *img)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	c.x = (ft_map(count.x, -2, +2, 0, WINDOW_WIDTH) );
	c.y = (ft_map(count.y, +2, -2, 0, WINDOW_HEIGHT)) ;
	z.x = 0.0;
	z.y = 0.0;
	while (i < ITERATION - 1)
	{
		z = add_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = ft_map(i, 0x000000, 0xF0F0F0, 0, ITERATION);
			ft_put_pixel(img, count.x, count.y, color);
			return ;
		}
		++i;	
	}
	ft_put_pixel(img, count.x, count.y, 0x660066);
}

void mandelbrot(t_data *img)
{
	t_coordinate count;

	set_coordinate(&count, 0,0);
	while (count.x < WINDOW_WIDTH)
	{
		count.y = 0;
		while (count.y < WINDOW_HEIGHT)
		{
			ft_mandelbrot_it(count, img);
			count.y++;
		}
		count.x++;
	}
}
