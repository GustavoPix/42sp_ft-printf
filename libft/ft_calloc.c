/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:38:45 by glima-de          #+#    #+#             */
/*   Updated: 2021/09/04 16:13:49 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*aux;
	size_t	i;

	i = 0;
	aux = malloc(nmemb * size);
	if (aux)
	{
		while (i < nmemb * size)
		{
			aux[i] = '\0';
			i++;
		}
	}
	return ((void *)aux);
}
