/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 14:08:17 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/10 20:05:50 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_parsed(t_filler *f)
{
	int	i;

	i = 0;
	while (f->parsed[i])
		free(f->parsed[i++]);
	free(f->parsed);
	f->parsed = NULL;
}

void	free_map(t_filler *f)
{
	int	i;

	i = 0;
	while (f->map[i])
		free(f->map[i++]);
	free(f->map);
	f->map = NULL;
}

void	free_heatmap(t_filler *f, int y)
{
	int	i;

	i = -1;
	while (++i < y)
		free(f->heatmap[i]);
	free(f->heatmap);
	f->heatmap = NULL;
}
