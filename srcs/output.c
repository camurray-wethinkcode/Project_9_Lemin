/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 12:07:48 by camurray          #+#    #+#             */
/*   Updated: 2020/05/16 14:48:17 by camurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	output_room(void *room)
{
	t_room	*tmp_room;

	if (room != NULL)
	{
		tmp_room = (t_room *)room;
		if (tmp_room->flag == 1)
			ft_putendl_fd("##start", 1);
		else if (tmp_room->flag == 3)
			ft_putendl_fd("##end", 1);
		ft_putstr_fd(tmp_room->name, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(tmp_room->x, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(tmp_room->y, 1);
	}
	ft_putchar_fd('\n', 1);
	return();
}

static void	output_path(void *tunnel)
{
	t_path	*path;

	path = (t_path *)tunnel;
	ft_putstr_fd(path->door1, 1);
	ft_putchar_fd('-', 1);
	ft_putendl_fd(path->door2, 1);
	return();
}

static void	output_room_wc(void *room)
{
	t_room	*tmp;

	if (room != NULL)
	{
		tmp = (t_room *)room;
		if (tmp->flag == 1)
			ft_putendl_fd("##start", 1);
		else if (tmp->flag == 3)
			ft_putendl_fd("##end", 1);
		ft_mini_printf("%s %d %d", tmp->name, 91, \
						tmp->x, 92, tmp->y, 92);
	}
	ft_putchar_fd('\n', 1);
	return();
}

static void	output_path_wc(void *path1)
{
	t_path	*path;

	path = (t_path *)path1;
	ft_mini_printf("%s-%s\n", path->door1, 36, path->door2, 36);
	return();
}

void		output(t_lemin *lemin)
{
	if (lemin->arg.ant_wc == FALSE)
		ft_putnbr_fd(lemin->total, 1);
	else
		ft_mini_printf("%d", lemin->total, 93);
	ft_putchar_fd('\n', 1);
	if (lemin->arg.room_wc == FALSE)
		ft_lstforeach(lemin->room_list, output_room);
	else
		ft_lstforeach(lemin->room_list, output_room_wc);
	if (lemin->arg.path_wc == FALSE)
		ft_lstforeach(lemin->path_list, output_path);
	else
		ft_lstforeach(lemin->path_list, output_path_wc);
	ft_putchar_fd('\n', 1);
	return();
}
