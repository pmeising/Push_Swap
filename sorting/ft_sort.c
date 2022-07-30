/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:11:48 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/30 22:14:42 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_find_spot(t_stacks **a, t_stacks **b)
{
	t_stacks	*iter_b;
	t_stacks	*iter_a;

	iter_a = *a;
	iter_b = *b;
	while (iter_a->sorted != iter_b->sorted - 1)
		ft_operations(a, b, 5);
	ft_operations(a, b, 3);
}

int	ft_find_mistake(t_stacks **a)
{
	t_stacks	*iterator;
	int			i;

	i = 0;
	iterator = *a;
	while (iterator->sorted < iterator->next->sorted)
	{
		iterator = iterator->next;
		i++;
	}
	return (i);
}

void	ft_fix(t_stacks **a, t_stacks **b)
{
	int			i;

	i = ft_op_rot_a(a, ft_find_mistake(a));
	while (i < 0)
	{
		ft_operations(a, b, 7);
		i++;
	}
	while (i > 0)
	{
		ft_operations(a, b, 5);
		i--;
	}
	ft_operations(a, b, 4);
	ft_find_spot(a, b);
}

// this function finds the longest increasing subsequence in the list of ints.
// The length array stores the count of increments, meaning the highest value
// in the length array refers to the longest increasing subsequence. In the 
// array "subsequence" I store the referenced last index of this sequence.
// By backtracing through that array, I can find the positions of each element 
// in that increasing subsequence.
// To simplify things, I overwrite the first element of subsequence with the
// index of the last element of the highest increasing subsequence.
// in the function ft_find_max, I am looking for the max value in the array
// length.

void	ft_sort(struct s_stacks **a, struct s_stacks **b)
{
	int				length[500];
	int				subsequence[500];

	if (ft_check_if_sorted(a) == 2)
		ft_one_off(a, b);
	ft_put_sorted(a);
	ft_put_1s(&subsequence[0], &length[0]);
	ft_lis(a, &subsequence[0], &length[0]);
	ft_lis_to_b(a, b, &length[0], &subsequence[0]);
	ft_sort_back_in_new(a, b);
	while (ft_check_if_sorted(a) != 1)
		ft_fix(a, b);
}
