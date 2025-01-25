/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:06:18 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/25 15:51:56 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_movement	get_movement(double x, double y, double zoom)
{
	t_movement	ret;

	ret.x_offset = x;
	ret.y_offset = y;
	ret.zoom = zoom;
	return (ret);
}

t_movement	movement_zoom(t_movement old, double zoom_val)
{
	t_movement	ret;

	ret.x_offset = old.x_offset;
	ret.y_offset = old.y_offset;
	ret.zoom = (zoom_val * old.zoom);
	return (ret);
}

t_movement	movement_xof(t_movement old, double xof_val)
{
	t_movement	ret;

	ret.x_offset = old.x_offset + xof_val;
	ret.y_offset = old.y_offset;
	ret.zoom = old.zoom;
	return (ret);
}

t_movement	movement_yof(t_movement old, double yof_val)
{
	t_movement	ret;

	ret.x_offset = old.x_offset;
	ret.y_offset = old.y_offset + yof_val;
	ret.zoom = old.zoom;
	return (ret);
}
