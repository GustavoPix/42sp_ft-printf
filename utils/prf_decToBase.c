/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_decToBase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:26:53 by glima-de          #+#    #+#             */
/*   Updated: 2021/09/25 16:40:30 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

int	prf_decToBase(unsigned long nbr, const char *base)
{
	int	s;

	s = 1;
	if (nbr >= (unsigned long)ft_strlen(base))
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
