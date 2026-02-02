/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 09:28:53 by jferone           #+#    #+#             */
/*   Updated: 2026/01/27 15:02:58 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Quick read: Sets rank/index (0 to N-1) for each node based on value
static void	assign_indices(t_stack *stack)
{
	t_stack	*ptr;
	t_stack	*compare;
	int		count;

	ptr = stack;
	while (ptr)
	{
		count = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < ptr->value)
				count++;
			compare = compare->next;
		}
		ptr->index = count;
		ptr = ptr->next;
	}
}

// Quick read: Finds position of the maximum index in stack B
static int	get_max_idx_pos(t_stack *stack, int *max_idx)
{
	int	pos;
	int	target_pos;
	int	curr_max;

	pos = 0;
	target_pos = 0;
	curr_max = -1;
	while (stack)
	{
		if (stack->index > curr_max)
		{
			curr_max = stack->index;
			target_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	*max_idx = curr_max;
	return (target_pos);
}

// Quick read: Moves the target position to top of stack B
static void	bring_max_to_top_b(t_gcb *gcb, int pos)
{
	if (pos <= gcb->size_b / 2)
	{
		while (pos > 0)
		{
			op_rb(gcb, true);
			pos--;
		}
	}
	else
	{
		while (pos < gcb->size_b)
		{
			op_rrb(gcb, true);
			pos++;
		}
	}
}

// Quick read: Pushes nodes to B in chunks (ranges)
static void	push_chunks(t_gcb *gcb, int chunk_sz)
{
	int	pushed;
	int	limit;

	pushed = 0;
	limit = chunk_sz;
	while (gcb->a)
	{
		if (gcb->a->index < limit)
		{
			op_pb(gcb, true);
			pushed++;
			if (gcb->b->index < limit - (chunk_sz / 2))
				op_rb(gcb, true);
			if (pushed == limit)
				limit += chunk_sz;
		}
		else
			op_ra(gcb, true);
	}
}

// Quick read: Chunking Sort Strategy core
void	solve_medium(t_gcb *gcb)
{
	int	chunk_sz;
	int	max_idx;
	int	target_pos;

	assign_indices(gcb->a);
	chunk_sz = 20;
	if (gcb->size_a > 150)
		chunk_sz = 45;
	push_chunks(gcb, chunk_sz);
	while (gcb->b)
	{
		target_pos = get_max_idx_pos(gcb->b, &max_idx);
		bring_max_to_top_b(gcb, target_pos);
		op_pa(gcb, true);
	}
}