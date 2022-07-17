/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:24:14 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/08 10:44:00 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_lstadd_front_a(t_stacks **lst, t_stacks *new)
{
	t_stacks	*temp;

	temp = *lst;
	if (lst == NULL)
		*lst = new;
	*lst = new;
	new->next = temp;
}
