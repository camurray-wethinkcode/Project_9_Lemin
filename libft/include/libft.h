/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:06:05 by camurray          #+#    #+#             */
/*   Updated: 2019/06/06 12:09:09 by camurray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <wchar.h>
# include <stdint.h>
# include <sys/types.h>
# include <stdarg.h>

/*
**# include <stdio.h> - included for using printf in main tests
**# include <ctype.h> - included for using is functions in main tests
*/

# define FT_RESET			(0)
# define FT_BOLD			(1)
# define FT_DIM				(2)
# define FT_ITALICS			(3)
# define FT_UNDERLINE			(4)
# define FT_REVERSE			(7)
# define FT_HIDDEN			(8)
# define FT_STROKE			(9)
# define FT_BLACK			(0)
# define FT_RED				(1)
# define FT_GREEN			(2)
# define FT_YELLOW			(3)
# define FT_BLUE			(4)
# define FT_MAGENTA			(5)
# define FT_CYAN			(6)
# define FT_WHITE			(7)

typedef enum				e_bool
{
	FALSE = 0,
	TRUE = 1
}					t_bool;

typedef struct				s_stack
{
	double				value;
	struct s_stack			*next;
}					t_stack;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
char				ft_chardel(char c);
int					ft_countwords(const char *s, char c);
int					ft_intlen(int n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
void				ft_isnegative(int n);
int					ft_ispowerof2(unsigned int n);
int					ft_isprint(int c);
int					ft_isupper(int c);
int					ft_iswhitespace(int c);
char				*ft_itoa(int n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				ft_search_and_replace(char *str, char a, char b);
int					ft_setdigitzero(int c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
void				ft_swap(int *a, int *b);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_free(t_list *first);
void				ft_lstdelnode(t_list **head, t_list *node, void (*del)(void*, size_t));
t_list				*ft_lstfind(t_list *begin_list, void *data, int (*cmp)());
void				ft_lstforeach(t_list *lst, void (*f)());
t_list				*ft_lstpush(t_list *first, void *item);
void				ft_printf(const char *format, ...);
void				ft_puterror_fd(char const *msg, int ret, int fd);
size_t				ft_strlchr(const char *str, int c);

#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000

typedef struct			s_listgnl
{
	char				*text;
	char				*lnew;
	struct s_listgnl	*next;
	int					fd;
}						t_listgnl;

int						get_next_line(int const fd, char **line);

#endif
