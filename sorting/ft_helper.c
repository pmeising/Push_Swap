/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:25:52 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/30 18:36:01 by pmeising         ###   ########.fr       */
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
	long long	nbr;
	int			number;

	nbr = 0;
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		nbr = nbr * 10 + nptr[i] - 48;
		i++;
	}
	if (nbr > 2147483647 || nbr < -2147483648)
		ft_error(1, 1);
	number = (int)nbr;
	return (number);
}

// for # of ints == 3, I swap first, then I reverse rotate if not in correct
// order.
// helper_9 finds and returns the position of the maximum int of the sequence.
// if it is 3 1 2, I can just rotate a
// if it is 3 2 1, I need to swap and rev rotate

void	ft_helper_8(struct s_stacks **a, struct s_stacks **b)
{
	int	pos_min;
	int	pos_max;

	pos_min = ft_helper_10(a);
	pos_max = ft_helper_9(a);
	if (pos_min == 0)
	{
		ft_operations(a, b, 7);
		ft_operations(a, b, 1);
	}
	else if (pos_max == 0 && pos_min == 1)
		ft_operations(a, b, 5);
	else if (pos_max == 0 && pos_min == 2)
	{
		ft_operations(a, b, 1);
		ft_operations(a, b, 7);
	}
	else if (pos_max == 1 && pos_min == 2)
		ft_operations(a, b, 7);
	else
		ft_operations(a, b, 1);
}
