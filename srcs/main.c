/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:29:56 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/12 21:22:17 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_filler	*f;

	if (!(f = initiate_structure()))
		return (-1);
	f->fd = open("/nfs/2018/j/jcasian/42-Program/Filler/hello.txt", O_RDWR);
	if (get_player(f) == -1)
		return (-1);
	if (1)
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
		find_nextpos(f);
		int	j;
		int	k;

		j = -1;
		while (++j < f->h_map)
		{
			k = -1;
			while (++k < f->w_map)
				ft_printf("%3i", f->heatmap[j][k]);
			ft_printf("\n");
		}
		ft_printf("-----PIECE-----\n");
		j = -1;
		while (f->piece[++j])
		{
			ft_printf("%s\n", f->piece[j]);
		}
	}
}
