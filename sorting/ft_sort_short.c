/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_short.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:56:27 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/30 19:01:56 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// Since I filter out before if the list is already sorted, I only have un-
// sorted lists here now. :)
// for size == 2, I just need to swap.
// for size == 3 

void	ft_sort_short(t_stacks **a, t_stacks **b)
{
	if (ft_lstsize(*a) == 2)
		ft_operations(a, b, 1);
	else if (ft_lstsize(*a) == 3)
		ft_helper_8(a, b);
	else
		ft_helper_11(a, b);
}
