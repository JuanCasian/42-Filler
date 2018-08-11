/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:29:56 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/10 18:51:28 by jcasian          ###   ########.fr       */
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
		int	j;
		int	k;

		j = -1;
		while (++j < f->h_map)
		{
			k = -1;
			while (++k < f->w_map)
				ft_printf("%i",f->heatmap[j][k]);
			ft_printf("\n");
		}
	}
}
