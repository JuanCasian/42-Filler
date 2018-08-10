/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 10:40:36 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/07 16:04:02 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdio.h>

typedef struct  s_filler
{
	char	**parsed;
	char	mychar;
	char	enemychar;
}				t_filler;

t_filler	*init_struct(void);
void get_player_info(t_filler *f);

#endif
