/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:01:09 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/19 21:56:41 by pmeising         ###   ########.fr       */
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
	newnode->op_steps = 0;
	newnode->index = 0;
	newnode->sorted = 0;
	return (newnode);
}
