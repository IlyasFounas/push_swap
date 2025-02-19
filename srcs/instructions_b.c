/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:51:07 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/12 14:26:43 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stacks *stacks)
{
	int	i;

	if (stacks->size_b == 0)
		return ;
	i = stacks->nb_values;
	ft_printf("pa\n");
	while (--i >= 0)
	{
		stacks->a[i + 1] = stacks->a[i];
	}
	stacks->a[0] = stacks->b[0];
	stacks->size_a++;
	stacks->size_b--;
	i = 0;
	while (++i < stacks->nb_values)
	{
		stacks->b[i - 1] = stacks->b[i];
	}
	stacks->b[i - 1] = 0;
}

void	ft_sb(t_stacks *stacks, int print)
{
	int	tmp;

	if (print == 1)
		ft_printf("sb\n");
	tmp = stacks->b[0];
	stacks->b[0] = stacks->b[1];
	stacks->b[1] = tmp;
}

void	ft_rb(t_stacks *stacks, int print)
{
	int	i;
	int	tmp;

	i = -1;
	if (print == 1)
		ft_printf("rb\n");
	tmp = stacks->b[0];
	while (++i < stacks->size_b - 1)
		stacks->b[i] = stacks->b[i + 1];
	stacks->b[stacks->size_b - 1] = tmp;
}

void	ft_rrb(t_stacks *stacks, int print)
{
	int	i;
	int	tmp;

	i = stacks->size_b;
	if (print == 1)
		ft_printf("rrb\n");
	tmp = stacks->b[stacks->size_b - 1];
	while (--i > 0)
		stacks->b[i] = stacks->b[i - 1];
	stacks->b[0] = tmp;
}

int	is_stack_b_sorted(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->size_b - 1)
	{
		if (stacks->b[i] > stacks->b[i + 1])
			return (0);
		i++;
	}
	return (1);
}
