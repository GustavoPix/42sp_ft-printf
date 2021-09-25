/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:27:37 by glima-de          #+#    #+#             */
/*   Updated: 2021/09/25 16:40:34 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

int	prf_print_d(int n)
{
	int	s;

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
