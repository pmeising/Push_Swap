/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_back_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:15:49 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/17 20:26:29 by pmeising         ###   ########.fr       */
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

void	ft_optimise_rotation(struct s_stacks **a, struct s_stacks **b)
{
	struct s_stacks	*iterator;
	int	i;
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
	if (i < (size/2))
		ft_operations(a, b, 5); // rotate a
	else
		ft_operations(a, b, 7); // reverse rotate a
}

void	ft_sort_back_in(struct s_stacks **a, struct s_stacks **b)
{
	struct s_stacks	*head_a;
	struct s_stacks	*head_b;

	head_a = *a;
	head_b = *b;
	while (head_b != NULL)
	{
		if (head_b->sorted == ((ft_lstlast(*a)->sorted) + 1))
		{
			ft_operations(a, b, 3); // push to a
			ft_operations(a, b, 5); // rotate a
		}
		else if (head_b->next != NULL &&
		 head_b->next->sorted == ((ft_lstlast(*a)->sorted) + 1))
		{
			ft_operations(a, b, 6); // rotate b
			ft_operations(a, b, 3); // push to a
		}
		else
			ft_operations(a, b, 5); // rotate a
		head_a = *a;
		head_b = *b;
	}
	while (ft_check_if_sorted(&head_a) == 0)
		ft_optimise_rotation(a, b);
}
