/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 10:40:36 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/10 15:48:48 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdio.h>

typedef struct  s_filler
{
	char	*line;
	char	**parsed;
	char	mychar;
	char	enemychar;
	int		h_map;
	int		w_map;
	int		fd;
}				t_filler;

t_filler	*initiate_structure(void);
int			get_player(t_filler *f);
void		free_parsed(t_filler *f);
int			get_map_size(t_filler *f);

#endif
