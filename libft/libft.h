/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:15:35 by glima-de          #+#    #+#             */
/*   Updated: 2021/09/25 15:24:42 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

char			*ft_itoa(int n);
int				ft_isprint(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_tolower(int ch);
int				ft_toupper(int ch);
int				ft_atoi(const char *str);
char			*ft_strdup(const char *s);
unsigned int	ft_strlen(const char *str);
void			ft_bzero(void *s, size_t n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putunbr_fd(unsigned int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memset(void *str, int c, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
void			*ft_memchr(const void *str, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strnstr(const char	*big, const char *little, size_t len);
void			*ft_memmove(void *destination, const void *source, size_t num);

#endif
