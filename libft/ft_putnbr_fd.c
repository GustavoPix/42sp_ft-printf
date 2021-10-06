/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 20:05:40 by glima-de          #+#    #+#             */
/*   Updated: 2021/10/06 13:56:08 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

static void	loop_to_print(int nb, int fd)
{
	char	c;

	if (nb >= 10 || nb <= -10)
	{
		loop_to_print(nb / 10, fd);
		loop_to_print(nb % 10, fd);
	}
	else
	{
		if (nb < 0)
			nb *= -1;
		c = nb + '0';
		ft_putchar(c, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar('-', fd);
	loop_to_print(n, fd);
}
