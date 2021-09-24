/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:09:10 by glima-de          #+#    #+#             */
/*   Updated: 2021/09/04 16:15:10 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*aux;
	size_t	i;
	size_t	ia;

	i = 0;
	ia = 0;
	aux = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	while (s1[i])
	{
		aux[ia] = s1[i];
		i++;
		ia++;
	}
	i = 0;
	while (s2[i])
	{
		aux[ia] = s2[i];
		i++;
		ia++;
	}
	aux[ia] = '\0';
	return (aux);
}
