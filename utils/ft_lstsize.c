/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:55:28 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/16 19:04:32 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_lstsize(t_stacks *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (i);
	while ((lst != NULL))
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
