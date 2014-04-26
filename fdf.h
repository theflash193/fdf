/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 15:27:10 by grass-kw          #+#    #+#             */
/*   Updated: 2014/04/24 10:32:18 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

#include "get_next_line.h"
#include "libft.h"
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				fd;
	char			*file;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	t_point			A;
	t_point			B;
	int				dx;
	int				dy;
}				t_env;

void	ft_error();
void	ft_parser(t_env *e);
int		key_hook(int keycode, t_env *e);
int		expose_hook(t_env *e);
int		mouse_hook(int button, int x, int y, t_env *e);
void	mlx_put_pixel_to_img(t_env *e, int color, int x, int y);
void	ft_check(t_env *e, int ac, char **av);
void	ft_free_tab(char **tab);
size_t	ft_strlen2(char **tab);
void	set_point(t_env *e, char **line, int x);
void	set_point2(t_env *e, char **line, char **line2, int x);
void	draw(t_env *data, t_point A, t_point B);
void	draw_vertical(t_env *data, t_point A, t_point B);
void	draw_line(t_env *data, t_point A, t_point B);
void	ligne(t_env *data, t_point A, t_point B, int z);

#endif