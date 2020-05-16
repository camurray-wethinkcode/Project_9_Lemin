/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 15:23:48 by camurray          #+#    #+#             */
/*   Updated: 2019/06/04 14:44:39 by camurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstfind(t_list *begin_list, void *data, int (*cmp)())
{
	t_list *node;

	node = begin_list;
	while (node)
	{
		if ((cmp)(node->content, data) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}
