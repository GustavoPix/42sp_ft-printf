/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:43:58 by glima-de          #+#    #+#             */
/*   Updated: 2021/09/23 19:43:58 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	list;

	va_start(list, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 's')
				ft_putstr_fd(va_arg(list, char *), 1);
			i++;
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	return (1);
}
