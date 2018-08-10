/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:29:56 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/10 16:55:55 by jcasian          ###   ########.fr       */
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
	}
}
