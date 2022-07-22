/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:56:01 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/22 20:24:08 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "string.h"
# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"

typedef struct s_stacks
{
	int				integer;
	int				index;
	int				sorted;
	int				op_steps;
	int				i;
	int				j;
	int				m;
	struct s_stacks	*previous;
	struct s_stacks	*next;
}					t_stacks;

// What does t_stacks refer to? Is it the name of the struct or what?

char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int		ft_atolonglong(const char *nptr);

// Error checks

void	ft_error(int ecode, int position);
void	ft_check_errors(int argc, char **argv);
int		ft_check(char *list);

// Operations on t_stacks:

int			ft_lstsize(t_stacks *lst);
t_stacks	*ft_lstnew(int content);
void		ft_lstadd_front(t_stacks **lst, t_stacks *new);
void		ft_lstadd_back(t_stacks **lst, t_stacks *new);
void		ft_lstdelone(t_stacks *lst, void (*del)(void *));
void		ft_lstclear(t_stacks **lst);
t_stacks	*ft_lstlast(struct s_stacks *lst);
t_stacks	*ft_lstmap(t_stacks *lst, void *(*f)(void *), void (*del)(void *));
void		ft_del_lst(struct s_stacks **lst);

void		ft_swap(struct s_stacks **list);
void		ft_rotate(struct s_stacks **lst);
void		ft_rev_rotate(struct s_stacks **lst);
void		ft_push(struct s_stacks **src, struct s_stacks **dest);
void		ft_operations(struct s_stacks **a, struct s_stacks **b, int operation);

// sorting the list

void	ft_sort(struct s_stacks **a, struct s_stacks **b);
void	ft_lis(struct s_stacks **lst, int *subsequence, int *length);
void	ft_lis_to_b(struct s_stacks **a, struct s_stacks **b, int *length, 
int *subsequence);
void	ft_put_1s(int *array, int *length);
int		ft_find_max(int	*length);
int		ft_is_in(int *list, int i, int max);
int		ft_is_in_stack(struct s_stacks **a, int i);
void	ft_sort_back_in_new(struct s_stacks **a, struct s_stacks **b);
void	ft_put_sorted(struct s_stacks **a);
int		ft_check_if_sorted(struct s_stacks **c);
int		ft_abs(int i);
void	ft_rr(struct s_stacks **a, struct s_stacks **b, int m);
void	ft_rrr(struct s_stacks **a, struct s_stacks **b, int m);
void	ft_rest(struct s_stacks **a, struct s_stacks **b, int j, int i);
void	ft_helper_1(int *length, int *list, int *subsequence, int i);
void	ft_helper_2(int *list);
int		ft_find_steps(struct s_stacks **a, struct s_stacks **b, int k);
int		ft_find_steps_while_pushing(struct s_stacks **a, struct s_stacks **b, int k);
void	ft_unite_while_pushing(struct s_stacks **a, struct s_stacks **b, int k);
int		ft_combine(int i, int j, struct s_stacks *iterator);
void	ft_one_off(struct s_stacks **a, struct s_stacks **b);

// Sorting funcs on c.

void	ft_switch(struct s_stacks **ptr_to_node, struct s_stacks **c);
void	ft_switch_head(struct s_stacks **ptr_to_node);

// printing stacks

void	ft_print_stack(struct s_stacks **stack);

// Miscellaneous

int		ft_find_min(struct s_stacks **c);
void	ft_op_rot_a_old(struct s_stacks **a, struct s_stacks **b, int pos);
void	ft_op_rot_b_old(struct s_stacks **a, struct s_stacks **b, int pos);

// NEW SORTING OPTIMIZATION
int		ft_op_rot_a(struct s_stacks **a, int pos);
int		ft_op_rot_b(struct s_stacks **b, int pos);

#endif
