/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 15:22:04 by grass-kw          #+#    #+#             */
/*   Updated: 2014/04/20 14:18:54 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include <math.h>
void	mlx_put_pixel_to_img(t_env *e, int color, int x, int y)
{
	if (x < 1900 && y < 1080)
		ft_memcpy(&e->data[(x * 4) + (y * e->size_line)],
		 &color, (size_t)sizeof(int));
}

void	draw(t_env *data, t_point A, t_point B)
{
	data->dx = (B.x - A.x) * 2;
	data->dy = (B.y - A.y) * 2;
	if ((A.x <= B.x) && data->dx >= abs(data->dy))
		draw_line(data, A, B);
	else if (B.x <= A.x && data->dx >= abs(data->dy))
		draw_line(data, B, A);
	else if (A.y <= B.y && data->dy >= abs(data->dx))
		draw_vertical(data, A, B);
	else
		draw_vertical(data, B, A);
}

void	draw_line(t_env *data, t_point A, t_point B)
{
	double	x;
	int		dist;

	x = A.x;
	while (x <= B.x)
	{
		dist = (data->dy * (x - A.x)) / data->dx;
		mlx_put_pixel_to_img(data, 0xFF0000, x , (A.y + dist));
		x++;
	}
}

void	draw_vertical(t_env *data, t_point A, t_point B)
{
	double	y;
	int		dist;

	y = A.y;
	while (y <= B.y)
	{
		dist = (data->dx * (y - A.y)) / data->dy;
		mlx_put_pixel_to_img(data, 0xFF0000, A.x + dist, y);
		y++;
	}
}

/*
void	draw_line(t_env *data, t_point A, t_point B)
{
	int		x;
	int		dist;

	x = A.x;
	while (x < B.x)
	{
		dist = ((B.y - A.y) * (x - A.x)) / (B.x - A.x);
		mlx_put_pixel_to_img(data, 0xFF0000, x , (A.y + dist));
		x++;
	}
}

void	draw_vertical(t_env *data, t_point A, t_point B)
{
	int		y;
	int		dist;

	y = A.y;
	while (y < B.y)
	{
		dist = ((B.x - A.x) * (y - A.y)) / (B.y - A.y);
		mlx_put_pixel_to_img(data, 0xFF0000, (A.x + dist), y);
		y++;
	}
}

void	draw(t_env *data, t_point A, t_point B)
{
	int		dx;
	int		dy;

	dx = (B.x - A.x) * 2;
	dy = (B.y - A.y) * 2;
	if ((dx) > (dy))
	{
		if (dy > 0)
		{
			draw_line(data, A, B);
			ft_putendl("1");
		}
		else
		{
			draw_line(data, B, A);
			ft_putendl("2");
		}
	}
	else
		if (dx > 0)
		{
			draw_vertical(data, A, B);
			ft_putendl("3");
		}
		else
		{
			draw_vertical(data, B, A);
			ft_putendl("4");
		}
}
*/

void	ligne(t_env *data, t_point A, t_point B, int z) {
	int dx,dy,i,xinc,yinc,cumul,x,y ;
	x = A.x ;
	y = A.y;
	dx = B.x - A.x ;
	dy = B.y - A.y ;
	xinc = ( dx > 0 ) ? 1 : -1 ;
	yinc = ( dy > 0 ) ? 1 : -1 ;
	dx = abs(dx);
	dy = abs(dy);
	(void)z;
	mlx_put_pixel_to_img(data, 0xFF0000, x, y);
	if ( dx > dy )
	{
		cumul = dx / 2 ;
		for ( i = 1 ; i <= dx ; i++ )
		{
			x += xinc ;
			cumul += dy ;
			if ( cumul >= dx )
			{
				cumul -= dx ;
				y += yinc;
			}
			mlx_put_pixel_to_img(data, 0xFF0000, x, y);
		}
	}
	else
	{
		cumul = dy / 2 ;
		for ( i = 1 ; i <= dy ; i++ )
		{
			y += yinc;
			cumul += dx ;
			if ( cumul >= dy )
			{
				cumul -= dy ;
				x += xinc ;
			}
			mlx_put_pixel_to_img(data, 0xFF0000, x, y);
		}
	}
}