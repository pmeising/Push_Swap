/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:38:55 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/08 10:47:45 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_lstdelone_a(t_stacks *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	else if (!del)
		return ;
	del(lst);
	free(lst);
}
