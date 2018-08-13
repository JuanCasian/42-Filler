/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:29:56 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/13 15:44:57 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	free_all(t_filler *f)
{
	free_map(f);
	free_heatmap(f, f->h_map);
	free_piece(f);
	free_list(f);
}

int			main(void)
{
	t_filler	*f;

	if (!(f = initiate_structure()))
		return (-1);
	//f->fd = open("/nfs/2018/j/jcasian/42-Program/Filler/hello.txt", O_RDWR);
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
		get_nextpos(f);
		ft_printf("%i %i\n", f->finaly, f->finalx);
		free_all(f);
	}
}
