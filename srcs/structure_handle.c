/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:31:15 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/13 18:56:46 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_filler	*initiate_structure(void)
{
	t_filler	*f;

	if (!(f = (t_filler*)malloc(sizeof(t_filler))))
		return (NULL);
	f->line = NULL;
	f->parsed = NULL;
	f->mychar = '\0';
	f->enemychar = '\0';
	f->h_map = 0;
	f->w_map = 0;
	f->heatmap = NULL;
	f->bscore = -1;
	return (f);
}
