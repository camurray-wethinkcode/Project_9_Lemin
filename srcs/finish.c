/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 15:20:48 by camurray          #+#    #+#             */
/*   Updated: 2020/05/16 14:43:39 by camurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void	delete_room(void *data)
{
	t_room	*room;

	room = (t_room *)data;
	ft_strdel(&room->name);
	ft_lst_rec_free(room->paths);
	free(data);
	data = NULL;
	return;
}

static void	delete_path(void *data)
{
	t_path	*path;

	path = (t_path *)data;
	ft_strdel(&path->door1);
	ft_strdel(&path->door2);
	free(data);
	data = NULL;
	return;
}

void		end(t_lemin *lemin)
{
	if (lemin)
	{
		if (lemin->room_list)
		{
			ft_lstforeach(lemin->room_list, delete_room);
			ft_lst_rec_free(lemin->room_list);
		}
		if (lemin->path_list)
		{
			ft_lstforeach(lemin->path_list, delete_path);
			ft_lst_rec_free(lemin->path_list);
		}
		if (lemin->ant_list)
			ft_memdel((void **)&lemin->ant_list);
		ft_memdel((void **)&lemin);
	}
	return;
}
