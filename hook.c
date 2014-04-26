/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 15:33:11 by grass-kw          #+#    #+#             */
/*   Updated: 2014/04/20 15:33:21 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	(void)e;
//	printf("key: %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	return (0);
}
