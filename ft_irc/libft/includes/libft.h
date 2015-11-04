/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:18:04 by pciavald          #+#    #+#             */
/*   Updated: 2014/05/25 15:47:57 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include "struct.h"
# include "get_next_line.h"

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isprintnstr(char *str, size_t len);
int		ft_toupper(int c);
int		ft_tolower(int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnew(size_t size);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoindel(char **str1, char **str2);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
void	ft_printsplit(char **split);
void	ft_freesplit(char ***split);
int		ft_countsplit(char **split);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void	ft_lstpushback(t_list **alst, t_list *new);
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

t_avl	*right_right_rotation(t_avl *parent);
t_avl	*left_left_rotation(t_avl *parent);
t_avl	*right_left_rotation(t_avl *parent);
t_avl	*left_right_rotation(t_avl *parent);

t_avl	*ft_avladd(t_avl *root, t_avl *node, int (*cmp)(void *, void *));
void	ft_avldel(t_avl **head, void (*del)(void *, size_t));
int		ft_avlheight(t_avl *node);
void	ft_avliter_inorder(t_avl *head, void (*f)(t_avl *node));
void	ft_avliter_inorderrev(t_avl *head, void (*f)(t_avl *node));
t_avl	*ft_avlnew(void const *content, size_t content_size);

char	*ft_strrealloc(char *ptr, size_t size);
void	ft_lstrev(t_list **begin);
int		ft_lstsize(t_list *begin);
int		ft_match(char *s1, char *s2);

int		ft_printf(const char *s, ...);

#endif
