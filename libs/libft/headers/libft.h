/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:45:30 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/07 17:08:39 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// Includes
# include <stdlib.h>
# include <unistd.h>

// Macros
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef UINT_MAX
#  define UINT_MAX 4294967295U
# endif

# ifndef LONG_MAX
#  define LONG_MAX 9223372036854775807L
# endif

# ifndef LONG_MIN
#  define LONG_MIN -9223372036854775808L
# endif

# ifndef ULONG_MAX
#  define ULONG_MAX 18446744073709551615UL
# endif

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef BYTE
#  define BYTE 8
# endif

//typedefs
typedef unsigned int	t_uint;
typedef unsigned char	t_uchar;
typedef unsigned long	t_ulong;

// Structs
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_tab
{
	void	**tab;
	size_t	rows;
	size_t	cols;
	size_t	element_size;
}	t_tab;

// Functions 
//
// Design disclaimer:
//
// List functions use 'lst_' instead of 'ft_' prefix
// for readability and brevity within the lib
//
// Some functions do not use the 'nonnull' attribute, 
// even though one might expect them to.
//
// This is an intentional design choice for flexibility and safety. 
// For example, NULL inputs are gracefully handled in the following cases:
//
// lst_new_node     -> Allows initializing a node with NULL content
// ft_free          -> Frees and nullifies pointer if not NULL
// ft_split_len     -> Returns 0 for NULL input
// ft_str_join      -> Allows joining when one string is NULL
// ft_str_join_free -> Same as above
// ft_strlen        -> NULL-safe, returns 0
// lst_size         -> Returns 0 if the list is NULL
//
//
// Char
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isnumspace(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

// Conversion
int		ft_atoi_base(const char *nptr, const char *base)
		__attribute__((nonnull(1, 2)));
int		ft_atoi(const char *nptr)
		__attribute__((nonnull(1)));
char	*ft_itoa_base(int n, char *base)
		__attribute__((nonnull(2)));
char	*ft_itoa(int n);

// IO
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

// Lst
void	lst_add_end(t_list **head, t_list *new)
		__attribute__((nonnull(1, 2)));
void	lst_add_start(t_list **head, t_list *new)
		__attribute__((nonnull(1, 2)));
void	lst_bubble_sort(t_list *head, int (*cmp)(void *, void *))
		__attribute__((nonnull(1, 2)));
void	lst_del_all(t_list **head, void (*del)(void*))
		__attribute__((nonnull(1)));
void	lst_del_node(t_list *node, void (*del)(void*))
		__attribute__((nonnull(1)));
void	lst_for_each(t_list *head, void (*f)(void *))
		__attribute__((nonnull(1, 2)));
int		lst_size(t_list *head);
t_list	*lst_deep_dup(t_list *head, void *(*copy)(void *), void (*del)(void *))
		__attribute__((nonnull(1, 2, 3)));
t_list	*lst_detach(t_list **head, t_list *node)
		__attribute__((nonnull(1, 2)));
t_list	*lst_dup(t_list *head, void (*del)(void *))
		__attribute__((nonnull(1, 2)));
t_list	*lst_last(t_list *head)
		__attribute__((nonnull(1)));
t_list	*lst_map(t_list *head, void *(*f)(void *), void (*del)(void *))
		__attribute__((nonnull(1, 2, 3)));
t_list	*lst_new_node(void *content);
t_list	*lst_search(t_list *head, void *target, int (*cmp)(void *, void *))
		__attribute__((nonnull(1, 3)));

// Matrix
void	ft_tab_free(t_tab *tab)
		__attribute__((nonnull(1)));
void	ft_tab_free_content(t_tab *tab)
		__attribute__((nonnull(1)));
t_tab	*ft_tab_dup(t_tab tab);
t_tab	*ft_tab_init_alloc(t_tab *tab, size_t rows, size_t cols, size_t e_size)
		__attribute__((nonnull(1)));
t_tab	*ft_tab_init_empty(t_tab *tab, size_t rows, size_t cols, size_t e_size)
		__attribute__((nonnull(1)));
t_tab	*ft_tab_init_fields(t_tab *tab, size_t rows, size_t cols, size_t e_size)
		__attribute__((nonnull(1)));

// Memory
void	ft_bzero(void *s, size_t n)
		__attribute__((nonnull(1)));
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n)
		__attribute__((nonnull(1)));
void	*ft_memcpy(void *dest, const void *src, size_t n)
		__attribute__((nonnull(1, 2)));
void	*ft_memmove(void *dest, const void *src, size_t n)
		__attribute__((nonnull(1, 2)));
void	*ft_memset(void	*s, int c, size_t n)
		__attribute__((nonnull(1)));
int		ft_free(void **s);
int		ft_memcmp(const void *s1, const void *s2, size_t n)
		__attribute__((nonnull(1, 2)));

// String
char	**ft_split(char const *s, char c)
		__attribute__((nonnull(1)));
char	**ft_split_dup(char **split)
		__attribute__((nonnull(1)));
void	ft_split_free(char **split)
		__attribute__((nonnull(1)));
size_t	ft_split_len(char **split);
void	ft_split_print(char **split)
		__attribute__((nonnull(1)));
int		ft_strncmp(const char *s1, const char *s2, size_t n)
		__attribute__((nonnull(1, 2)));
char	*ft_str_allinset(const char *string, const char *set)
		__attribute__((nonnull(1, 2)));
char	*ft_strchr(const char *s, int c)
		__attribute__((nonnull(1)));
char	*ft_strdup(const char *s)
		__attribute__((nonnull(1)));
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(t_uint, char))
		__attribute__((nonnull(1, 2)));
char	*ft_strnstr(const char *big, const char *little, size_t len)
		__attribute__((nonnull(1, 2)));
char	*ft_strrchr(const char *s, int c)
		__attribute__((nonnull(1)));
char	*ft_strtrim(char const *s1, char const *set)
		__attribute__((nonnull(1, 2)));
char	*ft_substr(char const *s, t_uint start, size_t len)
		__attribute__((nonnull(1)));
void	ft_striteri(char *s, void (*f)(t_uint, char*))
		__attribute__((nonnull(1, 2)));
size_t	ft_str_charcount(const char *s, int c)
		__attribute__((nonnull(1)));
size_t	ft_strlcat(char *dst, const char *src, size_t size)
		__attribute__((nonnull(1, 2)));
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
		__attribute__((nonnull(1, 2)));
size_t	ft_strlen(const char *s);

// Array

void	ft_quick_sort(int *array, int start, int end)
		__attribute__((nonnull(1)));
int		ft_get_min(int *array, size_t len)
		__attribute__((nonnull(1)));
void	ft_dual_quick_sort(int *array, int start, int end)
		__attribute__((nonnull(1)));

// Other Projects
char	*get_next_line(int fd);
int		ft_printf(const char *s, ...)
		__attribute__((nonnull(1)));

#endif