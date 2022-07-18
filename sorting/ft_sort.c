/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:11:48 by pmeising          #+#    #+#             */
/*   Updated: 2022/07/18 15:21:07 by pmeising         ###   ########.fr       */
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

void	ft_sort(struct s_stacks **a, struct s_stacks **b, int *commands)
{
	struct s_stacks	*head_to_a;
	int				index_of_max;
	int				i;
	int				length[500];
	int				subsequence[500];

	i = 0;
	head_to_a = *a;
	ft_put_sorted(a);
	ft_put_1s(&subsequence[0], &length[0]);
	ft_lis(a, &subsequence[0], &length[0]);
	ft_lis_to_b(a, b, &length[0], &subsequence[0]);
	ft_sort_back_in(a, b);
	// ft_print_stack(b);
	// printf("^^^ Stack B ^^^\n");
	ft_operations(a, b, 30);
	ft_print_stack(a);
	printf("^^^ Stack A ^^^\n");
}
