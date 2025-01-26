/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:36:24 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/26 10:57:30 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_output(char **argv, int argc)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 12))
		return ;
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 7))
		return ;
	else if (argc == 2 && !ft_strncmp(argv[1], "burningship", 13))
		return ;
	else if (argc == 2 && !ft_strncmp(argv[1], "hexacorn", 9))
		return ;
	else
		ft_printf("[USAGE]:./fractol mandelbrot\n \
       ./fractol julia [double] [double]\n \
       ./fractol burningship\n \
       ./fractol hexacorn\n");
	exit(1);
}

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		pxl = data->addr + (y * data->line_length + \
		x * (data->bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
	}
}

int	main(int argc, char **argv)
{
	t_ft_window	wnd;

	error_output(argv, argc);
	set_ft_window(&wnd, argv);
	fractals(&wnd, argv);
	mlx_key_hook(wnd.mlx_window, key_handler, &wnd);
	mlx_mouse_hook(wnd.mlx_window, mouse_handler, &wnd);
	mlx_hook(wnd.mlx_window, 17, 0, close_handler, &wnd);
	mlx_loop((wnd.mlx));
}
