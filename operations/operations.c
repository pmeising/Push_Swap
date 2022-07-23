/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:21:07 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/23 11:36:35 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_ops_1(struct s_stacks **a, struct s_stacks **b, int operation)
{
	if (operation == 1)
	{
		ft_swap(a); // swap 1st. 2 elements of stack a.
		write(1, "sa\n", 3);
	}
	else if (operation == 2)
	{
		ft_swap(b); // swap 1st. 2 elements of stack b.
		write(1, "sb\n", 3);
	}
	else if (operation == 12)
	{
		ft_swap(a); // swap 1st. 2 elements of both a and b.
		ft_swap(b);
		write(1, "ss\n", 3);
	}
	else if (operation == 3)
	{
		ft_push(b, a); // push to a.
		write(1, "pa\n", 3);
	}
	else if (operation == 4)
	{
		ft_push(a, b); // push to b.
		write(1, "pb\n", 3);
	}
}

void	ft_ops_2(struct s_stacks **a, struct s_stacks **b, int operation)
{
	if (operation == 5)
	{
		ft_rotate(a); // rotate up on a.
		write(1, "ra\n", 3);
	}
	else if (operation == 6)
	{
		ft_rotate(b); // rotate up on b.
		write(1, "rb\n", 3);
	}
	else if (operation == 56)
	{
		ft_rotate(a); // rotate up on both a and b.
		ft_rotate(b);
		write(1, "rr\n", 3);
	}
	else if (operation == 7)
	{
		ft_rev_rotate(a); // reverse rotate on a.
		write(1, "rra\n", 4);
	}
	else if (operation == 8)
	{
		ft_rev_rotate(b); // reverse rotate on b.
		write(1, "rrb\n", 4);
	}
	else if (operation == 78)
	{
		ft_rev_rotate(a); // reverse rotate on both a and b.
		ft_rev_rotate(b);
		write(1, "rrr\n", 4);
	}
}

void	ft_operations(struct s_stacks **a, struct s_stacks **b, int operation)
{
	static int	i;

	if (operation == 1 ||operation == 2 || operation == 12 || operation == 3
	 || operation == 3 || operation == 4)
	 	ft_ops_1(a, b, operation);
	if (operation == 5 ||operation == 6 || operation == 56 || operation == 7
	 || operation == 8 || operation == 78)
	 	ft_ops_2(a, b, operation);
	if (operation == 30)
		printf("It took me %d operations to sort the stack.\n", i);
	i++;
}
