/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:43:32 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/23 11:05:46 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_is_in(int *list, int i, int max)
{
	int	j;

	j = 0;
	while (j < max)
	{
		if (list[j] == i)
			return (1);
		j++;
	}
	return (0);
}

// I realized, that if length[index] of max == 1 (or rather the longest 
// increasing subsequence is 1) that means, that the stack is sorted upside
// down. The fastest way to sorting it, is to rev. rotate, push to b until a 
// only has 2 nodes. Then swap these nodes and start pushing from b until b
// is empty. That is what ft_one_sorted does.

void	ft_one_sorted(struct s_stacks **a, struct s_stacks **b)
{
	struct s_stacks	*head_a;
	struct s_stacks	*head_b;

	head_a = *a;
	head_b = *b;
	while (head_a->next->next != NULL)
	{
		ft_operations(a, b, 7); // reverse rotate a
		ft_operations(a, b, 4); // push to b
		head_a = *a;
	}
	ft_operations(a, b, 1); // swap a
	head_b = *b;
	while (head_b != NULL)
	{
		ft_operations(a, b, 3); // push to a
		head_b = *b;
	}
}

void	ft_lis_to_b(struct s_stacks **a, struct s_stacks **b, int *length,
int *subsequence)
{
	struct s_stacks	*iterator;
	int				index_of_max;
	int				k;
	int				list[500];
	int				size;

	k = 0;
	index_of_max = ft_find_max(&length[0]);
	if (length[index_of_max] == 1)
		ft_one_sorted(a, b);
	ft_helper_2(&list[0]);
	ft_helper_1(&length[0], &list[0], &subsequence[0], index_of_max);
	size = ft_lstsize(*a) + ft_lstsize(*b);
	while (k <= index_of_max)
	{
		iterator = *a;
		if (ft_is_in(&list[0], iterator->index, length[index_of_max]) == 0) // if not part of LIS
		{
			ft_operations(a, b, 4); // push to b.
			if (iterator->sorted > size/2 && ft_lstsize(*b) > 1)
				ft_operations(a, b, 6); // rotate b
		}
		else if ((ft_is_in(&list[0], iterator->index, index_of_max) == 1) && k <= index_of_max) // if part of LIS
		{
			ft_operations(a, b, 5); // rotate a.
			k++;
		}
		if (k == index_of_max && iterator->next != NULL &&
		 ft_is_in(&list[0], iterator->next->index, length[index_of_max]) == 1)
			break;
	}
}
