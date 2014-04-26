/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 15:22:08 by grass-kw          #+#    #+#             */
/*   Updated: 2014/04/24 15:22:18 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
void	ft_parser(t_env *e)
{
	char	**spl_line;
	char	**spl_line2;
	int		y;

	y = 0;
	get_next_line(e->fd, &(e->file));
	spl_line = ft_strsplit(e->file, ' ');
	while (get_next_line(e->fd, &(e->file)))
	{
		ft_putendl(e->file);
		spl_line2 = ft_strsplit(e->file, ' ');
		set_point(e, spl_line, y);
		set_point2(e, spl_line, spl_line2, y);
		spl_line = spl_line2;
		y += 50;
	}
	set_point(e, spl_line, y);
	//ft_free_tab(spl_line);
	//ft_free_tab(spl_line2);
}

void	set_point(t_env *e, char **line, int y)
{
	int		i;
	int		tmp;

	i = 0;
	while (line[i])
	{
		if (line[i] && line[i + 1])
		{
			e->A.x = i * 50;
			e->A.y = y;
			e->A.z = ft_atoi(line[i]);
			e->B.x = (i + 1) * 50;
			e->B.y = y;
			e->B.z = ft_atoi(line[i + 1]);
			tmp = e->A.x;
			e->A.x = e->A.x - e->A.y;
			e->A.y = (tmp + e->A.y) / 2;
			tmp = e->B.x;
			e->B.x = e->B.x - e->B.y;
			e->B.y = (tmp + e->B.y) / 2;
			draw(e, e->A, e->B);
		}
		i++;
	}
}

void	set_point2(t_env *e, char **line, char **line2, int y)
{
	int		i;
	int		tmp;

	i = 0;
	while (line[i] && line2[i])
	{
		if (line[i] && line2[i])
		{
			e->A.x = i * 50;
			e->A.y = y;
			e->A.z = ft_atoi(line[i]);
			e->B.x = (i) * 50;
			e->B.y = y + 50;
			e->B.z = ft_atoi(line2[i]);
			tmp = e->A.x;
			e->A.x = e->A.x - e->A.y;
			e->A.y = (tmp + e->A.y) / 2;
			tmp = e->B.x;
			e->B.x = e->B.x - e->B.y;
			e->B.y = (tmp + e->B.y) / 2;
			draw(e, e->A, e->B);
		}
		i++;
	}
}

//(e->A.z + e->B.z)