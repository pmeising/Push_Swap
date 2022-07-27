/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:32:23 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/27 15:26:27 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_helper_0(struct s_stacks *ptr_to_head)
{
	ft_error(5, 0);
	ft_del_lst(&ptr_to_head);
}

void	ft_make_list(struct s_stacks **lst, char **arguments, int i)
{
	while (arguments[i] != NULL)
	{
		ft_check(arguments[i]);
		ft_lstadd_back(lst, ft_lstnew(ft_atolonglong(arguments[i])));
		i++;
	}
}

static void	ft_det_dups(struct s_stacks *ptr_to_head)
{
	t_stacks	*iterator;
	t_stacks	*temp;
	int			i;
	int			k;

	i = 0;
	k = 0;
	iterator = ptr_to_head;
	while (iterator != NULL)
	{
		iterator->index = k;
		i = iterator->integer;
		temp = iterator->next;
		while (temp != NULL)
		{
			if (temp->integer == i)
				ft_helper_0(ptr_to_head);
			temp = temp->next;
		}
		iterator = iterator->next;
		temp = ptr_to_head;
		k++;
	}
}

void	ft_2(struct s_stacks **a, struct s_stacks **b)
{
	struct s_stacks	*ptr_to_head_a;

	ptr_to_head_a = *a;
	ft_det_dups(ptr_to_head_a);
	ft_read_from_terminal(a, b);
	ft_del_lst(a);
}

int	main(int argc, char **argv)
{
	struct s_stacks	*ptr_to_head_a;
	struct s_stacks	*ptr_to_head_b;
	int				i;
	char			**arguments;

	ptr_to_head_a = NULL;
	ptr_to_head_b = NULL;
	i = 0;
	if (argc == 1)
		exit (0);
	ft_check_errors(argc, argv);
	if (argc == 2)
		arguments = ft_split(argv[1], 32);
	else
	{
		arguments = argv;
		i++;
	}
	ft_make_list(&ptr_to_head_a, arguments, i);
	ft_2(&ptr_to_head_a, &ptr_to_head_b);
	return (0);
}
