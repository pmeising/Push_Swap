/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_back_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:15:49 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/23 11:18:50 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// I check if i and j would benefit from doing both ra and rb at the 
// same time. If both are negative, it makes sense to use rr or rrr.
// returning i + j + m, returns the minimum amount of steps the sorting
// would need. (Expectedly/theoretically)
// Also updating m, i and j on the elements of the node.

int	ft_combine(int i, int j, struct s_stacks *iterator)
{
	int	m;

	m = 0;
	if (i == 0 || j == 0)
		return (ft_abs(j) + ft_abs(i));
	if (i > 0 && j > 0)
	{
		while (i > 0 && j > 0)
		{
			j--;
			i--;
			m++;
		}
	}
	if (i < 0 && j < 0)
	{
		while (i < 0 && j < 0)
		{
			j++;
			i++;
			m--;
		}
	}
	iterator->m = m;
	iterator->i = i;
	iterator->j = j;
	return (ft_abs(j) + ft_abs(i) + ft_abs(m));
}

int	ft_spot_exists(struct s_stacks **a, int sorted)
{
	struct s_stacks	*head;
	int				i;

	head = *a;
	i = 0;
	while (head->next != NULL)
	{
		if (sorted > head->sorted && sorted < head->next->sorted)
			return (i + 1);
		i++;
		head = head->next;
	}
	return (-1);
}

// i represents the steps it takes to get the value on b to the top.
// j represents the steps it takes to get the value on a to the top.
// putting i and j on the variables in the list.

int	ft_find_steps(struct s_stacks **a, struct s_stacks **b, int k)
{
	struct s_stacks	*iterator;
	int				pos;

	iterator = *b;
	pos = k;
	iterator->m = 0;
	while (k != 0) // walking up the iterator to the position of where I operate.
	{
		iterator = iterator->next;
		k--;
	}
	iterator->i = ft_op_rot_b(b, pos);
	if (iterator->sorted < ft_find_min_ret_value(a))
		iterator->j = ft_op_rot_a(a, ft_find_min_ret_pos(a));
	else if (ft_spot_exists(a, iterator->sorted) != -1)
		iterator->j = ft_op_rot_a(a, ft_spot_exists(a, iterator->sorted));
	else if (iterator->sorted == ((ft_lstsize(*a) + ft_lstsize(*b)) - 1) && ft_is_in_stack(a, 0) != -1)
		iterator->j = ft_op_rot_a(a, ft_is_in_stack(a, 0));
	else
		return (-1);
	return (ft_combine(iterator->i, iterator->j, iterator));
}

void	ft_a(struct s_stacks **a, struct s_stacks **b)
{
	struct s_stacks	*iterator_a;
	int				i;

	iterator_a = *a;
	i = 0;
	while (iterator_a->sorted != 0)
	{
		iterator_a = iterator_a->next;
		i++;
	}
	i = ft_op_rot_a(a, i);
	while (i != 0)
	{
		if (i > 0)
		{
			ft_operations(a, b, 5); // rotate a
			i--;
		}	
		else if (i < 0)
		{
			ft_operations(a, b, 7); // rev rotate a
			i++;
		}	
	}
}

// for each node on b, find the lowest number of operations neccessary to get it to its position on a (including rotations on a).
// then compare each value and find the lowest.
// act on it and enforce that sequence of steps.
// the lowest # of actions is not identifying the correct node without doubt.
// There might be overlaps. It will always take the last occurence. I need to walk down the list 
// from the back to fix it.

void	ft_unite(struct s_stacks **a, struct s_stacks **b, int k, int position)
{
	struct s_stacks	*iterator_b;
	int				j;
	int				i;
	int				m;

	iterator_b = *b;
	// printf("Hi! \n");
	// printf("Iterator_b value and op steps: %d, %d\n", iterator_b->integer, iterator_b->op_steps);
	while (iterator_b->op_steps != k && iterator_b->next != NULL && iterator_b->sorted != position)
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
	// printf("a:\n");
	// ft_print_stack(a);
	// printf("b:\n");
	// ft_print_stack(b);
}

void	ft_sort_back_in_new(struct s_stacks **a, struct s_stacks **b)
{
	struct s_stacks	*iterator_b;
	int				pos;
	int				position;

	iterator_b = *b;
	while (*b != NULL)
	{
		pos = 0;
		iterator_b = *b;
		while (iterator_b != NULL) // walking through setting lowest # of steps to op_steps sets values for i, j and m.
		{
			iterator_b->op_steps = ft_find_steps(a, b, pos);
			// printf("Walking through b and setting i: %d, j: %d and m: %d, op_steps: %d.\n", iterator_b->i, iterator_b->j, iterator_b->m, iterator_b->op_steps);
			// printf("Stack a contains: \n");
			// ft_print_stack(a);
			// printf("Stack b contains: \n");
			// ft_print_stack(b);
			pos++;
			iterator_b = iterator_b->next;
		}
		iterator_b = *b;
		pos = 10000;
		while (iterator_b != NULL) // finds node with lowest op_steps in b and puts index of where it is.
		{
			if (iterator_b->op_steps < pos && iterator_b->op_steps != -1)
			{
				pos = iterator_b->op_steps;
				position = iterator_b->sorted;
				// printf("Lowest # of steps: %d at node-sorted: %d\n", pos, iterator_b->sorted);
			}
			iterator_b = iterator_b->next;
		}
		// printf("Shortest route is: %d\n", pos);
		// Supposed to find node and it's partner node on a and operate on it.
		// walks through b and locates lowest opsteps with iterator. Then acts on those steps.
		// Now we have the node on b, we have the steps it takes them to be on top, so we can just act on them.
		ft_unite(a, b, pos, position);
		// printf("Stack a contains: \n");
		// ft_print_stack(a);
		// printf("Stack b contains: \n");
		// ft_print_stack(b);
	}
	ft_a(a, b);
}
