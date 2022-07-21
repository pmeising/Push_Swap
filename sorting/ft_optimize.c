/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:13:00 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/21 18:49:35 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// These functions get as an input the stacks a and b, as well as the position
// of the node we want to have at the top of the stack.
// What we want to do, is to find the number of operations it would require
// to get this node to its destined position on stack a.
// The combination of both stacks optimal operation is the key here.

// For a regular rotation, the return value is +1, for a reverse 
// rotation, I'll return -1. This way, I can compare required rotations
// on both a and b and potentially opt for the rrr option, minimizing
// operations.

int	ft_op_rot_a(struct s_stacks **a, int pos)
{
	int	size;

	size = ft_lstsize(*a);
	if (pos == 0)
		return (pos);
	if (pos < (size/2))
		return (pos); // rotate a "pos" times.
	else if (pos == (size/2))
		return (pos);
	else if (pos >= (size/2))
		return (-1 * (size - pos)); // rev rotate a size - pos times.
	else
		return (0);
}

int	ft_op_rot_b(struct s_stacks **b, int pos)
{
	int	size;

	size = ft_lstsize(*b);
	if (pos == 0)
		return (pos);
	if (pos < (size/2))
		return (pos); // rotate b "pos" times getting it to the top.
	else if (pos == (size/2))
		return (pos);
	else if (pos >= (size/2))
		return (-1 * (size - pos)); // rev rotate b size - pos times.
	else
		return (0);
}
