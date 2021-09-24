/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:31:11 by glima-de          #+#    #+#             */
/*   Updated: 2021/09/04 14:59:32 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	rlen;
	char			*aux;

	i = 0;
	rlen = len;
	if (start + rlen > ft_strlen(s))
		rlen = ft_strlen(s) - start;
	if ((int)rlen < 0)
		rlen = 0;
	aux = malloc((rlen + 1) * sizeof(char));
	if (aux)
	{
		while (i < rlen)
		{
			aux[i] = s[i + start];
			i++;
		}
		aux[i] = '\0';
		return (aux);
	}
	else
		return (NULL);
}
