/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_back_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:15:49 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/19 21:53:28 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// thanks to LIS we are guaranteed to always have the highest and lowest int 
// values on stack a. Also, they have to be sitting next to one another.
// Additionally, we know, that the highest int on the stack has to be at the
// end of the stack.

// SUPER INCORRECT ASSUMPTION!!!!!
// TAKE INPUT ./a.out 1 93 -34 39 -325 20 3 -5 for example. A consists of
// -325 and -5.


// Only rotated once here. Need to implement a while loop. XD

void	ft_optimise_rotation(struct s_stacks **a, struct s_stacks **b)
{
	struct s_stacks	*iterator;
	int	i;
	int	j;
	int	size;

	iterator = *a;
	i = 0;
	size = ft_lstsize(*a);
	while (iterator->next != NULL)
	{
		if (iterator->sorted == (size - 1))
			break;
		i++;
		iterator = iterator->next;
	}
	j = i;
	while (j >= 0)
	{
		if (i < (size/2))
			ft_operations(a, b, 5); // rotate a
		else
			ft_operations(a, b, 7); // reverse rotate a
		j--;
	}
}

int	ft_is_in_stack(struct s_stacks **a, int i)
{
	struct s_stacks	*head;
	int	j;
	int	size;

	head = *a;
	size = ft_lstsize(head);
	j = 0;
	while (j < size)
	{
		if (head->sorted == i)
			return (j);
		j++;
		head = head->next;
	}
	return (-1);
}

void	ft_find_push(struct s_stacks **a, struct s_stacks **b, int i)
{
	int	pos;

	pos = ft_is_in_stack(b, i);
	if (pos == -1)
		printf("Did not find value in stack\n");
	if (pos != 0)
		ft_op_rot_b(a, b, pos);
	ft_operations(a, b, 5); // rotate a
	ft_operations(a, b, 3); // push to a
}

void	ft_sort_back_in(struct s_stacks **a, struct s_stacks **b)
{
	struct s_stacks	*head_a;
	struct s_stacks	*head_b;
	int				min;
	int				max;

	max = ft_lstsize(*a) + ft_lstsize(*b);
	head_a = *a;
	head_b = *b;
	while (head_b != NULL)
	{
		if (head_a->sorted == (max - 1))
			ft_operations(a, b, 5); // rotate a
		else if (head_a->sorted == 1 && ft_is_in_stack(b, 0) == 0)
			ft_operations(a, b, 3); // push to a
		else
		{
			if (ft_is_in_stack(a, head_a->sorted + 1) == -1)
				ft_find_push(a, b, head_a->sorted + 1);
			else
				ft_operations(a, b, 5); // rotate a
		}
		head_a = *a;
		head_b = *b;
	}
	min = ft_find_min(a);
	if (head_a->sorted != 0)
		ft_op_rot_a(a, b, min);
}
