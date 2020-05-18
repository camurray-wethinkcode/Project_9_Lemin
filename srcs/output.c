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

#include "../includes/lemin.h"

static void	showroom(void *room)
{
	t_room	*test;

	if (room != NULL)
	{
		test = (t_room *)room;
		if (test->flag == 1)
			ft_putendl_fd("##start", 1);
		else if (test->flag == 3)
			ft_putendl_fd("##end", 1);
		ft_putstr_fd(test->name, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(test->x, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(test->y, 1);
	}
	ft_putchar_fd('\n', 1);
	return;
}

static void	showpath(void *input)
{
	t_path	*path;

	path = (t_path *)input;
	ft_putstr_fd(path->door1, 1);
	ft_putchar_fd('-', 1);
	ft_putendl_fd(path->door2, 1);
	return;
}

void		output(t_lemin *input)
{
	ft_putnbr_fd(input->total, 1);
	ft_putchar_fd('\n', 1);
	ft_lstforeach(input->room_list, showroom);
	ft_lstforeach(input->path_list, showpath);
	ft_putchar_fd('\n', 1);
	return;
}