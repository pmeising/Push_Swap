/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:40:33 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/27 10:42:00 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

char	*ft_calloc(size_t number, size_t size)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc(number * size);
	if (dest == NULL)
		return (dest);
	while (i < (number * size))
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
