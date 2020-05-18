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

static int	move(t_ant *ant)
{
	int		i;
	int		move;
	t_list	*list;
	t_room	*test;

	i = 1;
	move = 0;
	if (ant->room->flag == 3)
		return(0);
	list = ant->room->paths;
	if (ant->moved)
		i = 0;
	while (i && list)
	{
		test = (t_room *)list->content;
		if ((!test->filled && !(test->flag == 1) && test != ant->last) || test->flag == 3)
		{
			move = 1;
			break;
		}
		list = list->next;
	}
	return(i && move);
}

static int	quit(t_ant *ants, int num)
{
	int		i;
	int		ans;

	i = 0;
	ans = 1;
	while (i < num && ants != 0)
	{
		if (ants[i].room->flag != 3)
		{
			ans = 0;
			break;
		}
		i++;
	}
	return(ans);
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

static void	attempt(t_lemin *input)
{
	int		i;
	int		turn;

	turn = 0;
	while (!turn && !quit(input->ant_list, input->total))
	{
		i = 0;
		turn = 1;
		while (i < input->total)
		{
			if (move(input->ant_list + i))
			{
				turn = 0;
				input->ant_list += i;
				run(input);
				input->ant_list -= i;
			}
			i++;
		}
		ft_putchar_fd('\n', 1);
	}
	return;
}

void		loop(t_lemin *input)
{
	while (!quit(input->ant_list, input->total))
	{
		reset(input->ant_list, input->total);
		attempt(input);
	}
	end(input);
	return;
}