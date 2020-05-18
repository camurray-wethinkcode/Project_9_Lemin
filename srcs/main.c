/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 16:17:58 by camurray          #+#    #+#             */
/*   Updated: 2020/05/16 14:44:12 by camurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int			main(int argc, char *argv[])
{
	t_lemin	*input;

	input = lemin(argc, argv);
	output(input);
	start(input);
	if (validate(input) != TRUE)
	{
		end(input);
		ft_puterror_fd("Error: incorrect input.", -1, 2);
	}
	loop(input);
	return(0);
}

static int	commandinput(char *input)
{
	int		ans;

	ans = 2;
	if (input[0] != '#')
		ans = 0;
	else if (ft_strequ("##start", input))
		ans = 1;
	else if (ft_strequ("##end", input))
		ans = 3;
	return(ans);
}

static int	roominput(char *input)
{
	while (*input && *input != ' ')
		input++;
	if (*input != ' ')
		return(0);
	input++;
	if (*input == '-')
		input++;
	while (*input && ft_isdigit(*input))
		input++;
	if (*input != ' ')
		return(0);
	input++;
	if (*input == '-')
		input++;
	while (*input && ft_isdigit(*input))
		input++;
	return(*input != '\0' ? 0 : 1);
}

static int	pathinput(char *input, t_list *room)
{
	int		ans;
	t_path	test;

	ans = 0;
	if (ft_strchr(input, '-'))
	{
		test.door1 = ft_strsub(input, 0, ft_strlchr(input, '-'));
		test.door2 = ft_strdup(input + ft_strlchr(input, '-') + 1);
		if (roomname(test.door1, room) && roomname(test.door2, room))
			ans = 1;
		free(test.door1);
		free(test.door2);
		test.door1 = NULL;
		test.door2 = NULL;
	}
	return(ans);
}

int			info(t_lemin *input)
{
	int		ans;
	char	*next;
	int		flag;

	flag = 2;
	input->done = 0;
	while ((ans = get_next_line(0, &next)) > 0)
	{
		if (commandinput(next))
		{
			flag = (flag != 2) ? flag : SET_FLAG(next);
		}
		else if (roominput(next) && !input->done)
		{
			input->room_list = ft_lstpush(input->room_list, startroom(next, flag));
			flag = 2;
		}
		else if (pathinput(next, input->room_list) && (input->done = 1))
			input->path_list = ft_lstpush(input->path_list, startpath(next));
		else
			break;
	}
	ft_memdel((void **)&next);
	return(ans);
}