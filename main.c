/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 15:22:20 by grass-kw          #+#    #+#             */
/*   Updated: 2014/04/24 11:12:12 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include <string.h>

int	main(int argc, char **argv)
{
	t_env	e;
//	char	*line;

	(void)argv;
	(void)argc;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1900, 1080, "fdf");
	e.img = mlx_new_image(e.mlx, 1900, 1080);
	e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.size_line), &(e.endian));
	ft_check(&e, argc, argv);
	ft_parser(&e);
//	draw(&e);
//	draw_line(&e, e.A, e.B);
//	draw_line2(&e, e.A, e.B);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
//	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}

void	ft_error()
{
	ft_putendl("usage : .fdf file1");
	exit(0);
}

void	ft_check(t_env *e, int ac, char **av)
{
	if (ac != 2)
		ft_error();
	e->file = av[1];
	e->fd = open(av[1], O_RDONLY);
	if (e->fd == -1)
	{
		ft_putendl(strerror(errno));
		exit(0);
	}
}
