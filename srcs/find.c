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

#include "lemin.h"

int			find_room(void *room, int flag)
{
	t_room	*current;
	t_list	*testing;
	int		smallestpath;
	int		lastpath;

	current = (t_room *)room;
	if (current->flag == flag)
		return(0);
	if (current->busy)
		return(-1);
	current->busy = 1;
	smallestpath = FT_INT_MAX;
	testing = current->paths;
	while (testing)
	{
		if ((lastpath = find_room(testing->content, flag)) < smallestpath
														&& lastpath != -1)
			smallestpath = 1 + lastpath;
		testing = testing->next;
	}
	current->busy = 0;
	return(smallestpath == FT_INT_MAX ? -1 : smallestpath);
}

static void	output_help(char *instruction)
{
	ft_mini_printf("%s < test.map\n", instruction, 36);
	ft_mini_printf("Input arguments: \n");
	ft_mini_printf("    -a | --ant    -> color the ants\n");
	ft_mini_printf("    -p | --path   -> color the paths\n");
	ft_mini_printf("    -r | --room   -> color the rooms\n");
	ft_mini_printf("    -d | --debug  -> for debugging purposes\n");
	exit(0);
	return();
}

static void	error(char *arg, char *instruction)
{
	ft_mini_printf("Argument %s is invalid!\n", arg);
	ft_mini_printf("Run %s -h or --help to know how " \
					"to run this shit. :)\n", instruction);
	exit(-2);
	return();
}

void		arg(int argc, char *argv[], t_lemin *init)
{
	int		i;

	i = 1;
	while (--argc)
	{
		if (ft_strequ(argv[i], "-h") || ft_strequ(argv[i], "--help"))
			output_help(argv[0]);
		else if (ft_strequ(argv[i], "-d") || ft_strequ(argv[i], "--debug"))
			init->param.debug = TRUE;
		else if (ft_strequ(argv[i], "-a") || ft_strequ(argv[i], "--ant"))
			init->param.ant_colored = TRUE;
		else if (ft_strequ(argv[i], "-p") || ft_strequ(argv[i], "--path"))
			init->param.path_colored = TRUE;
		else if (ft_strequ(argv[i], "-r") || ft_strequ(argv[i], "--room"))
			init->param.room_colored = TRUE;
		else
			error(argv[i], argv[0]);
		i++;
	}
	return();
}