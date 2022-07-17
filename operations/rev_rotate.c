/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:45:47 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/11 22:59:40 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_rev_rotate(struct s_stacks **lst)
{
	struct s_stacks	*ptr_to_first;
	struct s_stacks	*iterator;
	struct s_stacks	*ptr_last;

	iterator = *lst;
	ptr_last = iterator;
	ptr_to_first = *lst;
	if (ptr_to_first == NULL || ptr_to_first->next == NULL)
		ft_error(7, 0, NULL);
	else
	{
		while (ptr_last->next != NULL)
			ptr_last = ptr_last->next;
		ptr_last->previous->next = NULL;
		ptr_last->next = ptr_to_first;
		ptr_to_first->previous = ptr_last;
		ptr_last->previous = NULL;
		*lst = ptr_last;
	}
}
