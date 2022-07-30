/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:35:34 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/30 18:35:19 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// finds position of maximum int and returns index of max int.

int	ft_helper_9(struct s_stacks **a)
{
	t_stacks	*iterator;
	int			i;
	int			j;
	int			k;

	iterator = *a;
	j = iterator->integer;
	k = 0;
	i = k;
	iterator = iterator->next;
	while (iterator != NULL)
	{
		if (iterator->integer > iterator->previous->integer
			&& iterator->integer > j)
		{
			j = iterator->integer;
			i = k + 1;
		}
		iterator = iterator->next;
		k++;
	}
	return (i);
}

// Finds min and returns its index.

int	ft_helper_10(struct s_stacks **a)
{
	t_stacks	*iterator;
	int			i;
	int			j;
	int			k;

	iterator = *a;
	j = iterator->integer;
	k = 0;
	i = k;
	iterator = iterator->next;
	while (iterator != NULL)
	{
		if (iterator->integer < iterator->previous->integer
			&& iterator->integer < j)
		{
			j = iterator->integer;
			i = k + 1;
		}
		iterator = iterator->next;
		k++;
	}
	return (i);
}

void	ft_helper_11(t_stacks **a, t_stacks **b)
{
	t_stacks	*ptr;
	int			pos_min;

	ptr = *b;
	pos_min = ft_helper_10(a);
	if (ft_lstsize(*a) == 5)
	{
		ft_helper_12(a, b, ft_op_rot_a(a, pos_min));
		ft_operations(a, b, 4);
	}
	pos_min = ft_helper_10(a);
	ft_helper_12(a, b, ft_op_rot_a(a, pos_min));
	ft_operations(a, b, 4);
	ft_helper_8(a, b);
	ptr = *b;
	while (ptr != NULL)
	{
		ft_operations(a, b, 3);
		ptr = *b;
	}
}

// receives the j element as j and rotates optimally.

void	ft_helper_12(t_stacks **a, t_stacks **b, int j)
{
	while (j > 0)
	{
		ft_operations(a, b, 5);
		j--;
	}
	while (j < 0)
	{
		ft_operations(a, b, 7);
		j++;
	}
}
