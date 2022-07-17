/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:01:09 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/12 12:57:12 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_stacks	*ft_lstnew(int content)
{
	struct s_stacks	*newnode;

	newnode = malloc(sizeof(struct s_stacks));
	if (!newnode)
		return (NULL);
	newnode->integer = content;
	newnode->next = NULL;
	newnode->previous = NULL;
	newnode->index = 0;
	newnode->sorted = 0;
	return (newnode);
}
