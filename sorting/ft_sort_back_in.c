/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_back_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:15:49 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/25 16:25:54 by pmeising         ###   ########.fr       */
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
	ft_helper_4(i, j, m, iterator);
	return (ft_abs(j) + ft_abs(i) + ft_abs(m));
}

// i represents the steps it takes to get the value on b to the top.
// j represents the steps it takes to get the value on a to the top.
// putting i and j on the variables in the list.
// Line 82: walking up the iterator to the position of where I operate.

int	ft_find_steps(struct s_stacks **a, struct s_stacks **b, int k)
{
	struct s_stacks	*iterator;
	int				pos;

	iterator = *b;
	pos = k;
	iterator->m = 0;
	while (k != 0)
	{
		iterator = iterator->next;
		k--;
	}
	iterator->i = ft_op_rot_b(b, pos);
	if (iterator->sorted < ft_find_min_ret_value(a))
		iterator->j = ft_op_rot_a(a, ft_find_min_ret_pos(a));
	else if (ft_spot_exists(a, iterator->sorted) != -1)
		iterator->j = ft_op_rot_a(a, ft_spot_exists(a, iterator->sorted));
	else if (iterator->sorted == ((ft_lstsize(*a) + ft_lstsize(*b)) - 1)
		&& ft_is_in_stack(a, 0) != -1)
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
			ft_operations(a, b, 5);
			i--;
		}	
		else if (i < 0)
		{
			ft_operations(a, b, 7);
			i++;
		}	
	}
}

// for each node on b, find the lowest number of operations neccessary 
// to get it to its position on a (including rotations on a).
// then compare each value and find the lowest.
// act on it and enforce that sequence of steps.
// the lowest # of actions is not identifying the correct node without doubt.
// There might be overlaps. It will always take the last occurence. 
// I need to walk down the list from the back to fix it.

void	ft_unite(struct s_stacks **a, struct s_stacks **b, int k, int position)
{
	struct s_stacks	*iterator_b;
	int				j;
	int				i;
	int				m;

	iterator_b = *b;
	while (iterator_b->op_steps != k && iterator_b->next != NULL
		&& iterator_b->sorted != position)
		iterator_b = iterator_b->next;
	j = iterator_b->j;
	i = iterator_b->i;
	m = iterator_b->m;
	if (m > 0)
		ft_rr(a, b, m);
	if (m < 0)
		ft_rrr(a, b, m);
	ft_rest(a, b, i, j);
	ft_operations(a, b, 3);
}

// walking through setting lowest # of steps to op_steps sets values for i, j 
// and m.
// finds node with lowest op_steps in b and puts index of where it is. 

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
		while (iterator_b != NULL)
		{
			iterator_b->op_steps = ft_find_steps(a, b, pos);
			pos++;
			iterator_b = iterator_b->next;
		}
		iterator_b = *b;
		pos = ft_helper_5(b);
		position = ft_helper_6(b);
		ft_unite(a, b, pos, position);
	}
	ft_a(a, b);
}
