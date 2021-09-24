/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 12:30:03 by glima-de          #+#    #+#             */
/*   Updated: 2021/09/07 19:41:27 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*aux;

	i = 0;
	aux = (unsigned char *)str;
	while (i < n)
	{
		if (aux[i] == (unsigned char)c)
			return ((void *)&aux[i]);
		i++;
	}
	return (0);
}
