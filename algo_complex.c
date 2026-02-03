/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 09:28:52 by jferone           #+#    #+#             */
/*   Updated: 2026/02/03 17:59:34 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Quick read: : Executes remaining single-stack rotations
static void	finish_rotations(t_gcb *gcb, int cost_a, int cost_b)
{
	while (cost_a > 0)
	{
		op_ra(gcb, true);
		cost_a--;
	}
	while (cost_a < 0)
	{
		op_rra(gcb, true);
		cost_a++;
	}
	while (cost_b > 0)
	{
		op_rb(gcb, true);
		cost_b--;
	}
	while (cost_b < 0)
	{
		op_rrb(gcb, true);
		cost_b++;
	}
}

// Quick read: Executes double rotations (optimization)
static void	apply_opti_moves(t_gcb *gcb, t_stack *node)
{
	int	cost_a;
	int	cost_b;

	cost_a = node->cost_a;
	cost_b = node->cost_b;
	while (cost_a > 0 && cost_b > 0)
	{
		op_rr(gcb, true);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		op_rrr(gcb, true);
		cost_a++;
		cost_b++;
	}
	finish_rotations(gcb, cost_a, cost_b);
	op_pa(gcb, true);
}

// Quick read: Sorts the last 3 elements in A
static void	sort_three(t_gcb *gcb)
{
	t_stack	*a;
	int		max;

	a = gcb->a;
	max = a->value;
	if (a->next->value > max)
		max = a->next->value;
	if (a->next->next->value > max)
		max = a->next->next->value;
	if (a->value == max)
		op_ra(gcb, true);
	else if (a->next->value == max)
		op_rra(gcb, true);
	if (gcb->a->value > gcb->a->next->value)
		op_sa(gcb, true);
}

// Quick read: Brings the smallest element of A to the top
static void	final_offset(t_gcb *gcb)
{
	t_stack	*temp;
	t_stack	*min_node;
	int		pos;
	int		min_val;

	temp = gcb->a;
	min_val = stack->value;
	pos = 0;
	while (temp)
	{
		if (temp->value < min_val)
		{
			min_val = temp->value;
			min_node = temp;
		}
		temp = temp->next;
	}
	set_target_positions(gcb);
	pos = min_node->pos;
	if (pos <= gcb->size_a / 2)
		while (gcb->a->value != min_val)
			op_ra(gcb, true);
	else
		while (gcb->a->value != min_val)
			op_rra(gcb, true);
}

// Quick read: Turk Algorithm core (alias "Greedy Cheapest Insertion")
void	solve_complex(t_gcb *gcb)
{
	t_stack	*cheapest;

	if (gcb->size_a > 3 && !is_sorted(gcb->a))
		op_pb(gcb, true);
	if (gcb->size_a > 3 && !is_sorted(gcb->a))
		op_pb(gcb, true);
	while (gcb->size_a > 3 && !is_sorted(gcb->a))
		op_pb(gcb, true);
	sort_three(gcb);
	while (gcb->b)
	{
		set_target_positions(gcb);
		calculate_move_cost(gcb);
		cheapest = get_cheapest_node(gcb->b);
		apply_opti_moves(gcb, cheapest);
	}
	if (!is_sorted(gcb->a))
		final_offset(gcb);
}
