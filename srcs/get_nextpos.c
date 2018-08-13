/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nextpos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:34:13 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/13 15:14:42 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	get_realpiecepos(t_filler *f)
{
	f->finalx = f->finalx - f->relx;
	f->finaly = f->finaly - f->rely;
}

static void	check_piece(t_filler *f, int *score, int *valid, int y, int x)
{
	t_piecelist *tmp;
	int			smallx;
	int			smally;

	tmp = f->pieces;
	while (tmp)
	{
		smallx = x + tmp->x;
		smally = y + tmp->y;
		if (smallx >= 0 && smally >= 0 && smallx < f->w_map &&
				smally < f->h_map && f->heatmap[smally][smallx] != ENEMY)
		{
			if (f->heatmap[smally][smallx] == ME)
				(*valid)++;
			else
				(*score) += f->heatmap[smally][smallx];
		}
		else
		{
			*valid = -1;
			*score = -1;
			return ;
		}
		tmp = tmp->next;
	}
}

void	get_nextpos(t_filler *f)
{
	int j;
	int k;
	int score;
	int	valid;
	int	flag;

	j = -1;
	flag = 0;
	while (f->map[++j])
	{
		k = -1;
		while (f->map[j][++k])
		{
			score = 0;
			valid = 0;
			check_piece(f, &score, &valid, j, k);
			if ((valid == 1 && score < f->bscore) || (valid == 1 && flag == 0))
			{
				f->finalx = k;
				f->finaly = j;
				f->bscore = score;
			}
		}
	}
	get_realpiecepos(f);
}
