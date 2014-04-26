/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 16:55:03 by grass-kw          #+#    #+#             */
/*   Updated: 2014/04/20 15:35:35 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
void	draw_line(t_env *data, t_point A, t_point B)
{
	int		dx;
	int		dy;
	int		e;

	e = B.x - A.x;
	dx = e * 2;
	dy = (B.y - A.y) * 2;
	while (A.x <= B.x)
	{
		mlx_put_pixel_to_img(e, 0xFF0000, A.x, A.y);
		//mlx_pixel_put(data->mlx, data->win, A.x, A.y, 0xFF0000);
		A.x = A.x + 1;
		e -= dy;
		if (e <= 0)
		{
			A.y++;
			e += dx;
		}
	}
}

void	draw_line2(t_env *data, t_point A, t_point B)
{
	int		dx;
	int		dy;
	int		e;

	e = B.x - A.x;
	dx = e * 2;
	dy = (B.y - A.y) * 2;
	while (A.x <= B.x)
	{
		mlx_pixel_put(data->mlx, data->win, A.x, A.y, 0xFF0000);
		A.x = A.x + 1;
		e -= dy;
		if (e <= 0)
		{
			A.x++;
			A.y++;
			e += dx;
			}
	}
}