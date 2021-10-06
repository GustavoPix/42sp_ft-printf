/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_dec_to_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:16:23 by glima-de          #+#    #+#             */
/*   Updated: 2021/10/06 18:16:32 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

int	prf_dec_to_base(unsigned long nbr, const char *base)
{
	int	s;

	s = 1;
	if (nbr >= (unsigned long)ft_strlen(base))
	{
		s = prf_dec_to_base(nbr / ft_strlen(base), base);
		return (s + prf_dec_to_base(nbr % ft_strlen(base), base));
	}
	else
	{
		if (nbr < 0)
			nbr *= -1;
		ft_putchar_fd(base[nbr], 1);
		return (s);
	}
}
