/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_logical_rotate_n_push.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:07:37 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/06 19:09:42 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	no_logical_first_mediane(t_stacks *stacks, int limit, int push)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stacks->nb_values * 2)
	{
		j = -1;
		push = 0;
		if (i >= stacks->nb_values)
		{
			limit = stacks->nb_values / 2;
			j = stacks->nb_values / 4;
		}
		while (++j <= limit)
		{
			if (stacks->a[0] == stacks->a_index[j])
			{
				ft_pb(stacks);
				push++;
				break ;
			}
		}
		if (push == 0)
			ft_ra(stacks, 1);
	}
}

void	no_logical_push_mediane(t_stacks *stacks)
{
	int	x;
	int	y;
	int	y2;

	x = -1;
	while (++x < stacks->size_a / 2)
	{
		y = -1;
		y2 = -1;
		while (++y <= (stacks->nb_values / 2 + stacks->nb_values / 4))
			if (stacks->a[x] == stacks->a_index[y])
				break ;
		while (++y2 <= (stacks->nb_values / 2 + stacks->nb_values / 4))
			if (stacks->a[(stacks->size_a - 1) - x] == stacks->a_index[y2])
				break ;
		x++;
		if (y <= y2)
			while (--x >= 0)
				ft_ra(stacks, 1);
		else
			while (--x >= 0)
				ft_rra(stacks, 1);
		break ;
	}
}

void	no_logical_second_mediane(t_stacks *stacks)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stacks->nb_values)
	{
		j = stacks->nb_values / 2;
		while (++j <= (stacks->nb_values / 2 + stacks->nb_values / 4))
		{
			if (stacks->a[0] == stacks->a_index[j])
			{
				ft_pb(stacks);
				break ;
			}
		}
		no_logical_push_mediane(stacks);
		if (stacks->size_b + stacks->nb_values / 4 == stacks->nb_values)
			break ;
	}
	while (stacks->size_a != 3)
	{
		ft_pb(stacks);
		ft_rb(stacks, 1);
	}
}
