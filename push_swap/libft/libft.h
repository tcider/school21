/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:35:04 by tcider            #+#    #+#             */
/*   Updated: 2021/04/01 14:46:10 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define HSTR_SIZE 1000

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_xyz
{
	double			x;
	double			y;
	double			z;
}					t_xyz;

typedef struct		s_ilist
{
	int				value;
	int				index;
	int				tmp;
	char			flag;
	struct s_ilist	*next;
}					t_ilist;

typedef struct		s_stack
{
	int				size;
	t_ilist			*head;
	t_ilist			*tail;
}					t_stack;

typedef struct		s_heapstr
{
	int				size;
	char			*str;
}					t_heapstr;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/*
** For ft_printf
*/

void				ft_putchar(char c);
void				ft_putnchar(char c, int n);
void				ft_putnstr(char *str, int size);
char				*ft_litoa(long int n);
char				*ft_ulitoa(unsigned long int n);
void				ft_caddstr(char c, char **s);
void				ft_straddc(char **s, char c);
char				*ft_strwchar(int c, int *size);
int					ft_islcase(int c);
void				ft_strdelc(char **s);
void				ft_cdelstr(char **s);

/*
** Fot ft_minirt
*/

int					ft_minignl(int fd, char **line);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strtoi(char *str, char **tmp);
double				ft_strtof(char *str, char **tmp);
char				**ft_splitn(char const *s, char c, int *n);
char				**ft_splitw(char const *s, int *n);

/*
** 3 dimensions vectors functions library
*/

t_xyz				xyz_sub(t_xyz a, t_xyz b);
t_xyz				xyz_add(t_xyz a, t_xyz b);
t_xyz				xyz_mltnum(t_xyz a, double b);
double				xyz_len(t_xyz a);
t_xyz				xyz_norm(t_xyz a);
t_xyz				xyz_minus(t_xyz a);
double				xyz_mltxyz(t_xyz a, t_xyz b);
t_xyz				xyz_intersect(t_xyz a, t_xyz b);
t_xyz				xyz_new(double x, double y, double z);

/*
** For push_swap
*/

int					ft_strtoi_int(char *str, char **tmp);
int					ft_arr_findnum(int *arr, int len, int num);
void				ft_arr_sort(int *arr, int size);
int					*ft_arr_copy(int *arr, int size);
int					ft_arr_maxind(int *arr, int size);
int					*ft_arr_lcis(int *arr, int size, int *lcis_size);
int					*ft_arr_lcisind(int *arr, int size, int *lcis_size);
void				ft_arr_swap(int *arr, int i, int j);
t_stack				*ft_stack_create(void);
void				ft_stack_push(t_stack *stack, int value, int *error);
void				ft_stack_pushfull(t_stack *stack, t_ilist *list, \
					int *error);
int					ft_stack_pop(t_stack *stack, int *error);
void				ft_stack_print(t_stack *stack);
int					ft_stack_posbyval(t_stack *stack, int value);
int					ft_stack_posbyind(t_stack *stack, int ind);
int					ft_stack_issorted(t_stack *stack);
int					ft_stack_issortedb(t_stack *stack, int size);
void				ft_stack_swap(t_stack *stack);
void				ft_stack_rotate(t_stack *stack, int direction);
int					ft_stack_free(t_stack **stack);
int					ft_stack_top(t_stack *stack, int *error);
int					ft_stack_pretop(t_stack *stack, int *error);
void				ft_stack_push_back(t_stack *stack, int value, int *error);
void				ft_stack_printfull(t_stack *stack);
int					*ft_stack_toarr(t_stack *stack);
t_stack				*ft_stack_copy(t_stack *stack, int size);
t_ilist				*ft_stack_findbyind(t_stack *stack, int ind);
t_ilist				*ft_stack_findbyval(t_stack *stack, int value);
t_ilist				*ft_stack_findmintmp(t_stack *stack);
int					ft_stack_sort(t_stack *stack);
int					ft_stack_median(t_stack *stack, int size, int *error);
int					ft_stack_posminval(t_stack *stack);
int					ft_stack_isanyflag(t_stack *a);
t_heapstr			*ft_heapstr_create(void);
void				ft_heapstr_free(t_heapstr **hstr);
int					ft_heapstr_add(t_heapstr *hstr, char c);
int					ft_min(int a, int b);
int					ft_mod(int a);
int					ft_strcmp_spaced(const char *s1_spaced, const char *s2);

#endif
