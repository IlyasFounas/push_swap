/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:41:51 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/21 13:38:35 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	*a_index;
	int	size_a;
	int	size_b;
	int	nb_values;
	int	ra_gas_fee;
	int	rb_gas_fee;
	int	nb_neg;
}		t_stacks;

// instruction_a_b.c
void	ft_ss(t_stacks *stacks);
void	ft_rr(t_stacks *stacks);
void	ft_rrr(t_stacks *stacks);

// instruction_a.c
void	ft_pb(t_stacks *stacks);
void	ft_sa(t_stacks *stacks, int print);
void	ft_ra(t_stacks *stacks, int print);
void	ft_rra(t_stacks *stacks, int print);
int		is_stack_a_sorted(t_stacks *stacks);

// instruction_b.c
void	ft_pa(t_stacks *stacks);
void	ft_sb(t_stacks *stacks, int print);
void	ft_rb(t_stacks *stacks, int print);
void	ft_rrb(t_stacks *stacks, int print);
int		is_stack_b_sorted(t_stacks *stacks);

// no_logical_algo.c
void	no_logical_algo(t_stacks *stacks);
void	no_logical_sort_full_a(t_stacks *stacks);
void	no_logical_rotate_second(t_stacks *stacks, int lastone, int ra);
void	no_logical_rotate(t_stacks *stacks, int lastone);
void	no_logical_sort_of_3(t_stacks *stacks);

// no_logical_rotate_n_push.c
void	no_logical_first_mediane(t_stacks *stacks, int limit, int push);
void	no_logical_second_mediane(t_stacks *stacks);
void	no_logical_push_mediane(t_stacks *stacks);

// no_logical_search_best_move.c
void	no_logical_search_best_move(t_stacks *stacks);

// no_logical_sort
void	no_logical_sort(t_stacks *stacks);

// push_swap_utils.c
int		ft_alloc_my_stacks(t_stacks *stacks);
void	no_logical_sort_of_4(t_stacks *stacks);

// rotate_with_gas_fee.c
void	rotate_a_gas_fee(t_stacks *stacks, int ra_gas_fee);
void	rotate_b_gas_fee(t_stacks *stacks, int rb_gas_fee);
void	reverse_ra_gas_fee(t_stacks *stacks, int rra_gas_fee);
void	reverse_rb_gas_fee(t_stacks *stacks, int rrb_gas_fee);

#endif
