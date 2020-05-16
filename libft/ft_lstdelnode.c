/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:17:48 by camurray          #+#    #+#             */
/*   Updated: 2019/06/04 19:43:39 by camurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelnode(t_list **head, t_list *node, void (*del)(void*, size_t))
{
	t_list *temp;

	if (!node)
		return ;
	if (*head == node)
		*head = (*head)->next;
	else
	{
		temp = *head;
		while (temp->next != 0 && temp->next != node)
			temp = temp->next;
		if (temp->next == 0)
			return ;
		temp->next = temp->next->next;
	}
	ft_lstdelone(&node, del);
	free(node);
	node = NULL;
}
