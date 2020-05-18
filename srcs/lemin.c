/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 15:11:03 by camurray          #+#    #+#             */
/*   Updated: 2020/05/16 14:42:03 by camurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void	checks(t_lemin *input)
{
	if ((input->total = total()) == FALSE)
		ft_puterror_fd("Error: Invalid number of ants.", -1, 2);
	if (info(input) == -1)
		ft_puterror_fd("Error: Reading failed.", -1, 2);
	if (!input->room_list || !input->path_list)
		ft_puterror_fd("Error: Missing rooms or paths.", -1, 2);
	input->ant_list = startants(input->total, input->room_list);
}

t_lemin		*lemin(int num, char *arg[])
{
	t_lemin	*start;

	if (!(start = (t_lemin *)malloc(sizeof(t_lemin))))
		ft_puterror_fd("Malloc failed.", -3, 2);
	start->moves = 0;
	start->room_list = NULL;
	start->path_list = NULL;
	input(num, arg);
	checks(start);
	return(start);
}

void		start(t_lemin *input)
{
	t_room	*room;
	t_path	*path;
	t_list	*testroom;
	t_list	*testpath;

	testroom = input->room_list;
	while (testroom != 0)
	{
		room = (t_room *)testroom->content;
		testpath = input->path_list;
		while (testpath != 0)
		{
			path = (t_path *)testpath->content;
			if (ft_strequ(path->door1, room->name))
				room->paths = ft_lstpush(room->paths, roomname(path->door2, input->room_list));
			if (ft_strequ(path->door2, room->name))
				room->paths = ft_lstpush(room->paths, roomname(path->door1, input->room_list));
			testpath = testpath->next;
		}
		testroom = testroom->next;
	}
	return;
}

int			validate(t_lemin *input)
{
	return(pathvalidation(roomflag(1, input->room_list), input->path_list) \
			&& flagvalidation(input->room_list, input->path_list) \
			&& namevalidation(input->room_list));
}