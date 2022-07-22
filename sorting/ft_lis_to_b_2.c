/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis_to_b_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:31:19 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/22 18:38:30 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
void	ft_helper_2(int *list)
{
	int	i;

	i = 499;
	while (i >= 0)
	{
		list[i] = -1;
		i--;
	}
}

void	ft_helper_1(int *length, int *list, int *subsequence, int i)
{
	int	k;
	int	index_of_max;

	k = 0;
	index_of_max = i;
	while (k < length[i])
	{
		list[k] = index_of_max;
		// printf("List at %d has value: %d\n", k, index_of_max);
		index_of_max = subsequence[index_of_max];
		k++;
	}
}

int	ft_find_steps_while_pushing(struct s_stacks **a, struct s_stacks **b, int k)
{
	struct s_stacks	*iterator;
	int				pos;

	iterator = *b;
	pos = k;
	while (k != 0) // walking up the iterator to the position of where I operate.
	{
		iterator = iterator->next;
		k--;
	}
	iterator->i = ft_op_rot_b(b, pos);
	// printf("Operating on node with value: %d\n", iterator->integer);
	if (ft_is_in_stack(a, (iterator->sorted - 1)) != -1)
		iterator->j = ft_op_rot_a(a, ft_is_in_stack(a, (iterator->sorted + 1)));
	else if (iterator->sorted == (ft_lstsize(*a) + ft_lstsize(*b) - 1))
		iterator->j = ft_op_rot_a(a, ft_is_in_stack(a, 0));
	else
		return (-1);
	// printf("Returning values before combine: %d, %d\n", iterator->i, iterator->j);
	return (ft_combine(iterator->i, iterator->j, iterator));
}

void	ft_unite_while_pushing(struct s_stacks **a, struct s_stacks **b, int k)
{
	struct s_stacks	*iterator_b;
	int				j;
	int				i;
	int				m;

	iterator_b = *b;
	// printf("Hi! \n");
	// printf("Iterator_b value and op steps: %d, %d\n", iterator_b->integer, iterator_b->op_steps);
	while (iterator_b->op_steps != k && iterator_b->next != NULL)
		iterator_b = iterator_b->next;
	// printf("Operation taking place on: %d, i: %d, j: %d\n", iterator_b->integer, iterator_b->i, iterator_b->j);
	j = iterator_b->j;
	i = iterator_b->i;
	m = iterator_b->m;
	if (m > 0)
		ft_rr(a, b, m); // repeated rotate (both a and b)
	if (m < 0)
		ft_rrr(a, b, m); // repeated reverse rotate (both a and b)
	// printf("i: %d, j: %d\n", i, j);
	ft_rest(a, b, i, j);
	// printf("a:\n");
	// ft_print_stack(a);
	// printf("b:\n");
	// ft_print_stack(b);
	ft_operations(a, b, 3); // push to a
	ft_operations(a, b, 5); // rotate a
	// printf("a:\n");
	// ft_print_stack(a);
	// printf("b:\n");
	// ft_print_stack(b);
}

