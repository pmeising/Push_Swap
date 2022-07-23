/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longest_increasing_subsequence.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:38:40 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/23 12:45:36 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// Maximum arguments is set to 500 in this function!! 

void	ft_put_1s(int *array, int *length)
{
	int	i;

	i = 0;
	while (i < 500)
	{
		array[i] = 0;
		length[i] = 1;
		i++;
	}
}

void	ft_lis(struct s_stacks **lst, int *subsequence, int *length)
{
	struct s_stacks	*iterator;
	struct s_stacks	*walker;

	iterator = *lst;
	iterator = iterator->next;
	while (iterator != NULL)
	{
		walker = *lst;
		while (walker->index < iterator->index)
		{
			if (walker->integer < iterator->integer)
			{
				length[iterator->index] = length[walker->index] + 1;
				subsequence[iterator->index] = walker->index;
			}
			walker = walker->next;
		}
		iterator = iterator->next;
	}
}
