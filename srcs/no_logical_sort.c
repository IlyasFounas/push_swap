/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_logical_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:23:22 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/20 19:00:17 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	replace_stack_a(t_stacks *stacks)
{
	if (is_stack_a_sorted(stacks) == 1 && stacks->size_a == stacks->nb_values)
		return ;
	while (stacks->a[stacks->size_a - 1] < stacks->a[0]
		&& stacks->a[stacks->size_a - 1] > stacks->b[0])
		ft_rra(stacks, 1);
	if (stacks->a[stacks->size_a - 1] > stacks->a[0] && stacks->a[stacks->size_a
			- 1] < stacks->a[1])
	{
		ft_rra(stacks, 1);
		ft_sa(stacks, 1);
	}
}

static void	no_logical_a_bigger_than_b(t_stacks *stacks)
{
	while (stacks->size_a != stacks->nb_values && stacks->a[0] > stacks->b[0])
	{
		ft_pa(stacks);
		if (stacks->size_b == 1)
			no_logical_rotate(stacks, 1);
		else if (stacks->size_b == 0)
			no_logical_sort_full_a(stacks);
		if (stacks->size_b > 3)
			no_logical_search_best_move(stacks);
		else
			no_logical_rotate(stacks, 0);
		while (stacks->a[0] < stacks->b[0] && stacks->a[1] > stacks->b[0])
		{
			ft_pa(stacks);
			ft_sa(stacks, 1);
			if (stacks->size_b == 1)
				no_logical_rotate(stacks, 1);
			else if (stacks->size_b == 0)
				no_logical_sort_full_a(stacks);
		}
		replace_stack_a(stacks);
	}
}

static void	replace_b(t_stacks *stacks)
{
	while (stacks->a[0] < stacks->b[0] && stacks->a[1] > stacks->b[0])
	{
		ft_pa(stacks);
		ft_sa(stacks, 1);
		if (stacks->size_b == 1)
			no_logical_rotate(stacks, 1);
		else if (stacks->size_b == 0)
			no_logical_sort_full_a(stacks);
	}
}

void	no_logical_sort(t_stacks *stacks)
{
	while (stacks->size_a != stacks->nb_values)
	{
		no_logical_a_bigger_than_b(stacks);
		replace_b(stacks);
		no_logical_sort_full_a(stacks);
		if (stacks->size_a != stacks->nb_values && stacks->a[0] < stacks->b[0]
			&& stacks->a[stacks->size_a - 1] < stacks->b[0])
		{
			if (stacks->a[stacks->size_a - 1] < stacks->b[0])
			{
				ft_pa(stacks);
				ft_ra(stacks, 1);
			}
		}
		if (stacks->size_a != stacks->nb_values && stacks->a[stacks->size_a
				- 1] > stacks->b[0])
		{
			if (stacks->size_b > 3)
				no_logical_search_best_move(stacks);
			else
				no_logical_rotate(stacks, 0);
		}
	}
}
