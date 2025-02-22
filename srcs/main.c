/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:20:20 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/22 15:08:14 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stacks(t_stacks *stacks)
{
	if (stacks->a)
		free(stacks->a);
	if (stacks->b)
		free(stacks->b);
	if (stacks->a_index)
		free(stacks->a_index);
}

static int	count_nb_of_neg(t_stacks *stacks, long int nb)
{
	static int	nb_of_neg;

	if (nb == LONG_MIN + 1)
	{
		free_stacks(stacks);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (!nb_of_neg)
		nb_of_neg = 0;
	if (nb < 0)
		nb_of_neg++;
	return (nb_of_neg);
}

static int	is_there_any_duplicate(t_stacks *stacks)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stacks->size_a)
	{
		j = i;
		while (++j < stacks->size_a)
		{
			if (stacks->a[i] == stacks->a[j])
				return (0);
		}
	}
	return (1);
}

static void	sort_a_index(t_stacks *stacks)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	j = -1;
	tmp = -1;
	while (++j < stacks->nb_values)
		stacks->a_index[j] = stacks->a[j];
	while (++i < stacks->nb_values)
	{
		if (i + 1 < stacks->nb_values && stacks->a_index[i] > stacks->a_index[i
				+ 1])
		{
			tmp = stacks->a_index[i];
			stacks->a_index[i] = stacks->a_index[i + 1];
			stacks->a_index[i + 1] = tmp;
			i = -1;
		}
	}
}

int	main(int arc, char **arv)
{
	int			i;
	t_stacks	stacks;

	i = 0;
	stacks.nb_values = arc - 1;
	stacks.size_a = arc - 1;
	stacks.size_b = 0;
	if (arc < 2)
		return (1);
	if (ft_alloc_my_stacks(&stacks) == 0)
		return (1);
	while (++i < arc)
	{
		stacks.nb_neg = count_nb_of_neg(&stacks, ft_atoi_error(arv[i]));
		stacks.a[i - 1] = (int)ft_atoi_error(arv[i]);
	}
	if (is_there_any_duplicate(&stacks) == 0)
		return (ft_putstr_fd("Error\n", 2), free_stacks(&stacks), 1);
	if (is_stack_a_sorted(&stacks) == 1)
		return (free_stacks(&stacks), 0);
	sort_a_index(&stacks);
	no_logical_algo(&stacks);
	free_stacks(&stacks);
	return (0);
}
