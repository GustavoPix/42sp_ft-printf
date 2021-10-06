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

static int	prf_treatment_uint(unsigned int value, char c)
{
	if (c == 'u')
		return (prf_print_u(value));
	else if (c == 'x')
		return (prf_print_x(value, "0123456789abcdef"));
	else if (c == 'X')
		return (prf_print_x(value, "0123456789ABCDEF"));
	else
		return (0);
}

static int	prf_is_unsig_int(char c)
{
	if (c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

static int	prf_print_arg(va_list *list, char c)
{
	if (c == 's')
		return (prf_print_s(va_arg(*list, char *)));
	else if (c == 'c')
	{
		ft_putchar_fd(va_arg(*list, int), 1);
		return (-1);
	}
	else if (c == 'p')
		return (prf_print_p(va_arg(*list, unsigned long)));
	else if (c == 'i' || c == 'd')
		return (prf_print_d(va_arg(*list, int)));
	else if (prf_is_unsig_int(c) == 1)
		return (prf_treatment_uint(va_arg(*list, unsigned int), c));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (-1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		a;
	va_list	list;

	va_start(list, str);
	i = 0;
	a = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			a += prf_print_arg(&list, str[i + 1]);
			i++;
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(list);
	return (i + a);
}
