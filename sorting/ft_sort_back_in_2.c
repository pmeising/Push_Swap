/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_back_in_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:45:13 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/21 18:43:40 by pmeising         ###   ########.fr       */
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
	while (i != 0)
	{
		if (i > 0)
		{
			ft_operations(a, b, 6); // rotate b
			i--;
		}
		else if (i < 0)
		{
			ft_operations(a, b, 8); // rev rotate b
			i++;
		}
	}
	while (j != 0)
	{
		if (j > 0)
		{
			ft_operations(a, b, 5); // rotate a
			j--;
		}
		else if (j < 0)
		{
			ft_operations(a, b, 7); // rev rotate a
			j++;
		}
	}
}
