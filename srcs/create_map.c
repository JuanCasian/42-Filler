/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 16:03:09 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/10 16:56:03 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	verify_parsed(t_filler *f)
{
	int	flag;
	
	flag = 0;
	if (ft_countcharsrepetition(f->line, ' ') != 1)
		flag = 1;
	if (ft_strlen(f->line) != (size_t)f->w_map + 4)
		flag = 1;
	if (f->line[3] != ' ')
		flag = 1;
	if (flag == 1)
	{
		free_map(f);
		free(f->line);
		return (-1);
	}
	return (0);
}

int			create_map(t_filler *f)
{
	int	i;
	int	gres;

	i = -1;
	if (!(f->map = (char**)malloc(sizeof(char*) * f->h_map + 1)))
		return (-1);
	if ((gres = get_next_line(f->fd, &f->line) < 0))
		return (-1);
	while (++i < f->h_map)
	{
		free(f->line);
		if ((gres = get_next_line(f->fd, &f->line)) < 0)
			return (-1);
		if (verify_parsed(f) == -1)
			return (-1);
		if (!(f->map[i] = ft_strsub(f->line, 4, (size_t)f->w_map)))
		{
			free_map(f);
			free(f->line);
			return (-1);
		}
	}
	free(f->line);
	f->map[i] = NULL;
	return (0);
}
