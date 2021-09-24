/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 13:49:09 by glima-de          #+#    #+#             */
/*   Updated: 2021/08/21 13:49:09 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	si;
	size_t	di;
	size_t	dso;

	si = 0;
	di = 0;
	dso = ft_strlen(dest);
	di = dso;
	if (size < dso)
		return (size + ft_strlen(src));
	while (src[si] && di + 1 < size)
	{
		dest[di] = src[si];
		di++;
		si++;
	}
	while (src[si])
		si++;
	dest[di] = '\0';
	return (dso + si);
}
