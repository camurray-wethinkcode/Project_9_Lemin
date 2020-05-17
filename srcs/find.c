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

int			find_room(void *room, int flag)
{
	t_room	*now;
	t_list	*try;
	int		quickest;
	int		lastpath;

	now = (t_room *)room;
	if (now->flag == flag)
		return(0);
	if (now->occupied)
		return(-1);
	quickest = FT_INT_MAX;
	now->occupied = 1;
	try = now->paths;
	while (try)
	{
		if ((lastpath = find_room(try->content, flag)) < quickest)
                  quickest = lastpath + 1;
		try = try->next;
	}
	now->occupied = 0;
	return(quickest == FT_INT_MAX ? -1 : quickest);
}

static void	error(char *arg)
{
	ft_mini_printf("Argument invalid\n", arg);
	exit(-2);
	return;
}

void		arg(int argc, char *argv[], t_lemin *init)
{
	int		i;

	i = 1;
	while (--argc)
	{
		if (ft_strequ(argv[i], "-a") || ft_strequ(argv[i], "--ant"))
			init->arg.ant_wc = TRUE;
		else if (ft_strequ(argv[i], "-p") || ft_strequ(argv[i], "--path"))
			init->arg.path_wc = TRUE;
		else if (ft_strequ(argv[i], "-r") || ft_strequ(argv[i], "--room"))
			init->arg.room_wc = TRUE;
		else
			error(argv[i]);
		i++;
	}
	return;
}