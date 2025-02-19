/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_with_gas_fee.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:39:53 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/06 20:00:15 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_gas_fee(t_stacks *stacks, int ra_gas_fee)
{
	while (ra_gas_fee > 0)
	{
		ft_ra(stacks, 1);
		ra_gas_fee--;
	}
}

void	rotate_b_gas_fee(t_stacks *stacks, int rb_gas_fee)
{
	while (rb_gas_fee > 0)
	{
		ft_rb(stacks, 1);
		rb_gas_fee--;
	}
}

void	reverse_ra_gas_fee(t_stacks *stacks, int rra_gas_fee)
{
	while (rra_gas_fee < stacks->size_a)
	{
		ft_rra(stacks, 1);
		rra_gas_fee++;
	}
}

void	reverse_rb_gas_fee(t_stacks *stacks, int rrb_gas_fee)
{
	while (rrb_gas_fee < stacks->size_b)
	{
		ft_rrb(stacks, 1);
		rrb_gas_fee++;
	}
}
