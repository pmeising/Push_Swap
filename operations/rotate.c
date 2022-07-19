/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:13:37 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/19 19:29:44 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_rotate(struct s_stacks **lst)
{
	struct s_stacks	*ptr_to_first;
	struct s_stacks	*iterator;
	struct s_stacks	*ptr_last;

	iterator = *lst;
	ptr_to_first = *lst;
	ptr_last = iterator;
	if (ptr_to_first == NULL || ptr_to_first->next == NULL)
		ft_error(7, 0);
	while (ptr_last->next != NULL)
		ptr_last = ptr_last->next;
	iterator = iterator->next;
	iterator->previous = NULL;
	ptr_to_first->next = NULL;
	ptr_to_first->previous = ptr_last;
	ptr_last->next = ptr_to_first;
	*lst = iterator;
}
