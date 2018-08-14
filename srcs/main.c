/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:29:56 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/13 19:26:02 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(void)
{
	t_filler	*f;

	if (!(f = initiate_structure()))
		return (-1);
	f->fd = STDIN_FILENO;
	if (get_player(f) == -1)
		return (-1);
	while (1)
	{
		if (get_map_size(f) == -1)
			return (-1);
		if (create_map(f) == -1)
			return (-1);
		if (create_heatmap(f) == -1)
			return (-1);
		fill_heatmap(f);
		if (get_piece(f) == -1)
			return (-1);
		if (create_pieceslist(f) == -1)
			return (-1);
		if (get_nextpos(f) == -1)
			return (-1);
		ft_printf("%i %i\n", f->finaly, f->finalx);
	}
}
