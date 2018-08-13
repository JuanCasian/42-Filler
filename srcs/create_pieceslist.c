/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pieceslist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 20:48:11 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/12 21:19:14 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	add_firstelem(int j, int k, t_filler *f)
{
	f->relx = k;
	f->rely = j;
	if (!(f->pieces = (t_piecelist*)malloc(sizeof(t_piecelist))))
		return (-1);
	f->pieces->x = 0;
	f->pieces->y = 0;
	f->pieces->next = NULL;
	return (1);
}

static int	add_newelem(int y, int x, t_filler *f)
{
	t_piecelist	*elem;
	t_piecelist *tmp;

	if (!(elem = (t_piecelist*)malloc(sizeof(t_piecelist))))
		return (-1);
	elem->x = x;
	elem->y = y;
	tmp = f->pieces;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	return (0);
}

int			create_pieceslist(t_filler *f)
{
	int	flag;
	int	j;
	int	k;

	flag = 0;
	j = -1;
	while (f->piece[++j])
	{
		k = -1;
		while (f->piece[j][++k])
			if (f->piece[j][k] == '*')
			{
				if (flag == 0)
				{
					if ((flag = add_firstelem(j, k, f)) == -1)
						return (-1);
				}
				else
				{
					if (add_newelem(j - f->rely, k - f->relx, f) == -1)
						return (-1);
				}
			}
	}
	return (0);
}
