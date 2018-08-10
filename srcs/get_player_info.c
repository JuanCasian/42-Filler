//Header

#include "filler.h"

static void	check_parsed(char **str)
{
	if (ft_strcmp(str[0], "$$$") != 0)
		print_error();
	if (ft_strcmp(str[1], "exec") != 0)
		print_error();
	if (ft_strcmp(str[3], ":") != 0)
		print_error();
	if (ft_strcmp(str[4], "[../jcasian.filler]") != 0)
		print_error();
}

static void	select_player(t_filler *f)
{
	if (!(ft_strcmp(f->parsed[2], "p1")))
	{
		f->enemychar = 'X';
		f->mychar = 'O';
	}
	else if (!(ft_strcmp(f->parsed[2], "p2")))
	{
		f->enemychar = 'O';
		f->mychar = 'X';
	}
	else
		print_error();

}

void		get_player_info(t_filler *f)
{
	char	*line;
	int		x;

	if ((x = get_next_line(STDIN_FILENO, &line)) < 0)
		print_error();
	if (ft_numcharapp(line, ' ') != 4)
		print_error();
	f->parsed = ft_strsplit(line, ' ');
	check_parsed(f->parsed);
	select_player(f);
}
