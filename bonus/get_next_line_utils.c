/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:36:20 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/27 11:04:55 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_len(char *remainder)
{
	int	i;

	i = 0;
	if (ft_strchr(remainder, '\n') != NULL)
	{
		while (remainder[i] != '\n')
			i++;
		return (i + 1);
	}
	else
	{
		while (remainder[i] != '\0')
			i++;
		return (i + 1);
	}
	return (0);
}
