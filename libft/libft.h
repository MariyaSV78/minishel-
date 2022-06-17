/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:57:18 by msosnova          #+#    #+#             */
/*   Updated: 2021/12/06 16:16:41 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	*ft_memset(void *a, int b, size_t c);
void	ft_bzero(void *a, size_t b);
void	*ft_memcpy(void *a, const void *b, size_t c);
void	*ft_memccpy(void *a, const void *b, int c, size_t d);
void	*ft_memmove(void *a, const void *b, size_t c);
void	*ft_memchr(const void *a, int b, size_t c);
int		ft_memcmp(const void *a, const void *b, size_t c);
size_t	ft_strlen(const char *a);
int		ft_isalpha(int a);
int		ft_isdigit(int a);
int		ft_isalnum(int a);
int		ft_isascii(int a);
int		ft_isprint(int a);
int		ft_toupper(int a);
int		ft_tolower(int a);
char	*ft_strchr(const char *a, int c);
char	*ft_strrchr(const char *a, int c);
int		ft_strncmp(const char *a, const char *b, size_t c);
size_t	ft_strlcpy(char *a, const char *b, size_t c);
size_t	ft_strlcat(char *a, const char *b, size_t c);
char	*ft_strnstr(const char *a, const char *b, size_t c);
int		ft_atoi(const char *a);
void	*ft_calloc(size_t a, size_t b);
char	*ft_strdup(const char *a);

char	*ft_substr(char const *a, unsigned int b, size_t c);
char	*ft_strjoin(char const *a, char const *b);
char	*ft_strtrim(char const *a, char const *b);
char	**ft_split(char const *a, char b);
char	*ft_itoa(int a);
char	*ft_strmapi(char const *a, char (*f)(unsigned int, char));
void	ft_putchar_fd(char a, int b);
void	ft_putstr_fd(char const *a, int b);
void	ft_putendl_fd(char const *a, int b);
void	ft_putnbr_fd(int a, int b);

/*bonus*/
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void	*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif //LIBFT_H
