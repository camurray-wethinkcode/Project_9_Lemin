/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 16:17:58 by camurray          #+#    #+#             */
/*   Updated: 2020/05/16 14:44:12 by camurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			main(int argc, char *argv[])
{
	t_lemin	*lemin;

	lemin = structure(argc, argv);
	output(lemin);
	lemin(lemin);
	if (lemin_validate(lemin) != TRUE)
	{
		end(lemin);
		ft_puterror_fd("Error: Something went wrong, check your input.", -1, 2);
	}
	loop(lemin);
	return(0);
}

static int	validate_roomname(t_list *rooms)
{
	int		ans;
	t_room	*tmp;

	ans = 0;
	if (rooms != 0)
	{
		while (rooms)
		{
			tmp = (t_room *)rooms->content;
			if (tmp->name[0] == '#' || tmp->name[0] == 'L' || ft_strchr(tmp->name, '-') != 0)
				break;
			rooms = rooms->next;
		}
		ans = 1;
	}
	return(ans && !rooms);
}

static int	validate_roomflag(t_list *rooms, t_list *paths)
{
	int		start;
	int		end;
	t_room	*tmp;

	start = 0;
	end = 0;
	if (rooms != 0 || paths != 0)
	{
		while (rooms)
		{
			tmp = (t_room *)rooms->content;
			if (tmp->flag == 1)
				start++;
			if (tmp->flag == 3)
				end++;
			rooms = rooms->next;
		}
	}
	return(start == 1 && end == 1);
}

static int	validate_path(t_room *rooms, t_list *paths)
{
	return((rooms != 0 && paths != 0) && find_room(rooms, 3) >= 0);
}

int			validate(t_lemin *lemin)
{
	return(validate_path(roomflag(1, lemin->room_list), lemin->path_list) \
			&& validate_roomflag(lemin->room_list, lemin->path_list) \
			&& validate_roomname(lemin->room_list));
}

int			total(void)
{
	char	*line;
	int		ant_number;

	line = NULL;
	if (get_next_line(0, &line) > 0)
	{
		while (line[0] == '#')
		{
			ft_memdel((void **)&line);
			if (get_next_line(0, &line) == -1)
			{
				line = NULL;
				break;
			}
		}
	}
	ant_number = (line != NULL && *line != '\0') ? atoi(line) : 0;
	ft_memdel((void **)&line);
	return(ant_number);
}
