/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runloop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 08:17:38 by camurray          #+#    #+#             */
/*   Updated: 2020/05/16 14:55:30 by camurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	test(t_ant *ant)
{
	int		true;
	int		move;
	t_list	*ls;
	t_room	*tmp;

	if (ant->room->flag == 3)
		return(0);
	true = 1;
	move = 0;
	if (ant->moved)
		true = 0;
	ls = ant->room->paths;
	while (true && ls)
	{
		tmp = (t_room *)ls->content;
		if ((!tmp->filled && !(tmp->flag == 1) && tmp != ant->last)
			|| tmp->flag == 3)
		{
			move = 1;
			break;
		}
		ls = ls->next;
	}
	return(true && move);
}

static int	finish(t_ant *ants, int num)
{
	int		i;
	int		total;

	i = 0;
	total = 1;
	while (i < num && ants != 0)
	{
		if (ants[i].room->flag != 3)
		{
			total = 0;
			break;
		}
		i++;
	}
	return(total);
}

static void	reset(t_ant *ants, int num)
{
	int		i;

	i = 0;
	while (i < num)
	{
		ants[i].moved = 0;
		i++;
	}
	return;
}

static void	check(t_lemin *lemin)
{
	int		i;
	int		turn;

	turn = 0;
	while (!turn && !finish(lemin->ant_list, lemin->total))
	{
		i = 0;
		turn = 1;
		while (i < lemin->total)
		{
			if (test(lemin->ant_list + i))
			{
				turn = 0;
				lemin->ant_list += i;
				start(lemin);
				lemin->ant_list -= i;
			}
			i++;
		}
		ft_putchar_fd('\n', 1);
	}
	return;
}

void		loop(t_lemin *lemin)
{
	while (!finish(lemin->ant_list, lemin->total))
	{
		reset(lemin->ant_list, lemin->total);
		check(lemin);
	}
        ft_mini_printf("\nTotal moves : %d\n", lemin->moves, 92);
	end(lemin);
	return;
}
