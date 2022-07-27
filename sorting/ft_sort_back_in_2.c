/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_back_in_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:45:13 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/25 15:41:36 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_rr(struct s_stacks **a, struct s_stacks **b, int m)
{
	while (m > 0)
	{
		ft_operations(a, b, 56);
		m--;
	}
}

void	ft_rrr(struct s_stacks **a, struct s_stacks **b, int m)
{
	while (m < 0)
	{
		ft_operations(a, b, 78);
		m++;
	}
}

void	ft_rest(struct s_stacks **a, struct s_stacks **b, int i, int j)
{
	if (i != 0)
		ft_helper_2(a, b, i);
	while (j != 0)
	{
		if (j > 0)
		{
			ft_operations(a, b, 5);
			j--;
		}
		else if (j < 0)
		{
			ft_operations(a, b, 7);
			j++;
		}
	}
}
