/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:26:30 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/08 10:45:01 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_lstiter_a(t_stacks *lst, void (*f)(void *))
{
	t_stacks	*ptr;

	ptr = lst;
	if (lst == NULL)
		return ;
	while (ptr != NULL)
	{	
		f(ptr);
		ptr = ptr->next;
	}
}
