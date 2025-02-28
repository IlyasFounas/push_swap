/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_logical_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:05:10 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/28 18:48:43 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	no_logical_sort_of_3(t_stacks *stacks)
{
	if (stacks->nb_values == 2)
	{
		if (stacks->a[0] > stacks->a[1])
			ft_sa(stacks, 1);
	}
	else
	{
		if (stacks->a[2] < stacks->a[1] && stacks->a[2] < stacks->a[0] && stacks->a[0] > stacks->a[1])
		{
			ft_ra(stacks, 1);
			ft_sa(stacks, 1);
		}
		if (stacks->a[2] < stacks->a[1] && stacks->a[2] < stacks->a[0])
			ft_rra(stacks, 1);
		if (stacks->a[0] > stacks->a[2] && stacks->a[0] > stacks->a[1])
			ft_ra(stacks, 1);
		if (stacks->a[0] > stacks->a[1])
			ft_sa(stacks, 1);
		if (stacks->a[1] > stacks->a[2])
		{
			ft_ra(stacks, 1);
			ft_sa(stacks, 1);
			ft_rra(stacks, 1);
		}
	}
}

void	no_logical_sort_full_a(t_stacks *stacks)
{
	int	rra;

	rra = 0;
	if (is_stack_a_sorted(stacks) == 1 && stacks->size_a == stacks->nb_values)
		return ;
	if (stacks->a[0] > stacks->a[stacks->size_a - 1])
	{
		while (stacks->a[rra] > stacks->a[stacks->size_a - 1])
			rra++;
		if (rra > stacks->size_a / 2)
			while (stacks->a[0] > stacks->a[stacks->size_a - 1])
				ft_rra(stacks, 1);
		else
			while (stacks->a[0] > stacks->a[stacks->size_a - 1])
				ft_ra(stacks, 1);
	}
}

void	no_logical_rotate_second(t_stacks *stacks, int lastone, int ra)
{
	if (lastone == 1)
	{
		ft_ra(stacks, 1);
		while (stacks->a[0] > stacks->b[0])
		{
			if (++ra == stacks->size_a + 1)
				break ;
			ft_ra(stacks, 1);
		}
	}
	else
	{
		ft_rra(stacks, 1);
		while (stacks->a[0] > stacks->b[0])
		{
			if (++ra == stacks->size_a + 1)
				break ;
			ft_rra(stacks, 1);
		}
	}
}

void	no_logical_rotate(t_stacks *stacks, int lastone)
{
	int	ra;

	ra = 0;
	if (is_stack_a_sorted(stacks) == 1 && stacks->size_a == stacks->nb_values)
		return ;
	while (stacks->a[ra] < stacks->b[0])
	{
		ra++;
		if (ra > stacks->size_a)
			return ;
	}
	if (ra <= (stacks->size_a - 1) / 2)
	{
		while (stacks->a[0] < stacks->b[0])
		{
			if (++ra == stacks->size_a + 1)
				break ;
			ft_ra(stacks, 1);
		}
	}
	else
		no_logical_rotate_second(stacks, lastone, ra);
}

void	no_logical_algo(t_stacks *stacks)
{
	if (stacks->nb_values <= 3)
		no_logical_sort_of_3(stacks);
	else if (stacks->nb_values > 3 && stacks->nb_values < 20)
	{
		no_logical_sort_of_4(stacks);
		if (is_stack_a_sorted(stacks) != 0)
			return ;
		no_logical_sort(stacks);
	}
	else if (stacks->nb_values > 20)
	{
		no_logical_first_mediane(stacks, stacks->nb_values / 4, 0);
		no_logical_second_mediane(stacks);
		no_logical_sort_of_3(stacks);
		no_logical_sort(stacks);
	}
}
