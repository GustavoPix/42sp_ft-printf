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

static void	prf_decToBase(long nbr, const char *base)
{
	if (nbr >= (long)ft_strlen(base) || nbr <= (long)ft_strlen(base) * -1)
	{
		prf_decToBase(nbr / ft_strlen(base), base);
		prf_decToBase(nbr % ft_strlen(base), base);
	}
	else
	{
		if (nbr < 0)
			nbr *= -1;
		ft_putchar_fd(base[nbr], 1);
	}
}

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
			else if (str[i + 1] == 'c')
				ft_putchar_fd(va_arg(list, int), 1);
			else if (str[i + 1] == 'p')
			{
				ft_putstr_fd("0x", 1);
				prf_decToBase(va_arg(list, unsigned long), "0123456789abcdef");
			}
			else if (str[i + 1] == 'i' || str[i + 1] == 'd')
				ft_putnbr_fd(va_arg(list, int), 1);
			i++;
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	return (1);
}
