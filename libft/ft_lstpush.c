/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:17:48 by camurray          #+#    #+#             */
/*   Updated: 2019/06/06 14:43:39 by camurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstpush(t_list *first, void *item)
{
	t_list	*tmp;

	if (!item)
		return (NULL);
	if (!first)
	{
		first = (t_list *)malloc(sizeof(t_list));
		first->content = item;
		first->next = NULL;
	}
	else
	{
		tmp = first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_list *)malloc(sizeof(t_list));
		tmp->next->content = item;
		tmp->next->next = NULL;
	}
	return (first);
}
