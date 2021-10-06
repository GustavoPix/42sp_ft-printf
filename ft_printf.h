/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:28:06 by glima-de          #+#    #+#             */
/*   Updated: 2021/10/06 18:19:40 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	prf_print_d(int n);
int	prf_print_s(char *str);
int	prf_print_u(unsigned int n);
int	prf_print_p(unsigned long pointer);
int	prf_dec_to_base(unsigned long nbr, const char *base);
int	prf_print_x(unsigned long pointer, const char *base);

#endif
