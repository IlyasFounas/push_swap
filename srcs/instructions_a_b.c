/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:41:21 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/13 16:46:38 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_stacks *stacks)
{
	ft_printf("ss\n");
	ft_sa(stacks, 0);
	ft_sb(stacks, 0);
}

void	ft_rr(t_stacks *stacks)
{
	ft_printf("rr\n");
	ft_ra(stacks, 0);
	ft_rb(stacks, 0);
}

void	ft_rrr(t_stacks *stacks)
{
	ft_printf("rrr\n");
	ft_rra(stacks, 0);
	ft_rrb(stacks, 0);
}
