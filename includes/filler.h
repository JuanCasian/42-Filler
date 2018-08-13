/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 10:40:36 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/12 21:22:18 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define ENEMY -1
# define ME -2

# include "libft.h"
# include <stdio.h>

typedef struct	s_piecelist
{
	int						x;
	int						y;
	struct	s_piecelist	*next;
}				t_piecelist;

typedef struct  s_filler
{
	char		*line;
	char		**parsed;
	char		mychar;
	char		enemychar;
	int			h_map;
	int			w_map;
	int			fd;
	char		**map;
	int			**heatmap;
	char		**piece;
	int			w_piece;
	int			h_piece;
	t_piecelist	*pieces;
	int			relx;
	int			rely;
}				t_filler;

t_filler		*initiate_structure(void);
int				get_player(t_filler *f);
void			free_parsed(t_filler *f);
int				get_map_size(t_filler *f);
int				create_map(t_filler *f);
void			free_map(t_filler *f);
void			free_heatmap(t_filler *f, int y);
int				create_heatmap(t_filler *f);
void			fill_heatmap(t_filler *f);
int				get_piece(t_filler *f);
int				create_pieceslist(t_filler *f);

#endif
