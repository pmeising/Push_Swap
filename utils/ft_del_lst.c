/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:32:54 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/23 12:37:51 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_del_lst(struct s_stacks **lst)
{
	struct s_stacks	*iterator;
	struct s_stacks	*temp;

	iterator = *lst;
	temp = *lst;
	while (iterator != NULL)
	{
		temp = iterator;
		iterator = iterator->next;
		free (temp);
	}
	free (iterator);
}
