/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:00:04 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/28 11:32:20 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_trlt_op(struct s_stacks **a, struct s_stacks **b, char *instr)
{
	if (instr[0] == 's' && instr[1] == 'a')
		ft_b_operations(a, b, 1);
	else if (instr[0] == 's' && instr[1] == 'b')
		ft_b_operations(a, b, 2);
	else if (instr[0] == 's' && instr[1] == 's')
		ft_b_operations(a, b, 12);
	else if (instr[0] == 'p' && instr[1] == 'a')
		ft_b_operations(a, b, 3);
	else if (instr[0] == 'p' && instr[1] == 'b')
		ft_b_operations(a, b, 4);
	else if (instr[0] == 'r' && instr[1] == 'a')
		ft_b_operations(a, b, 5);
	else if (instr[0] == 'r' && instr[1] == 'b')
		ft_b_operations(a, b, 6);
	else if (instr[0] == 'r' && instr[1] == 'r' && instr[2] == '\n')
		ft_b_operations(a, b, 56);
	else if (instr[0] == 'r' && instr[1] == 'r' && instr[2] == 'a')
		ft_b_operations(a, b, 7);
	else if (instr[0] == 'r' && instr[1] == 'r' && instr[2] == 'b')
		ft_b_operations(a, b, 8);
	else if (instr[0] == 'r' && instr[1] == 'r' && instr[2] == 'r')
		ft_b_operations(a, b, 78);
}

// Here I read the output from the prior program in the terminal and execute on
// the stack.

// Read up on read function, while X read from terminal and error check it.

// Perhaps I can simply use my GNL function to read line by line from 
// the terminal. :) Look into it pls. :) 

void	ft_read_from_terminal(struct s_stacks **a, struct s_stacks **b)
{
	char		*instr;
	t_stacks	*ptr;
	int			size;

	size = ft_lstsize(*a);
	ptr = *b;
	instr = "0000";
	while (instr != NULL)
	{
		instr = get_next_line(0);
		if (instr == NULL)
			break ;
		ft_trlt_op(a, b, instr);
		free (instr);
	}
	free (instr);
	if (ft_check_if_sorted(a) == 1 && ptr == NULL && size == ft_lstsize(*a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
