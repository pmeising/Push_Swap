/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:21:07 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/23 12:36:07 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// key:
// 1 = swap 1st. 2 elements of stack a.
// 2 = swap 1st. 2 elements of stack b.
// 12 = swap 1st. 2 elements of both a and b.
// 3 = push to a.
// 4 = push to b.
// 5 = rotate up on a.
// 6 = rotate up on b.
// 56 = rotate up on both a and b.
// 7 = reverse rotate on a.
// 8 = reverse rotate on b.
// 78 = reverse rotate on both a and b.

void	ft_ops_1(struct s_stacks **a, struct s_stacks **b, int operation)
{
	if (operation == 2)
	{
		ft_swap(b);
		write(1, "sb\n", 3);
	}
	else if (operation == 12)
	{
		ft_swap(a);
		ft_swap(b);
		write(1, "ss\n", 3);
	}
	else if (operation == 3)
	{
		ft_push(b, a);
		write(1, "pa\n", 3);
	}
	else if (operation == 4)
	{
		ft_push(a, b);
		write(1, "pb\n", 3);
	}
}

void	ft_ops_2(struct s_stacks **a, struct s_stacks **b, int operation)
{
	if (operation == 5)
	{
		ft_rotate(a);
		write(1, "ra\n", 3);
	}
	else if (operation == 6)
	{
		ft_rotate(b);
		write(1, "rb\n", 3);
	}
	else if (operation == 56)
	{
		ft_rotate(a);
		ft_rotate(b);
		write(1, "rr\n", 3);
	}
	else if (operation == 7)
	{
		ft_rev_rotate(a);
		write(1, "rra\n", 4);
	}
}

void	ft_operations(struct s_stacks **a, struct s_stacks **b, int operation)
{
	if (operation == 1)
	{
		ft_swap(a);
		write(1, "sa\n", 3);
	}
	if (operation == 2 || operation == 12 || operation == 3
		|| operation == 3 || operation == 4)
		ft_ops_1(a, b, operation);
	if (operation == 5 || operation == 6 || operation == 56 || operation == 7
		|| operation == 8)
		ft_ops_2(a, b, operation);
	if (operation == 8)
	{
		ft_rev_rotate(b);
		write(1, "rrb\n", 4);
	}
	if (operation == 78)
	{
		ft_rev_rotate(a);
		ft_rev_rotate(b);
		write(1, "rrr\n", 4);
	}
}
