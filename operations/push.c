/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 23:00:48 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/25 14:46:12 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// When pushing, I have a source list and a destination list.
// When the source list is empty, I'll throw an error, as this is
// a effectless action. When the destination is empty, I'll have to create a 
// new node in it. If it is not empty, I'll have to add it to the top.

void	ft_push(struct s_stacks **src, struct s_stacks **dest)
{
	struct s_stacks	*iterator_of_src;
	struct s_stacks	*iterator_of_dest;
	struct s_stacks	*temp;

	iterator_of_src = *src;
	iterator_of_dest = *dest;
	temp = *src;
	if (iterator_of_src == NULL)
		ft_error(8, 0);
	if (iterator_of_src->next != NULL)
		iterator_of_src->next->previous = NULL;
	*src = iterator_of_src->next;
	temp->next = iterator_of_dest;
	if (iterator_of_dest != NULL)
		iterator_of_dest->previous = temp;
	*dest = temp;
}
