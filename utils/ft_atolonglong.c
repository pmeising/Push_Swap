/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolonglong.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:33:50 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/19 19:28:45 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static int	ft_is_negative(char *nptr, int i)
{
	if (nptr[i] == '-')
		return (-1);
	else if (nptr[i] == '+')
		return (1);
	return (0);
}

int	ft_atolonglong(const char *nptr)
{
	int			i;
	int			is_negative;
	long long	nbr;
	int			number;

	nbr = 0;
	is_negative = 0;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
			i++;
	is_negative = ft_is_negative((char *)nptr, i);
	if (is_negative != 0)
		i++;
	if (!(nptr[i] > 47 && nptr[i] < 58))
		return (0);
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		nbr = nbr * 10 + nptr[i] - 48;
		i++;
	}
	if (is_negative != 0)
		return (nbr * is_negative);
	if (nbr > 2147483647 || nbr < -2147483648)
		ft_error(4, 0);
	number = (int)nbr;
	return (number);
}
