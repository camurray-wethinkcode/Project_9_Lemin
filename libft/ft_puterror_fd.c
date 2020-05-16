/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:17:48 by camurray          #+#    #+#             */
/*   Updated: 2019/07/08 14:43:39 by camurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the string msg to the file descriptor fd, followed by an exit of the
** program with a custom return value (defined by ret).
*/

void	ft_puterror_fd(char const *msg, int ret, int fd)
{
	ft_putendl_fd(msg, fd);
	exit(ret);
}
