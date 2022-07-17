/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:44:25 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/16 19:45:28 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.



// Problem: integer values do not have a "null" option.
// I need a way to clarify when the node is empty.
// If I choose "0", the value "0" will be interpreted as
// the node to be empty. By this "0" can't be used.
// However, I'll introduce another struct in the linked 
// list, which will point to either "NULL" for an empty
// node, or the int 0 for the value 0.

// Addendum:	Will solve this issue by simply deleting the empty nodes.

// In order to check wheter I can switch the first two, I
// only need to check, if the 2nd node is empty or not. If 
// it is, I don't switch, it isn't, I do.

void	ft_swap(struct s_stacks **list)
{
	struct s_stacks	*ptr_to_head;
	struct s_stacks	*temp1;
	struct s_stacks	*temp2;
	int				i;

	i = 0;
	ptr_to_head = *list;
	if (ptr_to_head == NULL || ptr_to_head->next == NULL)
		ft_error(6, 0, NULL);
	else
	{
		ptr_to_head->previous = ptr_to_head->next;
		ptr_to_head->next->previous = NULL;
		temp1 = ptr_to_head->next->next;
		temp2 = ptr_to_head->next;
		ptr_to_head->next = temp1;
		temp2->next = ptr_to_head;
		*list = temp2;
	}
}
