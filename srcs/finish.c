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

char const	print_ant[3][4][47] =
{
	{
		{"   \\_//   \n"},
		{"   ..0..   \n"},
		{"     0     \n"},
		{"   ..0..   \n"},
	},
	{
		{"     \\_// \n"},
		{"     ..0.. \n"},
		{"      0    \n"},
		{"   ..0..   \n"},
	},
	{
		{" \\_//     \n"},
		{" ..0..     \n"},
		{"    0      \n"},
		{"   ..0..   \n"},
	}
};

void		bonus(t_lemin *lemin, t_ant *ant, t_room *room)
{
	int		i;

	i = 0;
	usleep(420000);
	ft_mini_printf("\n\n");
	while (i < 4)
	{
		ft_mini_printf("%s", print_ant[lemin->arg.bonus % 3][i], 93);
		i++;
	}
	ft_mini_printf("\n");
	ft_mini_printf("Ant  number   : %d\n", ant->number, 93);
	ft_mini_printf("Room name : %d\n", room->flag, 91);
	ft_mini_printf("Room flag : %d\n", room->flag, 91);
	ft_mini_printf("L%d-%s \n", ant->number, 93, \
					ant->room->name, 91);
	lemin->arg.bonus += 1;
	return;
}

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
