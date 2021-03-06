/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:56:01 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/30 18:52:12 by pmeising         ###   ########.fr       */
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

// by declaring t_stacks here, we can shorten the struct s_stacks to t_stacks

// void	ft_print_stack(struct s_stacks **stack);

char		*ft_strchr(const char *s, int c);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
int			ft_atolonglong(const char *nptr);

// Error checks

void		ft_error(int ecode, int position);
void		ft_check_errors(int argc, char **argv);
int			ft_check(char *list);

// Operations on t_stacks:

t_stacks	*ft_lstnew(int content);
t_stacks	*ft_lstlast(struct s_stacks *lst);
t_stacks	*ft_lstmap(t_stacks *lst, void *(*f)(void *), void (*del)(void *));
int			ft_lstsize(t_stacks *lst);
void		ft_lstadd_front(t_stacks **lst, t_stacks *new);
void		ft_lstadd_back(t_stacks **lst, t_stacks *new);
void		ft_lstdelone(t_stacks *lst, void (*del)(void *));
void		ft_lstclear(t_stacks **lst);
void		ft_del_lst(struct s_stacks **lst);
void		ft_swap(struct s_stacks **list);
void		ft_rotate(struct s_stacks **lst);
void		ft_rev_rotate(struct s_stacks **lst);
void		ft_push(struct s_stacks **src, struct s_stacks **dest);
void		ft_operations(struct s_stacks **a, struct s_stacks **b,
				int operation);

// sorting the list

//		 Low # of ints:

void		ft_sort_short(t_stacks **a, t_stacks **b);
int			ft_helper_9(struct s_stacks **a);
int			ft_helper_10(struct s_stacks **a);
void		ft_helper_11(t_stacks **a, t_stacks **b);
void		ft_helper_12(t_stacks **a, t_stacks **b, int j);

// 		High # of ints:

void		ft_sort(struct s_stacks **a, struct s_stacks **b);
void		ft_lis(struct s_stacks **lst, int *subsequence, int *length);
void		ft_lis_to_b(struct s_stacks **a, struct s_stacks **b, int *length,
				int *subsequence);
void		ft_put_1s(int *array, int *length);
int			ft_find_max(int	*length);
int			ft_is_in(int *list, int i, int max);
int			ft_is_in_stack(struct s_stacks **a, int i);
void		ft_sort_back_in_new(struct s_stacks **a, struct s_stacks **b);
void		ft_put_sorted(struct s_stacks **a);
int			ft_check_if_sorted(struct s_stacks **c);
int			ft_abs(int i);
void		ft_rr(struct s_stacks **a, struct s_stacks **b, int m);
void		ft_rrr(struct s_stacks **a, struct s_stacks **b, int m);
void		ft_rest(struct s_stacks **a, struct s_stacks **b, int j, int i);
void		ft_helper_1(int *length, int *list, int *subsequence, int i);
void		ft_helper_2(struct s_stacks **a, struct s_stacks **b, int i);
void		ft_helper_3(struct s_stacks **a, struct s_stacks **b);
void		ft_helper_4(int i, int j, int m, struct s_stacks *iterator);
int			ft_helper_5(struct s_stacks **b);
int			ft_helper_6(struct s_stacks **b);
int			ft_helper_7(int i, const char *nptr);
void		ft_helper_8(struct s_stacks **a, struct s_stacks **b);
int			ft_find_steps(struct s_stacks **a, struct s_stacks **b, int k);
int			ft_find_steps_while_pushing(struct s_stacks **a, struct s_stacks
				**b, int k);
void		ft_unite_while_pushing(struct s_stacks **a, struct s_stacks **b,
				int k);
int			ft_combine(int i, int j, struct s_stacks *iterator);
void		ft_one_off(struct s_stacks **a, struct s_stacks **b);
int			ft_spot_exists(struct s_stacks **a, int sorted);

// Sorting funcs on c.

void		ft_switch(struct s_stacks **ptr_to_node, struct s_stacks **c);
void		ft_switch_head(struct s_stacks **ptr_to_node);

// printing stacks

void		ft_print_stack(struct s_stacks **stack);

// Miscellaneous

int			ft_find_max(int	*length);
int			ft_find_min_ret_value(struct s_stacks **c);
int			ft_find_min_ret_pos(struct s_stacks **c);
void		ft_op_rot_a_old(struct s_stacks **a, struct s_stacks **b, int pos);
void		ft_op_rot_b_old(struct s_stacks **a, struct s_stacks **b, int pos);

// NEW SORTING OPTIMIZATION
int			ft_op_rot_a(struct s_stacks **a, int pos);
int			ft_op_rot_b(struct s_stacks **b, int pos);

// BONUS

void		ft_trlt_op(struct s_stacks **a, struct s_stacks **b,
				char *instruction);
void		ft_check_instruction(struct s_stacks **a, char *instruction);
void		ft_read_from_terminal(struct s_stacks **a, struct s_stacks **b);
void		ft_b_operations(struct s_stacks **a, struct s_stacks **b,
				int operation);
char		*ft_calloc(size_t number, size_t size);
char		*get_next_line(int fd);

#endif
