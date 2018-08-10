/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:45:49 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/10 15:50:05 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	get_player_line(t_filler *f)
{
	int	gres;

	if ((gres = get_next_line(f->fd, &f->line)) < 0)
		return (-1);
	if (ft_countcharsrepetition(f->line, ' ') != 4)
	{
		free(f->line);
		return (-1);
	}
	return (0);
}

static int	verify_parsed(t_filler *f)
{
	int flag;

	flag = 0;
	if (ft_strcmp(f->parsed[0], "$$$") != 0)
		flag = 1;
	if (ft_strcmp(f->parsed[1], "exec") != 0)
		flag = 1;
	if (ft_strcmp(f->parsed[3], ":") != 0)
		flag = 1;
	if (ft_strcmp(f->parsed[4], "[../jcasian.filler]") != 0)
		flag = 1;
	if (flag == 1)
	{
		free_parsed(f);
		return (-1);
	}
	return (0);
}

int			get_player(t_filler *f)
{
	if (get_player_line(f) == -1)
		return (-1);
	if (!(f->parsed = ft_strsplit(f->line, ' ')))
		return (-1);
	free(f->line);
	if (verify_parsed(f) == -1)
		return (-1);
	if (ft_strcmp(f->parsed[2], "p1") == 0)
	{
		f->mychar = 'O';
		f->enemychar = 'X';
	}
	else if (ft_strcmp(f->parsed[2], "p2") == 0)
	{
		f->mychar = 'X';
		f->enemychar = 'O';
	}
	else
	{
		free_parsed(f);
		return (-1);
	}
	free_parsed(f);
	return (0);
}
