/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:21:07 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/22 18:42:05 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_operations(struct s_stacks **a, struct s_stacks **b, int operation)
{
	static int	i;

	if (operation == 1)
		ft_swap(a); // swap 1st. 2 elements of stack a.
	else if (operation == 2)
		ft_swap(b); // swap 1st. 2 elements of stack b.
	else if (operation == 12)
	{
		ft_swap(a); // swap 1st. 2 elements of both a and b.
		ft_swap(b);
	}
	else if (operation == 3)
		ft_push(b, a); // push to a.
	else if (operation == 4)
		ft_push(a, b); // push to b.
	else if (operation == 5)
		ft_rotate(a); // rotate up on a.
	else if (operation == 6)
		ft_rotate(b); // rotate up on b.
	else if (operation == 56)
	{
		ft_rotate(a); // rotate up on both a and b.
		ft_rotate(b);
		// printf("Repeatedly rotating\n");
	}
	else if (operation == 7)
		ft_rev_rotate(a); // reverse rotate on a.
	else if (operation == 8)
		ft_rev_rotate(b); // reverse rotate on b.
	else if (operation == 78)
	{
		ft_rev_rotate(a); // reverse rotate on both a and b.
		ft_rev_rotate(b);
		// printf("Repeatedly reverse rotating\n");
	}
	else if (operation == 30)
		printf("It took me %d operations to sort the stack.\n", i);
	// printf("After operation: \n");
	// ft_print_stack(a);
	// printf("^ Stack A ^ \n");
	// ft_print_stack(b);
	// printf("^ Stack B ^ \n");
	i++;
}
