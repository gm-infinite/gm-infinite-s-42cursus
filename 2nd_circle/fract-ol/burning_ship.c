/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:58:18 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/25 15:36:12 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_burning_ship_it(t_coordinate count, t_data *img, int color[])
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	c.x = (ft_map(count.x, +2 * img->mvmt.zoom - img->mvmt.x_offset, \
	-2 * img->mvmt.zoom - img->mvmt.x_offset, WINDOW_WIDTH));
	c.y = (ft_map(count.y, -2 * img->mvmt.zoom - img->mvmt.y_offset, \
	+2 * img->mvmt.zoom - img->mvmt.y_offset, WINDOW_HEIGHT));
	z.x = 0.0;
	z.y = 0.0;
	while (i < ITERATION - 1)
	{
		z = add_complex(square_complex(abs_complex(z)), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			ft_put_pixel(img, count.x, count.y, color[i]);
			return ;
		}
		i++;
	}
	ft_put_pixel(img, count.x, count.y, FT_COLOR6);
}

void	burning_ship(t_ft_window *wnd)
{
	t_coordinate	count;

	set_coordinate(&count, 0, 0);
	while (count.x < WINDOW_WIDTH)
	{
		count.y = 0;
		while (count.y < WINDOW_HEIGHT)
		{
			ft_burning_ship_it(count, &(wnd->img), wnd->color);
			count.y++;
		}
		count.x++;
	}
	mlx_put_image_to_window(wnd->mlx, wnd->mlx_window, wnd->img.img, 0, 0);
}
