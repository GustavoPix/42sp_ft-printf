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

static int	prf_decToBase(unsigned long nbr, const char *base)
{
	int s = 1;
	if (nbr >= (unsigned long)ft_strlen(base)/* || nbr <= (long)ft_strlen(base) * -1*/)
	{
		s = prf_decToBase(nbr / ft_strlen(base), base);
		return (s + prf_decToBase(nbr % ft_strlen(base), base));
	}
	else
	{
		if (nbr < 0)
			nbr *= -1;
		ft_putchar_fd(base[nbr], 1);
		return (s);
	}
}

static int ft_print_s(char *str)
{
	if (str)
	{
		ft_putstr_fd(str, 1);
		return (ft_strlen(str) - 2);
	}
	ft_putstr_fd("(null)", 1);
	return (4);
}

static int ft_print_p(unsigned long pointer)
{
	if (pointer)
	{
		ft_putstr_fd("0x", 1);
		return (prf_decToBase(pointer, "0123456789abcdef") );
	}
	ft_putstr_fd("(nil)", 1);
	return (3);
}

static int ft_print_x(unsigned long pointer, const char *base)
{
	return (prf_decToBase(pointer, base) - 2);
}

static int ft_print_d(int n)
{
	int s;

	s = -1;
	ft_putnbr_fd(n, 1);
	while (n <= -10 || n >= 10)
	{
		s++;
		n /= 10;
	}
	if (n < 0)
		s++;
	return (s);
}

static int ft_print_u(unsigned int n)
{
	int s;

	s = -1;
	ft_putunbr_fd(n, 1);
	while (n >= 10)
	{
		s++;
		n /= 10;
	}
	if (n < 0)
		s++;
	return (s);
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
			if (str[i + 1] == 's')
				a += ft_print_s(va_arg(list, char *));
			else if (str[i + 1] == 'c')
			{
				ft_putchar_fd(va_arg(list, int), 1);
				a-=1;
			}
			else if (str[i + 1] == 'p')
				a += ft_print_p(va_arg(list, unsigned long));
			else if (str[i + 1] == 'i' || str[i + 1] == 'd')
				a += ft_print_d(va_arg(list, int));
			else if (str[i + 1] == 'u')
				a += ft_print_u(va_arg(list, unsigned int));
			else if (str[i + 1] == 'x')
				a += ft_print_x(va_arg(list, unsigned int), "0123456789abcdef");
			else if (str[i + 1] == 'X')
				a += ft_print_x(va_arg(list, unsigned int), "0123456789ABCDEF");
			else if (str[i + 1] == '%')
			{
				ft_putchar_fd('%', 1);
				a -= 1;
			}
			i++;
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i + a);
}
