/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:06:50 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/13 16:26:21 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_alloc_my_stacks(t_stacks *stacks)
{
	stacks->a = ft_calloc(stacks->nb_values + 1, 4);
	if (!stacks->a)
		return (0);
	stacks->b = ft_calloc(stacks->nb_values + 1, 4);
	if (!stacks->b)
	{
		free(stacks->a);
		return (0);
	}
	stacks->a_index = ft_calloc(stacks->nb_values + 1, 4);
	if (!stacks->a_index)
	{
		free(stacks->a);
		free(stacks->b);
		return (0);
	}
	return (1);
}

static int	find_little_number(t_stacks *stacks)
{
	int	i;
	int	res;

	i = 0;
	res = stacks->a[0];
	while (++i < stacks->size_a)
		if (res > stacks->a[i])
			res = stacks->a[i];
	return (res);
}

static void	no_logical_4_sort(t_stacks *stacks)
{
	while (is_stack_a_sorted(stacks) == 0)
	{
		if (stacks->a[0] > stacks->a[1])
			if (stacks->a[0] > stacks->a[2])
				ft_ra(stacks, 1);
		if (stacks->a[0] > stacks->a[1])
			if (stacks->a[0] < stacks->a[2])
				ft_sa(stacks, 1);
		if (stacks->a[0] < stacks->a[1])
		{
			if (stacks->a[1] > stacks->a[2])
			{
				ft_sa(stacks, 1);
				ft_ra(stacks, 1);
			}
		}
	}
}

void	no_logical_sort_of_4(t_stacks *stacks)
{
	int	j;

	while (stacks->size_a != 3 && is_stack_a_sorted(stacks) == 0)
	{
		j = 0;
		while (stacks->a[j] != find_little_number(stacks))
			j++;
		if (j <= (stacks->size_a - 1) / 2)
			while (--j >= 0)
				ft_ra(stacks, 1);
		else
			while (++j <= stacks->size_a)
				ft_rra(stacks, 1);
		ft_pb(stacks);
	}
	no_logical_4_sort(stacks);
	while (stacks->size_b != 0)
		ft_pa(stacks);
	return ;
}
