/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:14:04 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/08 10:55:47 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_lstadd_back(t_stacks **lst, t_stacks *new)
{
	t_stacks	*ptr_to_head;

	ptr_to_head = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (ptr_to_head->next != NULL)
		{
			ptr_to_head = ptr_to_head->next;
		}
		ptr_to_head->next = new;
		new->previous = ptr_to_head;
	}
}
