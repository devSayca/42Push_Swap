/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 09:28:51 by jferone           #+#    #+#             */
/*   Updated: 2026/02/03 17:59:42 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Quick read: Finds the index of the minimum value in stack *A
static int	get_min_pos(t_stack *stack)
{
	int	min;
	int	pos;
	int	min_pos;

	if (!stack)
		return (0);
	min = stack->value;
	pos = 0;
	min_pos = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (min_pos);
}

// Quick read: Brutal sort for 3 elements (Max-to-bottom logic)
static void	simple_sort_three(t_gcb *gcb)
{
	int		val1;
	int		val2;
	int		val3;

	if (gcb->size_a < 3)
		return ;
	val1 = gcb->a->value;
	val2 = gcb->a->next->value;
	val3 = gcb->a->next->next->value;
	if (val1 > val2 && val1 > val3)
		op_ra(gcb, true);
	else if (val2 > val1 && val2 > val3)
		op_rra(gcb, true);
	if (gcb->a->value > gcb->a->next->value)
		op_sa(gcb, true);
}

// Quick read: Rotates stack A to bring the target position to the top
static void	bring_to_top(t_gcb *gcb, int pos)
{
	if (pos <= gcb->size_a / 2)
	{
		while (pos > 0)
		{
			op_ra(gcb, true);
			pos--;
		}
	}
	else
	{
		while (pos < gcb->size_a)
		{
			op_rra(gcb, true);
			pos++;
		}
	}
}

// Quick read: Simple Sort O(n^2) that extracts min to B, sorts 3, pushes back.
void	solve_simple(t_gcb *gcb)
{
	if (gcb->size_a == 2)
	{
		if (gcb->a->value > gcb->a->next->value)
			op_sa(gcb, true);
		return ;
	}
	while (gcb->size_a > 3)
	{
		bring_to_top(gcb, get_min_pos(gcb->a));
		op_pb(gcb, true);
	}
	simple_sort_three(gcb);
	while (gcb->b)
		op_pa(gcb, true);
}
