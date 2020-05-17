#ifndef LEMIN_H
# define LEMIN_H
# define FT_INT_MAX			(2147483647)
# include "../libft/include/libft.h"
# define SET_FLAG(line)	input_commands(line);ft_memdel((void **)&line)

typedef struct			s_path
{
	char			*door1;
	char			*door2;
}				t_path;

typedef struct			s_room
{
	char			*name;
	int			x;
	int			y;
	int			flag;
	int			occupied;
	int			filled;
	t_list			*paths;
}				t_room;

typedef struct			s_ant
{
	int			number;
	t_room			*room;
	t_room			*last;
	int			moved;
}				t_ant;

typedef struct			s_arg
{
	int			ant_wc;
	int			path_wc;
	int			room_wc;
}				t_arg;

typedef struct			s_lemin
{
	int			total;
	int			done;
	long int		moves;
	t_ant			*ant_list;
	t_list			*room_list;
	t_list			*path_list;
	t_arg			arg;
}				t_lemin;

t_ant		*start_ants(int total, t_list *rooms);
t_path		*start_path(char *line);
t_room		*start_room(char *line, int flag);
t_room		*roomflag(int flag, t_list *list);
t_room		*roomname(char *name, t_list *list);
t_lemin		*structure(int total_arg, char *arg[]);
void		start(t_lemin *lemin);
int			validate(t_lemin *lemin);
int			total(void);
void		output(t_lemin *lemin);
void		loop(t_lemin *lemin);
int			input(t_lemin *lemin);
void		lemin(t_lemin *lemin);
int			find_room(void *room, int flag);
void		arg(int argc, char *argv[], t_lemin *init);
void		end(t_lemin *lemin);

#endif
