/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 20:21:20 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/10 20:45:49 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	get_dimensions(t_filler *f)
{
	int	gres;

	if ((gres = get_next_line(f->fd, &f->line)) < 0 || !f->line)
		return (-1);
	if (ft_countcharsrepetition(f->line, ' ') != 2)
	{
		free(f->line);
		return (-1);
	}
	if (!(f->parsed = ft_strsplit(f->line, ' ')))
		return (-1);
	free(f->line);
	if (ft_strcmp(f->parsed[0], "Piece") != 0)
	{
		free_parsed(f);
		return (-1);
	}
	f->h_piece = ft_atoi(f->parsed[1]);
	f->w_piece = ft_atoi(f->parsed[2]);
	free_parsed(f);
	if (f->w_piece <= 0 || f->h_piece <= 0)
		return (-1);
	return (0);
}

static int	valid_pieceline(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '.' && str[i] != '*')
			return (0);
	}
	return (1);
}

static int	get_pieceline(t_filler *f, int i)
{
	int gres;

	if ((gres = get_next_line(f->fd, &f->line)) < 0 || !f->line)
		return (-1);
	if (!(valid_pieceline(f->line)))
	{
		free(f->line);
		return (-1);
	}
	if (ft_strlen(f->line) != (size_t)f->w_piece)
		return (-1);
	if (!(f->piece[i] = ft_strdup(f->line)))
	{
		free(f->line);
		return (-1);
	}
	return (0);
}

int			get_piece(t_filler *f)
{
	int i;

	i = -1;
	if (get_dimensions(f) == -1)
		return (-1);
	if (!(f->piece = (char**)malloc(sizeof(char*) * f->h_piece + 1)))
		return (-1);
	while (++i < f->h_piece)
		if (get_pieceline(f, i) == -1)
			return (-1);
	f->piece[i] = NULL;
	return (0);
}
