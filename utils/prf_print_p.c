/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:27:16 by glima-de          #+#    #+#             */
/*   Updated: 2021/09/25 16:40:38 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

int	prf_print_p(unsigned long pointer)
{
	if (pointer)
	{
		ft_putstr_fd("0x", 1);
		return (prf_decToBase(pointer, "0123456789abcdef"));
	}
	ft_putstr_fd("(nil)", 1);
	return (3);
}
