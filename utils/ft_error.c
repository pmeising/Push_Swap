/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:05:03 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/27 18:39:36 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// static void	ft_earth(int i)
// {
// 	write(2, "Error\n", 6);
// 	write(2, "        _____\n    ,-:` \\;',`'-,\n  .'-;_,;  ':-;_,'.\n", 53);
// 	write(2, " /;   '/    ,  _`.-\\ \n| '`. (`     /` ` \\`| \n", 47);
// 	write(2, "|:.  `\\`-.   \\_   / |\n|     (   `,  .`\\ ;'|\n", 47);
// 	write(2, " \\     | .'     `-'/\n  `.   ;/        .'\njgs `'-._____.", 56);
// 	write(2, "\n\nVoid detected, please add lifeforms...\n\n... ... ...", 53);
// 	write(2, " ... ... ... ... ... ... ... \n\n", 31);
// 	i++;
// }

// static void	ft_alien(int i)
// {
// 	write(2, "Error\n", 6);
// 	write(2, "\n\n", 2);
// 	write(2, "            .- '' -.\n           /        \\ \n          /_", 57);
// 	write(2, "        _\\ \n         // \\      / \\ \n         |\\_@\\  ", 57);
// 	write(2, " /_@/|\n          \\    ||    /\n           \\        /\n", 55);
// 	write(2, "            \\  __  /\n             '.__.'\n", 42);
// 	write(2, "              |  |\n     jgs      |  |\n\n", 39);
// 	i++;
// }

// static void	ft_overpopulation(int i)
// {
// 	write(2, "Error\n", 6);
// 	write(2, "Detected invalid syntax\n", 24);
// 	write(2, "Option 1: './<program name> <String of space separated", 55);
//  	write(2, "integers>'\n", 11);
// 	write(2, "Option 2: './<program name> <int_1> <int_2> ... <int_n>'\n", 57);
// 	i++;
// }

void	ft_error(int ecode, int position)
{
	if (ecode > -20 && position > -20)
		write(1, "Error\n", 6);
	exit (0);
}
	// if (ecode == 0)
	// {
	// 	ft_earth(0);
	// 	exit(0);
	// }
	// else if (ecode == 1)
	// 	ft_overpopulation(0);
	// else if (ecode == 2)
	// {
	// 	ft_alien(0);
	// 	printf("Found unknown life-form at index ");
	// 	printf("%d.\n\n... ... ... ... ... .. ...\n\n", position);
	// }
	// else if (ecode == 3)
	// {
	// 	// argument only has "-" no value inside.
	// 	write(2, "Error\n", 6);
	// 	write(2, " '-' without following numeric input.\n", 38);
	// 	exit(0);
	// }
	// else if (ecode == 4)
	// {
	// 	// argument is exceeding int limit.
	// 	write(2, "Error\n", 6);
	// 	write(2, "Argument exceeds integer limits.\n", 33);
	// 	exit(0);
	// }
	// else if (ecode == 5)
	// {
	// 	write(2, "Error\n", 6);
	// 	write(2, "Found duplicate.\n", 18);
	// 	exit (0);
	// }
	// else if (ecode == 6)
	// {
	// 	write(2, "Error\n", 6);
	// 	write(2, "Not doing anything, swap with < 2 nodes.\n", 41);
	// 	exit (0);
	// }
	// else if (ecode == 7)
	// {
	// 	write(2, "Error\n", 6);
	// 	write(2, "Rotate with less than 2 nodes.\n", 31);
	// 	exit (0);
	// }
	// else if (ecode == 8)
	// {
	// 	write(2, "Error\n", 6);
	// 	write(2, "Tried to push from empty list.\n", 31);
	// 	exit (0);
	// }
	// 	else if (ecode == 9)
	// {
	// 	write(2, "Error\n", 6);
	// 	write(2, "List already sorted!\n", 31);
	// 	exit (0);
	// }
// }

// Here I check the entire string, if it contains any invalid value.
// I loop through it and compare each value to the range of ascii 
// "0" until "9" and "-".
int	ft_check(char *list)
{
	int	i;

	i = 0;
	if ((char)list[i] == 45 || (char)list[i] == 43)
		i++;
	if ((char)list[i] == '\0')
		ft_error(3, 0);
	while (list[i] != '\0')
	{
		if ((char)list[i] < 48 || (char)list[i] > 57)
		{
			ft_error(2, i);
			exit(1);
		}
		i++;
	}
	if (ft_strlen(list) > 11)
		ft_error(4, 0);
	return (0);
}

// called by main to run the error checks.

void	ft_check_errors(int argc, char **argv)
{
	if (argc < 2)
		exit (0);
	if (argc > 2 && (ft_strchr(argv[1], 32) != NULL))
	{
		ft_error(1, 0);
		exit (0);
	}
}
