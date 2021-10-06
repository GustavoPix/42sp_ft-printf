/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:56:23 by glima-de          #+#    #+#             */
/*   Updated: 2021/10/06 13:59:21 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	gc_to_remove_left(char const *str, char const *set)
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

static int	gc_to_remove_right(char const *str, char const *set)
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
	unsigned int	l_remove;
	unsigned int	r_remove;
	int				i;

	l_remove = gc_to_remove_left(s1, set);
	if (l_remove >= ft_strlen(s1))
	{
		aux = malloc(1 * sizeof(char));
		aux[0] = '\0';
		return (aux);
	}
	r_remove = gc_to_remove_right(s1, set);
	i = 0;
	aux = malloc((r_remove - l_remove + 1) * sizeof(char));
	if (!aux)
		return (NULL);
	while (s1[i + l_remove] && i + l_remove < r_remove)
	{
		aux[i] = s1[i + l_remove];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}
