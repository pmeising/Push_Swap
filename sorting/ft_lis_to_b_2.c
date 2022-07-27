/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis_to_b_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:31:19 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/25 15:42:15 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_helper_3(struct s_stacks **a, struct s_stacks **b)
{
	struct s_stacks	*iterator;
	int				size;

	iterator = *a;
	size = ft_lstsize(*a) + ft_lstsize(*b);
	ft_operations(a, b, 4);
	if (iterator->sorted > size / 2 && ft_lstsize(*b) > 1)
		ft_operations(a, b, 6);
}

void	ft_helper_2(struct s_stacks **a, struct s_stacks **b, int i)
{
	while (i != 0)
	{
		if (i > 0)
		{
			ft_operations(a, b, 6);
			i--;
		}
		else if (i < 0)
		{
			ft_operations(a, b, 8);
			i++;
		}
	}
}

void	ft_helper_1(int *length, int *list, int *subsequence, int i)
{
	int	k;
	int	index_of_max;
	int	m;

	m = 499;
	while (m >= 0)
	{
		list[m] = -1;
		m--;
	}
	k = 0;
	index_of_max = i;
	while (k < length[i])
	{
		list[k] = index_of_max;
		index_of_max = subsequence[index_of_max];
		k++;
	}
}
