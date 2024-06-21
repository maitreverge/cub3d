/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:29:11 by flverge           #+#    #+#             */
/*   Updated: 2023/10/06 16:04:13 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void*(*f)(void *), void(*del) (void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

// int		ft_abs(int c);
// size_t	ft_countwords(char const *str, char c);
// int		ft_intlen(int n);
// int		ft_isblank(int c);
// int		ft_iscntrl(int c);
// int		ft_isgraph(int c);
// int		ft_islower(int c);
// int		ft_isspace(int c);
// int		ft_isupper(int c);
// int		ft_isxdigit(int c);
// char	*ft_newstr(size_t size);
// void	ft_putchar(char c);
// long	ft_power(int nb, int power);
// int		ft_str_is_alpha(char *str);
// int		ft_str_is_lowercase(char *str);
// int		ft_str_is_digit(char *str);
// int		ft_str_is_printable(char *str);
// int		ft_str_is_unique_chars(char *str);
// int		ft_str_is_uppercase(char *str);
// char	*ft_strcapitalize(char *str);
// int		ft_strcasecmp(const char *s1, const char *s2);
// char	*ft_strcasestr(const char *haystack, const char *needle);
// char	*ft_strlowcase(char *str);
// char	*ft_strncpy(char *dest, char const *src, size_t n);
// char	*ft_strndup(const char *s1, size_t n);
// int		ft_strcmp(const char *s1, const char *s2);

#endif