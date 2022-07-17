/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:05:15 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/15 21:30:19 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_stacks	*ft_lstlast(struct s_stacks *lst)
{
	if (lst == NULL)
		return (lst);
	while (((lst->next) != NULL))
		lst = lst->next;
	return (lst);
}
