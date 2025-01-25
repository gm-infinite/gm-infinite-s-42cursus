/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:40:36 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/25 15:51:19 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	key_handler2(int keycode, t_ft_window *wnd, int shift_lock)
{
	if (keycode == XK_Down)
		wnd->img.mvmt = movement_yof(wnd->img.mvmt, (-0.25 - \
		shift_lock * 0.20) * wnd->img.mvmt.zoom);
	else if (keycode == XK_Left)
		wnd->img.mvmt = movement_xof(wnd->img.mvmt, (-0.25 - \
		shift_lock * 0.20) * wnd->img.mvmt.zoom);
	else if (keycode == XK_Right)
		wnd->img.mvmt = movement_xof(wnd->img.mvmt, (+0.25 + \
		shift_lock * 0.20) * wnd->img.mvmt.zoom);
	else if (keycode == XK_Escape)
	{
		mlx_destroy_image(wnd->mlx, (wnd->img.img));
		mlx_destroy_window(wnd->mlx, wnd->mlx_window);
		mlx_destroy_display(wnd->mlx);
		free(wnd->mlx);
		exit (0);
	}
}

int	key_handler(int keycode, t_ft_window *wnd)
{
	static int	shift_lock = 0;

	if (keycode == XK_k)
		color_shift_right(wnd->color);
	else if (keycode == XK_j)
		color_shift_left(wnd->color);
	else if (keycode == XK_r)
		wnd->img.mvmt = get_movement(0.0, 0.0, 1.0);
	else if (keycode == XK_Shift_R)
		shift_lock = shift_lock ^ 1;
	else if (keycode == XK_Up)
		wnd->img.mvmt = movement_yof(wnd->img.mvmt, (+0.25 + \
		shift_lock * 0.20) * wnd->img.mvmt.zoom);
	else
		key_handler2(keycode, wnd, shift_lock);
	fractals(wnd, wnd->argv);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_ft_window *wnd)
{
	if (wnd->img.mvmt.zoom < 0.000000001)
		return (0);
	if (button == 4)
		wnd->img.mvmt = get_movement(wnd->img.mvmt.x_offset + 0.1 * \
		ft_map(x, -2, +2, WINDOW_WIDTH - 1) * wnd->img.mvmt.zoom, \
		wnd->img.mvmt.y_offset + 0.1 * ft_map(y, +2, -2, WINDOW_WIDTH - 1) \
		* wnd->img.mvmt.zoom, 0.909090909090909 * wnd->img.mvmt.zoom);
	if (button == 5)
		wnd->img.mvmt = get_movement(wnd->img.mvmt.x_offset + 0.1 * \
		ft_map(x, -2, +2, WINDOW_WIDTH - 1) * wnd->img.mvmt.zoom, \
		wnd->img.mvmt.y_offset + 0.1 * ft_map(y, +2, -2, WINDOW_WIDTH - 1) \
		* wnd->img.mvmt.zoom, 1.1 * wnd->img.mvmt.zoom);
	fractals(wnd, wnd->argv);
	return (0);
}

int	close_handler(t_ft_window *wnd)
{
	mlx_destroy_image(wnd->mlx, (wnd->img.img));
	mlx_destroy_window(wnd->mlx, wnd->mlx_window);
	mlx_destroy_display(wnd->mlx);
	free(wnd->mlx);
	exit (0);
}
