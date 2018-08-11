/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heatmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 18:28:38 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/10 18:49:55 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	initialize_heatmap(t_filler *f, int y)
{
	int x;

	x = -1;
	while (++x < f->w_map)
	{
		if (f->map[y][x] == '.')
			f->heatmap[y][x] = 0;
		if (f->map[y][x] == f->mychar)
			f->heatmap[y][x] = -2;
		if (f->map[y][x] == f->enemychar)
			f->heatmap[y][x] = -1;
	}
}

int		create_heatmap(t_filler *f)
{
	int	y;

	y = -1;
	if (!(f->heatmap = (int**)malloc(sizeof(int) * f->h_map)))
	{
		free_parsed(f);
		return (-1);
	}
	while (++y < f->h_map)
	{
		if (!(f->heatmap[y] = (int*)malloc(sizeof(int) * f->w_map)))
		{
			free_parsed(f);
			free_heatmap(f, y);
			return (-1);
		}
		initialize_heatmap(f, y);
	}
	return (0);
}
