/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_LIS_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:43:32 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/15 21:11:28 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_find_max(int	*length)
{
	int	i;
	int	index_of_max;

	index_of_max = 0;
	i = 498;
	while (i > 0)
	{
		if (length[i] > length[i + 1] && length[i] > index_of_max)
			index_of_max = i;
		i--;
	}
	i = 0;
	printf("Longest sequence is %d\nThis is stored at position: %i\n", length[index_of_max], index_of_max);
	return (index_of_max);
}

int	ft_is_in(int *list, int i, int max)
{
	int	j;

	j = 0;
	while (j < max)
	{
		if (list[j] == i)
		{
			printf("Found a match.\n");
			return (1);
		}
		j++;
	}
	return (0);
}

void	ft_lis_to_b(struct s_stacks **a, struct s_stacks **b, int *length, 
int *subsequence)
{
	struct s_stacks	*iterator;
	int				index_of_max;
	int				k;
	int				i;
	int				list[500];

	iterator = *a;
	k = 0;
	index_of_max = ft_find_max(&length[0]);
	i = index_of_max;
	while (k < length[i])
	{
		list[k] = index_of_max;
		index_of_max = subsequence[index_of_max];
		k++;
	}
	k = 0;
	index_of_max = i;
	i = 1;
	while (k < index_of_max)
	{
		if (ft_lstsize(*a) == length[index_of_max])
			break;
		iterator = *a;
		if (ft_is_in(&list[0], iterator->index, length[index_of_max]) == 0)
		{
			ft_operations(a, b, 4); // push to b.
			i++;
		}
		else if ((ft_is_in(&list[0], iterator->index, index_of_max) == 1) && k < index_of_max)
		{
			ft_operations(a, b, 5); // rotate.
			k++;
		}
	}
}
