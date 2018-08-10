/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 10:40:36 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/10 16:56:05 by jcasian          ###   ########.fr       */
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
	char	**map;
}				t_filler;

t_filler	*initiate_structure(void);
int			get_player(t_filler *f);
void		free_parsed(t_filler *f);
int			get_map_size(t_filler *f);
int			create_map(t_filler *f);
void	free_map(t_filler *f);

#endif
