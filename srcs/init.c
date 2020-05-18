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

#include "../includes/lemin.h"

t_room		*roomname(char *name, t_list *list)
{
	int		i;
	t_room	*test;

	i = 0;
	while (list && !i)
	{
		test = (t_room *)list->content;
		i = ft_strequ(name, test->name);
		list = list->next;
	}
	return(i ? test : NULL);
}

t_ant		*startants(int total, t_list *rooms)
{
	int		i;
	t_ant	*ants;

	i = 0;
	if (!(ants = (t_ant *)malloc(sizeof(t_ant) * total)))
		ft_puterror_fd("Malloc failed.", -3, 2);
	while (i < total)
	{
		ants[i].room = roomflag(1, rooms);
		ants[i].moved = 0;
		ants[i].number = i + 1;
		i++;
	}
	return(ants);
}

t_path		*startpath(char *input)
{
	int		i;
	t_path	*path;

	if (!(path = (t_path *)malloc(sizeof(t_path))))
		ft_puterror_fd("Malloc failed.", -3, 2);
	i = (int)ft_strlchr(input, '-');
	path->door1 = ft_strsub(input, 0, i);
	path->door2 = ft_strdup(input + i + 1);
	free(input);
	return(path);
}

t_room		*startroom(char *input, int flag)
{
	int		i;
	t_room	*room;

	i = 0;
	if (!(room = (t_room *)malloc(sizeof(t_room))))
		ft_puterror_fd("Malloc failed.", -3, 2);
	while (input[i] != ' ')
		i++;
	room->flag = flag;
	room->name = ft_strsub(input, 0, i);
	while (input[i] == ' ')
		i++;
	room->x = ft_atoi(input + i);
	while (input[i] != ' ')
		i++;
	while (input[i] == ' ')
		i++;
	room->y = ft_atoi(input + i);
	room->paths = NULL;
	room->occupied = 0;
	room->filled = 0;
	free(input);
	return(room);
}

int	pathvalidation(t_room *rooms, t_list *paths)
{
	return((rooms != 0 && paths != 0) && froom(rooms, 3) >= 0);
}