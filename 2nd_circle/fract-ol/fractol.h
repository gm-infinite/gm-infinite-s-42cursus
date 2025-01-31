/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:42:58 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/29 16:35:40 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <math.h>

# define WINDOW_WIDTH 1500
# define WINDOW_HEIGHT 1500
# define ITERATION 50
# define FT_COLOR1	0xcc0000
# define FT_COLOR2	0xcccc00
# define FT_COLOR3	0x44cc44
# define FT_COLOR4	0x0000cc
# define FT_COLOR5	0xcc00cc
# define FT_COLOR6	0x000000

typedef struct s_movement
{
	double	x_offset;
	double	y_offset;
	double	zoom;
}			t_movement;

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_movement	mvmt;
}			t_data;

typedef struct s_ft_window {
	t_data	img;
	void	*mlx;
	void	*mlx_window;
	int		color[ITERATION];
	char	**argv;
}		t_ft_window;

typedef struct s_coordinate {
	int	x;
	int	y;
}			t_coordinate;

typedef struct s_complex {
	double	x;
	double	y;
}			t_complex;

typedef struct s_trgb {
	unsigned char	t;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}		t_trgb;

void		set_coordinate(t_coordinate *vec, int nx, int ny);
void		mandelbrot(t_ft_window *wnd);
void		ft_put_pixel(t_data *data, int x, int y, int color);
void		set_complex(t_complex *a, double x, double y);
t_complex	square_complex(t_complex a);
t_complex	add_complex(t_complex a, t_complex b);
void		set_ft_window(t_ft_window *wnd, char **argv);
double		ft_map(double unscaled_num, double new_min, double new_max, \
			double old_max);
void		set_color(int *color);
void		color_shift_left(int *color);
void		color_shift_right(int *color);
int			key_handler(int keycode, t_ft_window *wnd);
void		fractals(t_ft_window *wnd, char **argv);
double		ft_atod(const char *str);
void		julia(t_ft_window *wnd, char **argv);
t_movement	get_movement(double x, double y, double zoom);
t_movement	movement_zoom(t_movement old, double zoom_val);
t_movement	movement_xof(t_movement old, double xof_val);
t_movement	movement_yof(t_movement old, double yof_val);
int			mouse_handler(int button, int x, int y, t_ft_window *wnd);
t_complex	sub_complex(t_complex a, t_complex b);
t_complex	div_complex(t_complex a, t_complex b);
t_complex	mult_complex(t_complex a, t_complex b);
t_complex	get_complex(double x, double y);
void		burning_ship(t_ft_window *wnd);
t_complex	abs_complex(t_complex a);
int			close_handler(t_ft_window *wnd);
void		hexacorn(t_ft_window *wnd);

#endif