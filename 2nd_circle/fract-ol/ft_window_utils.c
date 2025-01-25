/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:43:38 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/25 15:53:40 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_ft_window(t_ft_window *wnd, char **argv)
{
	wnd->mlx = mlx_init();
	wnd->argv = argv;
	wnd->mlx_window = mlx_new_window(wnd->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, \
	"fract-ol");
	wnd->img.img = mlx_new_image(wnd->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	wnd->img.addr = mlx_get_data_addr(wnd->img.img, &(wnd->img.bits_per_pixel), \
	&(wnd->img.line_length), &(wnd->img.endian));
	wnd->img.mvmt = get_movement(0.0, 0.0, 1.0);
	set_color(wnd->color);
}
