/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:13:00 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/25 15:18:32 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_spot_exists(struct s_stacks **a, int sorted)
{
	struct s_stacks	*head;
	int				i;

	head = *a;
	i = 0;
	while (head->next != NULL)
	{
		if (sorted > head->sorted && sorted < head->next->sorted)
			return (i + 1);
		i++;
		head = head->next;
	}
	return (-1);
}

int	ft_is_in_stack(struct s_stacks **a, int i)
{
	struct s_stacks	*head;
	int				j;
	int				size;

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
	ft_operations(a, b, 7);
	ft_operations(a, b, 7);
	ft_operations(a, b, 1);
	ft_operations(a, b, 5);
	ft_operations(a, b, 5);
	ft_del_lst(a);
	ft_del_lst(b);
	exit (0);
}
