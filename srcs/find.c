/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 15:17:53 by camurray          #+#    #+#             */
/*   Updated: 2020/05/16 14:43:22 by camurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int			froom(void *room, int flag)
{
	t_room	*now;
	t_list	*try;
	int		quickest;
	int		path;

	quickest = 2147483647;
	now = (t_room *)room;
	try = now->paths;
	if (now->flag == flag)
		return (0);
	if (now->occupied)
		return (-1);
	now->occupied = 1;
	while (try)
	{
		if ((path = froom(try->content, flag)) < quickest && path != -1)
			quickest = 1 + path;
		try = try->next;
	}
	now->occupied = 0;
	return(quickest == 2147483647 ? -1 : quickest);
}

int			total(void)
{
	char	*input;
	int		ant;

	input = NULL;
	if (get_next_line(0, &input) > 0)
	{
		while (input[0] == '#')
		{
			ft_memdel((void **)&input);
			if (get_next_line(0, &input) == -1)
			{
				input = NULL;
				break;
			}
		}
	}
	ant = (input != NULL && *input != '\0') ? atoi(input) : 0;
	ft_memdel((void **)&input);
	return(ant);
}

static void	error(char *arg)
{
	ft_printf("Argument %s is invalid!\n", arg);
	exit(-2);
	return;
}

void		input(int argc, char *argv[])
{
	int		i;

	i = 1;
	while (--argc)
	{
		error(argv[i]);
		i++;
	}
	return;
}

t_room		*roomflag(int flag, t_list *list)
{
	int		i;
	t_room	*test;

	i = 0;
	while (list && !i)
	{
		test = (t_room *)list->content;
		i = test->flag == flag ? 1 : 0;
		list = list->next;
	}
	return(i ? test : NULL);
}