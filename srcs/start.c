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

#include "../includes/lemin.h"

static void	showant(t_ant *ant)
{
	ft_putchar_fd('L', 1);
	ft_putnbr_fd(ant->number, 1);
	ft_putchar_fd('-', 1);
	ft_putstr_fd(ant->room->name, 1);
	ft_putchar_fd(' ', 1);
	return;
}

static void	moveant(t_lemin *input, t_ant *ant, t_room *room)
{
	ant->room->filled = 0;
	ant->last = ant->room;
	ant->room = room;
	ant->room->filled = 1;
	showant(ant);
	input->moves += 1;
	return;
}

void		run(t_lemin *input)
{
	int		ans;
	int		total;
	t_list	*list;
	t_room	*test;
	t_room	*next;

	total = 2147483647;
	list = input->ant_list->room->paths;
	while (list)
	{
		test = (t_room *)list->content;
		if ((test->flag == 3 || !test->filled) && test != input->ant_list->last)
		{
			ans = froom(test, 3);
			if (ans < total && ans > -1)
			{
				total = ans;
				next = test;
			}
		}
		list = list->next;
	}
	if (total < 2147483647)
		moveant(input, input->ant_list, next);
}
