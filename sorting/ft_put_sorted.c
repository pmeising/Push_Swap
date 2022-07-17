/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:39:34 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/17 19:03:43 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// checks, if the list is already sorted. If so, returns 1, if not sorted,
// it returns 0.

int	ft_check_if_sorted(struct s_stacks **c)
{
	struct s_stacks	*iterator;
	int				i;
	int				j;
	int				size;

	size = ft_lstsize(*c);
	i = 0;
	j = 0;
	iterator = *c;
	while (i < size && iterator->next != NULL)
	{
		if (iterator->next->integer > iterator->integer)
			j++;
		iterator = iterator->next;
		i++;
	}
	if (j == size - 1)
		return (1);
	return (0);
}

// rotates, until lowest int is on the top of the list and puts sorted indexes. 
// Then writes the sorted indexes into the nodes.

void	ft_put_indexes(struct s_stacks **c)
{
	struct s_stacks	*iterator;
	int				i;

	i = 0;
	iterator = *c;
	while (iterator->integer < iterator->next->integer) // put lowest int at the top.
	{
		ft_rotate(c);
		iterator = *c;
	}
	ft_rotate(c);
	iterator = *c;
	while (iterator != NULL)
	{
		iterator->sorted = i;
		i++;
		iterator = iterator->next;
	}
}

// makes a copy list "c" of a, on which the sorting can take place, without
// changing the order on "a".

void	ft_copy_lst(struct s_stacks **a, struct s_stacks **c)
{
	struct s_stacks	*head_a;
	struct s_stacks	*head_c;
	int				i;

	i = 0;
	head_a = *a;
	head_c = *c;
	while (head_a != NULL)
	{
		ft_lstadd_back(c, ft_lstnew(head_a->integer));
		head_c = *c;
		head_c = head_c->next;
		head_a = head_a->next;
	}
	head_c = *c;
	while (head_c != NULL)
	{
		head_c->index = i;
		head_c = head_c->next;
		i++;
	}
}

// walking through c and transferring the sorted indexes to stack a's nodes.

void	ft_transfere_indexes(struct s_stacks **a, struct s_stacks **c)
{
	struct s_stacks	*head_a;
	struct s_stacks	*head_c;

	head_a = *a;
	head_c = *c;
	while (head_c != NULL)
	{
		head_a = *a;
		while (head_a != NULL)
		{
			if (head_a->integer == head_c->integer)
				head_a->sorted = head_c->sorted;
			head_a = head_a->next;
		}
		head_c = head_c->next;
	}
}

void	ft_put_sorted(struct s_stacks **a)
{
	struct s_stacks	*iterator;
	struct s_stacks	*temp;
	struct s_stacks	*head_a;
	struct s_stacks	*head_c;

	ft_copy_lst(a, &head_c);
	ft_print_stack(&head_c);
	head_a = *a;
	iterator = head_c;
	if (ft_check_if_sorted(&head_c) == 1)
		ft_error(9, 0, NULL);
	while (ft_check_if_sorted(&head_c) == 0)
	{
		if (iterator->next == NULL)
			iterator = head_c;
		if (iterator->integer > iterator->next->integer)
			ft_switch(&iterator, &head_c);
		if (iterator->next == NULL)
			iterator = head_c;
		iterator = iterator->next;
	}
	ft_put_indexes(&head_c);
	ft_transfere_indexes(a, &head_c);
}