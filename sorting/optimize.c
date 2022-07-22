/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:13:00 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/22 20:23:38 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_op_rot_a_old(struct s_stacks **a, struct s_stacks **b, int pos)
{
	struct s_stacks	*iterator;
	int	size;

	iterator = *a;
	size = ft_lstsize(*a);
	if (pos == 0)
		return ;
	while (pos != 0)
	{
		iterator = iterator->next;
		pos--;
	}
	while (iterator != *a)
	{
		if (pos < size/2)
			ft_operations(a, b, 5); // rotate a
		else if (pos >= size/2)
			ft_operations(a, b, 7); // rev rotate a	
	}
}

void	ft_op_rot_b_old(struct s_stacks **a, struct s_stacks **b, int pos)
{
	struct s_stacks	*iterator;
	int	size;


	iterator = *b;
	size = ft_lstsize(*b);
	if (pos == 0)
		return ;
	while (pos != 0)
	{
		iterator = iterator->next;
		pos--;
	}
	while (iterator != *b)
	{
		if (pos < size/2)
			ft_operations(a, b, 6); // rotate b
		else if (pos >= size/2)
			ft_operations(a, b, 8); // rev rotate b
	}
}

int	ft_is_in_stack(struct s_stacks **a, int i)
{
	struct s_stacks	*head;
	int	j;
	int	size;

	head = *a;
	size = ft_lstsize(head);
	j = 0;
	while (j < size)
	{
		if (head->sorted == i)
			return (j);
		j++;
		head = head->next;
	}
	return (-1);
}

int	ft_abs(int i)
{
	if (i < 0)
		i = i * (-1);
	return (i);
}

void	ft_one_off(struct s_stacks **a, struct s_stacks **b)
{
	ft_operations(a, b, 7); // rev rotate a
	ft_operations(a, b, 7); // rev rotate a
	ft_operations(a, b, 1); // swap a
	ft_operations(a, b, 5); // rotate a
	ft_operations(a, b, 5); // rotate a
	ft_operations(a, b, 30);
	ft_del_lst(a);
	ft_del_lst(b);
	exit (0);
}

