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

#include "lemin.h"

static void	set_values(t_lemin *init)
{
	if ((init->ant_total = total()) == FALSE)
		ft_puterror_fd("Error: Invalid number of ants.", -1, 2);
	if (input(init) == -1)
		ft_puterror_fd("Error: Reading failed.", -1, 2);
	if (!init->room_list || !init->path_list)
		ft_puterror_fd("Error: Missing rooms or paths.", -1, 2);
	init->ant_list = start_ants(init->ant_total, init->room_list);
}

t_lemin		*structure(int total_params, char *params[])
{
	t_lemin	*init;

	if (!(init = (t_lemin *)malloc(sizeof(t_lemin))))
		ft_puterror_fd("Memory allocation failed.", -3, 2);
	init->moves = 0;
	init->room_list = NULL;
	init->path_list = NULL;
	init->param.debug = FALSE;
	init->param.ant_colored = FALSE;
	init->param.path_colored = FALSE;
	init->param.room_colored = FALSE;
	arg(total_params, params, init);
	set_values(init);
	return(init);
}

static void	output_ant(t_lemin *lemin, t_ant *ant, t_room *room)
{
	if (lemin->param.debug == FALSE)
	{
		ft_putchar_fd('L', 1);
		ft_putnbr_fd(ant->id, 1);
		ft_putchar_fd('-', 1);
		ft_putstr_fd(ant->room->name, 1);
		ft_putchar_fd(' ', 1);
	}
	else
		bonus(lemin, lemin->ant_list, room);
	return();
}

static void	move_ant(t_lemin *lemin, t_ant *ant, t_room *room)
{
	ant->room->has_ant = 0;
	ant->last = ant->room;
	ant->room = room;
	ant->room->has_ant = 1;
	output_ant(lemin, ant, room);
	lemin->moves += 1;
	return();
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
		if ((tmp->flag == 3 || !tmp->has_ant) \
				&& tmp != lemin->ant_list->last)
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
