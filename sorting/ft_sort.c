/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:11:48 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/22 20:24:14 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// this function finds the longest increasing subsequence in the list of ints.
// The length array stores the count of increments, meaning the highest value
// in the length array refers to the longest increasing subsequence. In the 
// array "subsequence" I store the referenced last index of this sequence.
// By backtracing through that array, I can find the positions of each element 
// in that increasing subsequence.
// To simplify things, I overwrite the first element of subsequence with the
// index of the last element of the highest increasing subsequence.
// in the function ft_find_max, I am looking for the max value in the array
// length.

void	ft_sort(struct s_stacks **a, struct s_stacks **b)
{
	int				length[500];
	int				subsequence[500];

	if (ft_check_if_sorted(a) == 2)
		ft_one_off(a, b);
	ft_put_sorted(a);
	ft_put_1s(&subsequence[0], &length[0]);
	ft_lis(a, &subsequence[0], &length[0]);
	ft_lis_to_b(a, b, &length[0], &subsequence[0]);
	printf("\n\n Pushing completed A: \n");
	ft_print_stack(a);
	printf("B: \n");
	ft_print_stack(b);
	printf("\n\n\n");
	ft_sort_back_in_new(a, b);
	ft_operations(a, b, 30);
	ft_print_stack(a);
	printf("^^^ Stack A ^^^\n");
	ft_print_stack(b);
	printf("^^^ Stack B ^^^\n");
	if (ft_check_if_sorted(a) == 1)
		printf("Sorting successful! :) \n");
	else
		printf("\n\nSORTING WAS NOT SUCCESSFULL...\n\n");
}
