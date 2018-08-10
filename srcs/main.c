/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:29:56 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/10 15:51:20 by jcasian          ###   ########.fr       */
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
	ft_printf("My char: %c\n", f->mychar);
	if (1)
	{
		if (get_map_size(f) == -1)
			return (-1);
		ft_printf("Map height: %i\nMap width: %i\n", f->h_map, f->w_map);
	}
}
