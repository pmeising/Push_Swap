/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:26:16 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/19 19:34:27 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// Writing a function that is capable of switching nodes inside the stack.
// Passed in is the pointer to the node that is supposed to be switched with 
// its successor.

void	ft_switch(struct s_stacks **ptr_to_node, struct s_stacks **c)
{
	struct s_stacks	*node;
	struct s_stacks	*node2;
	struct s_stacks	*temp;

	node = *ptr_to_node;
	if (ptr_to_node == NULL || node->next == NULL)
		ft_error(6, 0);
	else
	{
		node2 = node->next;
		if (node->previous != NULL)
			node->previous->next = node2;
		else
			*c = node2;
		if (node2->next != NULL)
			node2->next->previous = node;
		temp = node->previous;
		node->previous = node2;
		node->next = node2->next;
		node2->previous = temp;
		node2->next = node;
	}
}
