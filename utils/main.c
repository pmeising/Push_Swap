/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:41:32 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/30 22:43:46 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// In the main function I walk through the arguments and check if they are a 
// valid input. I while loop through them and check if each argument is a valid
// int. If the input was a string of space separated ints, I split them and 
// input them as content into the nodes of the linked list a.
// Following, I call the sorting function and then delete the lists from the 
// memory.
// Line 107 checks for invalid input on arguments.
// Line 108 converts to int -> creating new node and adding it to
// the end of list a.

// checks the Linked List for duplicate values using nested while loops.
// also puts indexes into nodes.

void	ft_helper_0(struct s_stacks *ptr_to_head)
{
	ft_del_lst(&ptr_to_head);
	ft_error(5, 0);
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

// The following function is outcommented due to the functionality only
// being used during testing. If neccessary, it can be used again.

// void	ft_print_stack(struct s_stacks **stack)
// {
// 	t_stacks	*iterator;
// 	int			i;

// 	i = 0;
// 	iterator = *stack;
// 	while (iterator != NULL)
// 	{
// 		i++;
// 		// printf("Address of %d. node: %p\n", i, iterator);
// 		printf("Value of %d. node->integer: %d\n", i, iterator->integer);
// 		// printf("Index of node: %d\n", iterator->index);
// 		// printf("Index when sorted: %d\n", iterator->sorted);
// 		// printf("Address of %d. node->previous value: %p\n", i,
// 		// iterator->previous);
// 		// printf("Address of %d. node->next value: %p\n", i, iterator->next);
// 		// printf("i value: %d\n", iterator->i);
// 		// printf("j value: %d\n", iterator->j);
// 		// printf("m value: %d\n", iterator->m);
// 		iterator = iterator->next;
// 	}
// }

void	ft_2(struct s_stacks **a, struct s_stacks **b)
{
	struct s_stacks	*ptr_to_head_a;

	ptr_to_head_a = *a;
	ft_det_dups(ptr_to_head_a);
	if (ft_check_if_sorted(a) == 1)
		exit(0);
	if (ft_lstsize(*a) < 6)
		ft_sort_short(a, b);
	else
		ft_sort(a, b);
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
	ft_check_errors(argc, argv);
	if (argc == 2)
		arguments = ft_split(argv[1], 32);
	else
	{
		arguments = argv;
		i++;
	}
	while (arguments[i] != NULL)
	{
		ft_check(arguments[i]);
		ft_lstadd_back(&ptr_to_head_a, ft_lstnew(ft_atolonglong(arguments[i])));
		i++;
	}
	ft_2(&ptr_to_head_a, &ptr_to_head_b);
	return (0);
}
