/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:55:35 by glima-de          #+#    #+#             */
/*   Updated: 2021/09/07 19:08:07 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	gc_isspace(char c)
{
	int		i;
	char	test[7];

	i = 0;
	test[0] = ' ';
	test[1] = '\f';
	test[2] = '\n';
	test[3] = '\r';
	test[4] = '\t';
	test[5] = '\v';
	test[6] = '\0';
	while (test[i] != '\0')
	{
		if (c == test[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		num;
	int		i;
	int		pos;

	num = 0;
	i = 0;
	pos = 1;
	while (gc_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pos *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * pos);
}
