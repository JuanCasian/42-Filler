// Header

#include "filler.h"

t_filler	*init_struct(void)
{
	t_filler	*f;

	f = (t_filler*)malloc(sizeof(t_filler));
	f->parsed = NULL;
	f->mychar = '\0';
	f->enemychar = '\0';
	return (f);
}
