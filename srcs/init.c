/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 15:17:48 by camurray          #+#    #+#             */
/*   Updated: 2020/05/16 14:41:37 by camurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_ant		*start_ants(int total, t_list *rooms)
{
	int		i;
	t_ant	*ants;

	i = 0;
	if (!(ants = (t_ant *)malloc(sizeof(t_ant) * total)))
		ft_puterror_fd("Memory allocation failed.", -3, 2);
	while (i < total)
	{
		ants[i].room = get_room_flag(1, rooms);
		ants[i].did_turn = 0;
		ants[i].id = i + 1;
		i++;
	}
	return(ants);
}

t_path		*start_path(char *line)
{
	int		i;
	t_path	*newpath;

	if (!(newpath = (t_path *)malloc(sizeof(t_path))))
		ft_puterror_fd("Memory allocation failed.", -3, 2);
	i = (int)ft_strlchr(line, '-');
	newpath->door1 = ft_strsub(line, 0, i);
	newpath->door2 = ft_strdup(line + i + 1);
	free(line);
	return(newpath);
}

t_room		*start_room(char *line, int flag)
{
	int		i;
	t_room	*newroom;

	i = 0;
	if (!(newroom = (t_room *)malloc(sizeof(t_room))))
		ft_puterror_fd("Memory allocation failed.", -3, 2);
	while (line[i] != ' ')
		i++;
	newroom->flag = flag;
	newroom->name = ft_strsub(line, 0, i);
	while (line[i] == ' ')
		i++;
	newroom->x = ft_atoi(line + i);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	newroom->y = ft_atoi(line + i);
	newroom->paths = NULL;
	newroom->busy = 0;
	newroom->has_ant = 0;
	free(line);
	return(newroom);
}

t_room		*roomflag(int flag, t_list *list)
{
	int		done;
	t_room	*tmp;

	done = 0;
	while (list && !done)
	{
		tmp = (t_room *)list->content;
		done = tmp->flag == flag ? 1 : 0;
		list = list->next;
	}
	return(done ? tmp : NULL);
}

t_room		*roomname(char *name, t_list *list)
{
	int		done;
	t_room	*tmp;

	done = 0;
	while (list && !done)
	{
		tmp = (t_room *)list->content;
		done = ft_strequ(name, tmp->name);
		list = list->next;
	}
	return(done ? tmp : NULL);
}
