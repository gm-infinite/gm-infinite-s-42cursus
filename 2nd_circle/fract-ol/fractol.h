/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:42:58 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/23 17:50:20 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
#include <stdio.h>

# define WINDOW_WIDTH 2000
# define WINDOW_HEIGHT 2000
# define PI 3.1415926535897932
# define ITERATION 500

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct	s_coordinate {
	int x;
	int y;
}			t_coordinate;

typedef struct	s_complex {
	double x;
	double y;
}			t_complex;

void set_coordinate(t_coordinate *vec, int nx, int ny);
void mandelbrot(t_data *img);
void ft_put_pixel(t_data *data, int x, int y, int color);
void set_complex(t_complex *a, double x, double y);
t_complex square_complex(t_complex a);
t_complex add_complex(t_complex a, t_complex b);

#endif