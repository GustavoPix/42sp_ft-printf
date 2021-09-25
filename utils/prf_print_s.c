/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:27:04 by glima-de          #+#    #+#             */
/*   Updated: 2021/09/25 16:40:42 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

int	prf_print_s(char *str)
{
	if (str)
	{
		ft_putstr_fd(str, 1);
		return (ft_strlen(str) - 2);
	}
	ft_putstr_fd("(null)", 1);
	return (4);
}
