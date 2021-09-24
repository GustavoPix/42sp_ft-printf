/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:14:16 by glima-de          #+#    #+#             */
/*   Updated: 2021/08/20 21:14:16 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t num)
{
	size_t	i;
	char	*pd;
	char	*ps;

	i = 0;
	pd = (char *)destination;
	ps = (char *)source;
	if (pd < ps)
	{
		while (i < num)
		{
			pd[i] = ps[i];
			i++;
		}
	}
	else
	{
		while (num > 0)
		{
			num--;
			pd[num] = ps[num];
		}
	}
	return (destination);
}
