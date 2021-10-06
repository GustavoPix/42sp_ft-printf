/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:55:06 by glima-de          #+#    #+#             */
/*   Updated: 2021/10/06 13:57:55 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	gc_num_words(char const *s, char c)
{
	int	qty;
	int	i;
	int	sw;

	qty = 0;
	i = 0;
	sw = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (sw > 0)
				qty++;
			sw = 0;
		}
		else
			sw++;
		i++;
	}
	if (sw > 0)
		qty++;
	return (qty);
}

static char	*gc_copy_word(char const *s, int qty)
{
	char	*aux;
	int		i;

	i = 0;
	aux = malloc((qty + 1) * sizeof(char));
	while (i < qty)
	{
		aux[i] = s[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

static void	gc_populate_words(char const *s, char c, char **tab)
{
	int	i;
	int	it;
	int	sw;

	i = 0;
	it = 0;
	sw = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (sw > 0)
			{
				tab[it] = gc_copy_word(&s[i - sw], sw);
				it++;
			}
			sw = 0;
		}
		else
			sw++;
		i++;
	}
	if (sw > 0)
		tab[it] = gc_copy_word(&s[i - sw], sw);
}

char	**ft_split(char const *s, char c)
{
	int		qty_words;
	char	**aux;

	qty_words = gc_num_words(s, c);
	aux = malloc((qty_words + 1) * sizeof(char *));
	gc_populate_words(s, c, aux);
	aux[qty_words] = NULL;
	return (aux);
}
