#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/include/libft.h"
# define SET_FLAG(line)	commandinput(line);ft_memdel((void **)&line)

typedef struct			s_path
{
	char			*door1;
	char			*door2;
}				t_path;

typedef struct			s_room
{
	char				*name;
	int					x;
	int					y;
	int					flag;
	int					occupied;
	int					filled;
	t_list				*paths;
}						t_room;

typedef struct			s_ant
{
	int					number;
	t_room				*room;
	t_room				*last;
	int					moved;
}						t_ant;	

typedef struct			s_lemin
{
	int					total;
	int					done;
	long int			moves;
	t_ant				*ant_list;
	t_list				*room_list;
	t_list				*path_list;
}					t_lemin;

int	pathvalidation(t_room *rooms, t_list *paths);
int	flagvalidation(t_list *rooms, t_list *paths);
int	namevalidation(t_list *rooms);
int						info(t_lemin *lemin);
int						validate(t_lemin *lemin);
void					end(t_lemin *lemin);
void					loop(t_lemin *lemin);
void					run(t_lemin *lemin);
void					start(t_lemin *lemin);
void					output(t_lemin *lemin);
t_lemin					*lemin(int total_params, char *params[]);
int						froom(void *room, int flag);
int						total(void);
void					input(int argc, char *argv[]);
t_room					*roomname(char *name, t_list *list);
t_room					*roomflag(int flag, t_list *list);
t_ant					*startants(int total_ants, t_list *rooms);
t_path					*startpath(char *line);
t_room					*startroom(char *line, int room_flag);

#endif
