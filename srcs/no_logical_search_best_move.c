/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_logical_search_best_move.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:11:39 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/13 16:31:30 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	no_logical_gas_fee_second_verif(t_stacks *stacks, int ra_gas_fee,
		int rb_gas_fee)
{
	if (ra_gas_fee > stacks->size_a / 2 && rb_gas_fee < stacks->size_b / 2)
	{
		reverse_ra_gas_fee(stacks, ra_gas_fee);
		rotate_b_gas_fee(stacks, rb_gas_fee);
	}
	else
	{
		while (ra_gas_fee < stacks->size_a && rb_gas_fee < stacks->size_b
			&& rb_gas_fee != 0 && ra_gas_fee != 0)
		{
			ft_rrr(stacks);
			ra_gas_fee++;
			rb_gas_fee++;
		}
		if (ra_gas_fee != 0)
			reverse_ra_gas_fee(stacks, ra_gas_fee);
		if (rb_gas_fee != 0)
			reverse_rb_gas_fee(stacks, rb_gas_fee);
	}
}

static void	no_logical_gas_fee_verif(t_stacks *stacks, int ra_gas_fee,
		int rb_gas_fee)
{
	if (ra_gas_fee < stacks->size_a / 2 && rb_gas_fee < stacks->size_b / 2)
	{
		while (ra_gas_fee > 0 && rb_gas_fee > 0)
		{
			ft_rr(stacks);
			ra_gas_fee--;
			rb_gas_fee--;
		}
		rotate_a_gas_fee(stacks, ra_gas_fee);
		rotate_b_gas_fee(stacks, rb_gas_fee);
		return ;
	}
	else if (ra_gas_fee < stacks->size_a / 2 && rb_gas_fee > stacks->size_b / 2)
	{
		rotate_a_gas_fee(stacks, ra_gas_fee);
		reverse_rb_gas_fee(stacks, rb_gas_fee);
		return ;
	}
	no_logical_gas_fee_second_verif(stacks, ra_gas_fee, rb_gas_fee);
}

static void	no_logical_second_calcul_gas_fee(t_stacks *stacks, int i, int j)
{
	if (j > stacks->size_a / 2 && i < stacks->size_b / 2)
	{
		if ((j - (stacks->size_a / 2)) + i + 1 < stacks->ra_gas_fee
			+ stacks->rb_gas_fee + 1)
		{
			stacks->ra_gas_fee = j;
			stacks->rb_gas_fee = i;
		}
	}
	else if (j > stacks->size_a / 2 && i > stacks->size_b / 2)
	{
		if ((j - (stacks->size_a / 2)) + (i - (stacks->size_b
					/ 2)) < stacks->ra_gas_fee + stacks->rb_gas_fee)
		{
			stacks->ra_gas_fee = j;
			stacks->rb_gas_fee = i;
		}
	}
}

static void	no_logical_first_calcul_gas_fee(t_stacks *stacks, int i, int j)
{
	if (j < stacks->size_a / 2 && i < stacks->size_b / 2)
	{
		if (j + i + 1 < stacks->ra_gas_fee + stacks->rb_gas_fee + 1)
		{
			stacks->ra_gas_fee = j;
			stacks->rb_gas_fee = i;
		}
	}
	else if (j < stacks->size_a / 2 && i > stacks->size_b / 2)
	{
		if (j + (i - (stacks->size_b / 2)) + 1 < stacks->ra_gas_fee
			+ stacks->rb_gas_fee + 1)
		{
			stacks->ra_gas_fee = j;
			stacks->rb_gas_fee = i;
		}
	}
}

void	no_logical_search_best_move(t_stacks *stacks)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stacks->size_b)
	{
		j = -1;
		while (stacks->a[++j] < stacks->b[i])
			if (j == stacks->size_a)
				break ;
		if (i == 0)
		{
			stacks->ra_gas_fee = j;
			stacks->rb_gas_fee = i;
		}
		else
		{
			no_logical_first_calcul_gas_fee(stacks, i, j);
			no_logical_second_calcul_gas_fee(stacks, i, j);
			if (stacks->ra_gas_fee + stacks->rb_gas_fee < 4)
				break ;
		}
	}
	no_logical_gas_fee_verif(stacks, stacks->ra_gas_fee, stacks->rb_gas_fee);
}
