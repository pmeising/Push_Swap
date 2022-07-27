/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:25:52 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/27 15:38:11 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_helper_4(int i, int j, int m, struct s_stacks *iterator)
{
	iterator->m = m;
	iterator->i = i;
	iterator->j = j;
}

int	ft_helper_5(struct s_stacks **b)
{
	struct s_stacks	*iterator_b;
	int				pos;

	pos = 10000;
	iterator_b = *b;
	while (iterator_b != NULL)
	{
		if (iterator_b->op_steps < pos && iterator_b->op_steps != -1)
			pos = iterator_b->op_steps;
		iterator_b = iterator_b->next;
	}
	return (pos);
}

int	ft_helper_6(struct s_stacks **b)
{
	struct s_stacks	*iterator_b;
	int				pos;
	int				position;

	pos = 10000;
	position = 0;
	iterator_b = *b;
	while (iterator_b != NULL)
	{
		if (iterator_b->op_steps < pos && iterator_b->op_steps != -1)
		{
			pos = iterator_b->op_steps;
			position = iterator_b->sorted;
		}
		iterator_b = iterator_b->next;
	}
	return (position);
}

int	ft_helper_7(int i, const char *nptr)
{
	int	nbr;

	nbr = 0;
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		nbr = nbr * 10 + nptr[i] - 48;
		i++;
	}
	return (nbr);
}

void	ft_helper_8(struct s_stacks **a, struct s_stacks **b)
{
	ft_operations(a, b, 1);
	while (ft_check_if_sorted(a) != 1)
		ft_operations(a, b, 5);
}
