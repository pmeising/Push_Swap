/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:13:00 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/18 22:16:43 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_op_rot_a(struct s_stacks **a, struct s_stacks **b, int pos)
{
	struct s_stacks	*iterator;
	int	size;

	iterator = *a;
	size = ft_lstsize(*a);
	if (pos == 0)
		return ;
	while (pos != 0)
	{
		iterator = iterator->next;
		pos--;
	}
	while (iterator != *a)
	{
		if (pos < size/2)
			ft_operations(a, b, 5); // rotate a
		else if (pos >= size/2)
			ft_operations(a, b, 7); // rev rotate a	
	}
}

void	ft_op_rot_b(struct s_stacks **a, struct s_stacks **b, int pos)
{
	struct s_stacks	*iterator;
	int	size;


	iterator = *b;
	size = ft_lstsize(*b);
	if (pos == 0)
		return ;
	while (pos != 0)
	{
		iterator = iterator->next;
		pos--;
	}
	while (iterator != *b)
	{
		if (pos < size/2)
			ft_operations(a, b, 6); // rotate b
		else if (pos >= size/2)
			ft_operations(a, b, 8); // rev rotate b
	}
}
