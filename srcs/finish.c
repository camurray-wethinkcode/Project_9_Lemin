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

static void	endroom(void *input)
{
	t_room	*room;

	room = (t_room *)input;
	ft_strdel(&room->name);
	ft_free(room->paths);
	free(input);
	input = NULL;
	return;
}

static void	endpath(void *input)
{
	t_path	*path;

	path = (t_path *)input;
	ft_strdel(&path->door1);
	ft_strdel(&path->door2);
	free(input);
	input = NULL;
	return;
}

void		end(t_lemin *input)
{
	if (input)
	{
		if (input->room_list)
		{
			ft_lstforeach(input->room_list, endroom);
			ft_free(input->room_list);
		}
		if (input->path_list)
		{
			ft_lstforeach(input->path_list, endpath);
			ft_free(input->path_list);
		}
		if (input->ant_list)
			ft_memdel((void **)&input->ant_list);
		ft_memdel((void **)&input);
	}
	return;
}

int	namevalidation(t_list *rooms)
{
	int		ans;
	t_room	*test;

	ans = 0;
	if (rooms != 0)
	{
		while (rooms)
		{
			test = (t_room *)rooms->content;
			if (test->name[0] == '#' || test->name[0] == 'L' || ft_strchr(test->name, '-') != 0)
				break;
			rooms = rooms->next;
		}
		ans = 1;
	}
	return(ans && !rooms);
}

int	flagvalidation(t_list *rooms, t_list *paths)
{
	int		start;
	int		end;
	t_room	*test;

	start = 0;
	end = 0;
	if (rooms != 0 || paths != 0)
	{
		while (rooms)
		{
			test = (t_room *)rooms->content;
			if (test->flag == 1)
				start++;
			if (test->flag == 3)
				end++;
			rooms = rooms->next;
		}
	}
	return(start == 1 && end == 1);
}