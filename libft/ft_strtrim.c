/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:56:23 by glima-de          #+#    #+#             */
/*   Updated: 2021/09/04 16:15:44 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	gc_toRemoveLeft(char const *str, char const *set)
{
	int	i;
	int	iset;

	i = 0;
	iset = 0;
	while (str[i])
	{
		while (set[iset])
		{
			if (str[i] == set[iset])
			{
				i++;
				iset = -1;
			}
			iset++;
		}
		return (i);
	}
	return (i);
}

static int	gc_toRemoveRight(char const *str, char const *set)
{
	int	i;
	int	iset;

	i = ft_strlen(str) - 1;
	iset = 0;
	while (str[i] && i > 0)
	{
		while (set[iset])
		{
			if (str[i] == set[iset])
			{
				i--;
				iset = -1;
			}
			iset++;
		}
		return (i + 1);
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*aux;
	unsigned int	lRemove;
	unsigned int	rRemove;
	int				i;

	lRemove = gc_toRemoveLeft(s1, set);
	if (lRemove >= ft_strlen(s1))
	{
		aux = malloc(1 * sizeof(char));
		aux[0] = '\0';
		return (aux);
	}
	rRemove = gc_toRemoveRight(s1, set);
	i = 0;
	aux = malloc((rRemove - lRemove + 1) * sizeof(char));
	if (!aux)
		return (NULL);
	while (s1[i + lRemove] && i + lRemove < rRemove)
	{
		aux[i] = s1[i + lRemove];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}
