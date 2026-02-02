/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:43:51 by jferone           #+#    #+#             */
/*   Updated: 2026/01/27 14:59:06 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Quick read: Refresh cursor positions for accurate cost calculation
static void	update_positions(t_stack *stack)
{
	int	cursor;

	cursor = 0;
	while (stack)
	{
		stack->pos = cursor;
		stack = stack->next;
		cursor++;
	}
}

// Quick read: Finds the best target in *A (smallest > val, or Min if none)
static t_stack	*find_target(t_stack *a, int val)
{
	t_stack	*target;
	t_stack	*min;
	long	best;

	target = NULL;
	min = a;
	best = LONG_MAX;
	while (a)
	{
		if (a->value < min->value)
			min = a;
		if (a->value > val && a->value < best)
		{
			best = a->value;
			target = a;
		}
		a = a->next;
	}
	if (target)
		return (target);
	return (min);
}

// Quick read: Assigns a target node in *A for every node in *B
void	set_target_positions(t_gcb *gcb)
{
	t_stack	*b_node;

	update_positions(gcb->a);
	update_positions(gcb->b);
	b_node = gcb->b;
	while (b_node)
	{
		b_node->target = find_target(gcb->a, b_node->value);
		b_node = b_node->next;
	}
}

// Quick read: Calculates cost (pos and neg) to bring element and target to top
void	calculate_move_cost(t_gcb *gcb)
{
	t_stack	*b;
	int		sz_a;
	int		sz_b;

	b = gcb->b;
	sz_a = gcb->size_a;
	sz_b = gcb->size_b;
	while (b)
	{
		b->cost_b = b->pos;
		if (b->pos > sz_b / 2)
			b->cost_b = (sz_b - b->pos) * -1;
		if (b->target)
		{
			b->cost_a = b->target->pos;
			if (b->target->pos > sz_a / 2)
				b->cost_a = (sz_a - b->target->pos) * -1;
		}
		b = b->next;
	}
}

// Quick read: Finds the node with the cheapest combined move cost
t_stack	*get_cheapest_node(t_stack *stack)
{
	t_stack	*cheap;
	long	min;
	long	cost;

	cheap = NULL;
	min = LONG_MAX;
	while (stack)
	{
		cost = absol_val(stack->cost_a) + absol_val(stack->cost_b);
		if ((stack->cost_a > 0 && stack->cost_b > 0)
			|| (stack->cost_a < 0 && stack->cost_b < 0))
		{
			cost = absol_val(stack->cost_a);
			if (absol_val(stack->cost_b) > cost)
				cost = absol_val(stack->cost_b);
		}
		if (cost < min)
		{
			min = cost;
			cheap = stack;
		}
		stack = stack->next;
	}
	return (cheap);
}
