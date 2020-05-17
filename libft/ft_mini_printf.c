/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:17:48 by camurray          #+#    #+#             */
/*   Updated: 2019/08/04 14:43:39 by camurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void		set_color(int c)
{
	ft_putstr_fd("\x1B[", 1);
	ft_putnbr_fd(c, 1);
	ft_putchar_fd('m', 1);
	return ;
}

void		putcstr(char const *s, size_t col)
{
	set_color(col);
	ft_putstr_fd(s, 1);
	set_color(0);
	return ;
}

void		ft_mini_printf(const char *format, ...)
{
	va_list p;
	char	*tmp;

	va_start(p, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if ((*(format + 1)) == 's')
				putcstr(va_arg(p, char*), va_arg(p, size_t));
			else if ((*(format + 1)) == 'd')
			{
				putcstr(tmp = ft_itoa(va_arg(p, int)), va_arg(p, size_t));
				ft_memdel((void**)&tmp);
			}
			format += 1;
		}
		else
			write(1, format, 1);
		format += 1;
	}
	va_end(p);
	return ;
}
