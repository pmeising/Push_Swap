/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:06:30 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/08 10:44:31 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_lstclear_a(t_stacks **lst)
{
	t_stacks	*iterator;
	t_stacks	*first;

	if (lst == NULL)
		return ;
	first = *lst;
	iterator = first->next;
	while (first != NULL)
	{
		iterator = first->next;
		free(first);
		first = iterator;
	}
	*lst = NULL;
}
