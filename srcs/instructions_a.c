/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:51:09 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/12 18:04:20 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_stacks *stacks)
{
	int	i;

	if (stacks->size_a == 0)
		return ;
	ft_printf("pb\n");
	i = stacks->nb_values;
	while (--i >= 0)
	{
		stacks->b[i + 1] = stacks->b[i];
	}
	stacks->b[0] = stacks->a[0];
	stacks->size_b++;
	stacks->size_a--;
	i = 0;
	while (++i < stacks->nb_values)
	{
		stacks->a[i - 1] = stacks->a[i];
	}
	stacks->a[i - 1] = 0;
}

void	ft_sa(t_stacks *stacks, int print)
{
	int	tmp;

	if (print == 1)
		ft_printf("sa\n");
	tmp = stacks->a[0];
	stacks->a[0] = stacks->a[1];
	stacks->a[1] = tmp;
}

void	ft_ra(t_stacks *stacks, int print)
{
	int	i;
	int	tmp;

	i = -1;
	if (print == 1)
		ft_printf("ra\n");
	tmp = stacks->a[0];
	while (++i < stacks->size_a - 1)
		stacks->a[i] = stacks->a[i + 1];
	stacks->a[stacks->size_a - 1] = tmp;
}

void	ft_rra(t_stacks *stacks, int print)
{
	int	i;
	int	tmp;

	i = stacks->size_a;
	if (print == 1)
		ft_printf("rra\n");
	tmp = stacks->a[stacks->size_a - 1];
	while (--i > 0)
		stacks->a[i] = stacks->a[i - 1];
	stacks->a[0] = tmp;
}

int	is_stack_a_sorted(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->size_a - 1)
	{
		if (stacks->a[i] > stacks->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
