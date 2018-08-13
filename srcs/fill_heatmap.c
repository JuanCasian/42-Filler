/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_heatmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 19:07:18 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/13 16:34:39 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	fill_withone(t_filler *f, int x, int y)
{
	if (x + 1 < f->w_map && f->heatmap[y][x + 1] == ENEMY)
		f->heatmap[y][x] = 1;
	if (x + 1 < f->w_map && y - 1 >= 0 && f->heatmap[y - 1][x + 1] == ENEMY)
		f->heatmap[y][x] = 1;
	if (y - 1 >= 0 && f->heatmap[y - 1][x] == ENEMY)
		f->heatmap[y][x] = 1;
	if (x - 1 >= 0 && y - 1 >= 0 && f->heatmap[y - 1][x - 1] == ENEMY)
		f->heatmap[y][x] = 1;
	if (x - 1 >= 0 && f->heatmap[y][x - 1] == ENEMY)
		f->heatmap[y][x] = 1;
	if (x - 1 >= 0 && y + 1 < f->h_map && f->heatmap[y + 1][x - 1] == ENEMY)
		f->heatmap[y][x] = 1;
	if (y + 1 < f->h_map && f->heatmap[y + 1][x] == ENEMY)
		f->heatmap[y][x] = 1;
	if (y + 1 < f->h_map && x + 1 < f->w_map && f->heatmap[y + 1][x + 1]
			== ENEMY)
		f->heatmap[y][x] = 1;
}

static void	fill_firstround(t_filler *f)
{
	int	x;
	int	y;

	y = -1;
	while (++y < f->h_map)
	{
		x = -1;
		while (++x < f->w_map)
			if (f->heatmap[y][x] == 0)
				fill_withone(f, x, y);
	}
}

static void	fill_heatvalue(t_filler *f, int x, int y, int i)
{
	if (x + 1 < f->w_map && f->heatmap[y][x + 1] == i)
		f->heatmap[y][x] = i + 1;
	if (x + 1 < f->w_map && y - 1 >= 0 && f->heatmap[y - 1][x + 1] == i)
		f->heatmap[y][x] = i + 1;
	if (y - 1 >= 0 && f->heatmap[y - 1][x] == i)
		f->heatmap[y][x] = i + 1;
	if (x - 1 >= 0 && y - 1 >= 0 && f->heatmap[y - 1][x - 1] == i)
		f->heatmap[y][x] = i + 1;
	if (x - 1 >= 0 && f->heatmap[y][x - 1] == i)
		f->heatmap[y][x] = i + 1;
	if (x - 1 >= 0 && y + 1 < f->h_map && f->heatmap[y + 1][x - 1] == i)
		f->heatmap[y][x] = i + 1;
	if (y + 1 < f->h_map && f->heatmap[y + 1][x] == i)
		f->heatmap[y][x] = i + 1;
	if (y + 1 < f->h_map && x + 1 < f->w_map && f->heatmap[y + 1][x + 1]
			== i)
		f->heatmap[y][x] = i + 1;
}

static void	fill_restofmap(t_filler *f)
{
	int	i;
	int	x;
	int	y;
	int	max;

	if (f->w_map > f->h_map)
		max = f->w_map;
	else
		max = f->h_map;
	i = 0;
	while (++i < max)
	{
		y = -1;
		while (++y < f->h_map)
		{
			x = -1;
			while (++x < f->w_map)
				if (f->heatmap[y][x] == 0)
					fill_heatvalue(f, x, y, i);
		}
	}
}

void		fill_heatmap(t_filler *f)
{
	fill_firstround(f);
	fill_restofmap(f);
}
