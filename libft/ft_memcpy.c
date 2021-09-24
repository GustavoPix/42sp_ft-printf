/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:47:06 by glima-de          #+#    #+#             */
/*   Updated: 2021/08/20 20:47:06 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*pd;
	char	*ps;

	i = 0;
	pd = (char *)dest;
	ps = (char *)src;
	while (i < n)
	{
		pd[i] = ps[i];
		i++;
	}
	return (dest);
}
