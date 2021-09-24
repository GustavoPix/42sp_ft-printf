/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:05:40 by glima-de          #+#    #+#             */
/*   Updated: 2021/09/04 16:15:38 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	ib;
	size_t	il;

	ib = 0;
	il = 0;
	if (!little[0])
		return ((char *)&big[0]);
	while (big[ib] && ib < len)
	{
		while (big[ib + il] == little[il] && ib + il < len)
		{
			if (!little[il + 1])
				return ((char *)&big[ib]);
			il++;
			if (!big[ib + il])
				return (0);
		}
		il = 0;
		ib++;
	}
	return (0);
}
