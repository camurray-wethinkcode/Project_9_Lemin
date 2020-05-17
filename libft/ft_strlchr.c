/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:17:48 by camurray          #+#    #+#             */
/*   Updated: 2019/10/04 14:43:39 by camurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

size_t		ft_strlchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != (char)c)
		i += 1;
	return (str[i] != (char)c ? -1 : i);
}
