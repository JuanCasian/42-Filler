/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:16:33 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/10 20:27:21 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	get_map_info(t_filler *f)
{
	int	gres;

	if ((gres = get_next_line(f->fd, &f->line)) < 0 || !f->line)
		return (-1);
	if (ft_countcharsrepetition(f->line, ' ') != 2)
	{
		free(f->line);
		return (-1);
	}
	return (0);
}

int			get_map_size(t_filler *f)
{
	if (get_map_info(f) == -1)
		return (-1);
	if (!(f->parsed = ft_strsplit(f->line, ' ')))
		return (-1);
	free(f->line);
	if (ft_strcmp(f->parsed[0], "Plateau") != 0)
	{
		free_parsed(f);
		return (-1);
	}
	f->h_map = ft_atoi(f->parsed[1]);
	f->w_map = ft_atoi(f->parsed[2]);
	free_parsed(f);
	if (f->h_map <= 0 || f->w_map <= 0)
		return (-1);
	return (0);
}
