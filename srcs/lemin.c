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

static void	set_values(t_lemin *init)
{
	if ((init->total = total()) == FALSE)
		ft_puterror_fd("Error: Invalid number of ants.", -1, 2);
	if (input(init) == -1)
		ft_puterror_fd("Error: Reading failed.", -1, 2);
	if (!init->room_list || !init->path_list)
		ft_puterror_fd("Error: Missing rooms or paths.", -1, 2);
	init->ant_list = start_ants(init->total, init->room_list);
}

t_lemin		*structure(int total_arg, char *argm[])
{
	t_lemin	*init;

	if (!(init = (t_lemin *)malloc(sizeof(t_lemin))))
		ft_puterror_fd("Malloc failed.", -3, 2);
	init->moves = 0;
	init->room_list = NULL;
	init->path_list = NULL;
	init->arg.bonus = FALSE;
	init->arg.ant_wc = FALSE;
	init->arg.path_wc = FALSE;
	init->arg.room_wc = FALSE;
	arg(total_arg, argm, init);
	set_values(init);
	return(init);
}

static void	print_ant(t_lemin *lemin, t_ant *ant, t_room *room)
{
	if (lemin->arg.bonus == FALSE)
	{
		ft_putchar_fd('L', 1);
		ft_putnbr_fd(ant->number, 1);
		ft_putchar_fd('-', 1);
		ft_putstr_fd(ant->room->name, 1);
		ft_putchar_fd(' ', 1);
	}
	else
		bonus(lemin, lemin->ant_list, room);
	return;
}

static void	move_ant(t_lemin *lemin, t_ant *ant, t_room *room)
{
	ant->room->filled = 0;
	ant->last = ant->room;
	ant->room = room;
	ant->room->filled = 1;
	print_ant(lemin, ant, room);
	lemin->moves += 1;
	return;
}

void		start(t_lemin *lemin)
{
	int		result;
	int		distance;
	t_list	*ls;
	t_room	*tmp;
	t_room	*next;

	distance = FT_INT_MAX;
	ls = lemin->ant_list->room->paths;
	while (ls)
	{
		tmp = (t_room *)ls->content;
		if ((tmp->flag == 3 || !tmp->filled) && tmp != lemin->ant_list->last)
		{
			result = find_room(tmp, 3);
			if (result < distance && result > -1)
			{
				distance = result;
				next = tmp;
			}
		}
		ls = ls->next;
	}
	if (distance < FT_INT_MAX)
		move_ant(lemin, lemin->ant_list, next);
}
