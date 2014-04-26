/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 14:56:58 by grass-kw          #+#    #+#             */
/*   Updated: 2014/04/24 14:56:58 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	ft_free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

size_t	ft_strlen2(char **s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_isnumber(char *str)
{
	int				i;

	i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;
	if (ft_isdigit(str[i]))
		return (1);
	return (0);
}