/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:40:51 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/25 15:21:25 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractals(t_ft_window *wnd, char **argv)
{
	if (!ft_strncmp((wnd->argv)[1], "mandelbrot", 12))
		mandelbrot(wnd);
	else if (!ft_strncmp((wnd->argv)[1], "julia", 6))
		julia(wnd, argv);
	else if (!ft_strncmp((wnd->argv)[1], "burningship", 13))
		burning_ship(wnd);
	else if (!ft_strncmp((wnd->argv)[1], "hexacorn", 9))
		hexacorn(wnd);
}
