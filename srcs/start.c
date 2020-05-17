/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 17:27:48 by camurray          #+#    #+#             */
/*   Updated: 2020/05/16 14:43:14 by camurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	input_commands(char *line)
{
	int		ret;

	ret = 1;
	if (line[0] != '#')
		ret = 0;
	else if (ft_strequ("##start", line))
		ret = 1;
	else if (ft_strequ("##end", line))
		ret = 3;
	return(ret);
}

static int	input_rooms(char *line)
{
	while (*line && *line != ' ')
		line++;
	if (*line != ' ')
		return(0);
	line++;
	if (*line == '-')
		line++;
	while (*line && ft_isdigit(*line))
		line++;
	if (*line != ' ')
		return(0);
	line++;
	if (*line == '-')
		line++;
	while (*line && ft_isdigit(*line))
		line++;
	return(*line != '\0' ? 0 : 1);
}

static int	input_paths(char *line, t_list *rooms)
{
	int		ret;
	t_path	tmp;

	ret = 0;
	if (ft_strchr(line, '-'))
	{
		tmp.door1 = ft_strsub(line, 0, ft_strlchr(line, '-'));
		tmp.door2 = ft_strdup(line + ft_strlchr(line, '-') + 1);
		if (roomname(tmp.door1, rooms) && roomname(tmp.door2, rooms))
			ret = 1;
		free(tmp.door1);
		free(tmp.door2);
		tmp.door1 = NULL;
		tmp.door2 = NULL;
	}
	return(ret);
}

int			input(t_lemin *lemin)
{
	int		ret;
	char	*line;
	int		flag;

	flag = 1;
	lemin->rooms_done = 0;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (input_commands(line))
		{
			flag = (flag != 1) ? flag : SET_FLAG(line);
		}
		else if (input_rooms(line) && !lemin->rooms_done)
		{
			lemin->room_list = ft_lstpush(lemin->room_list, \
											start_room(line, flag));
			flag = 1;
		}
		else if (input_paths(line, lemin->room_list) && (lemin->rooms_done = 1))
			lemin->path_list = ft_lstpush(lemin->path_list, start_path(line));
		else
			break;
	}
	ft_memdel((void **)&line);
	return(ret);
}

void		lemin(t_lemin *lemin)
{
	t_room	*room;
	t_path	*path;
	t_list	*tmp_room;
	t_list	*tmp_path;

	tmp_room = lemin->room_list;
	while (tmp_room != 0)
	{
		room = (t_room *)tmp_room->content;
		tmp_path = lemin->path_list;
		while (tmp_path != 0)
		{
			path = (t_path *)tmp_path->content;
			if (ft_strequ(path->door1, room->name))
				room->paths = ft_lstpush(room->paths, \
						roomname(path->door2, lemin->room_list));
			if (ft_strequ(path->door2, room->name))
				room->paths = ft_lstpush(room->paths, \
						roomname(path->door1, lemin->room_list));
			tmp_path = tmp_path->next;
		}
		tmp_room = tmp_room->next;
	}
	return();
}