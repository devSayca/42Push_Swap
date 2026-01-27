/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgr_metrics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:58:09 by jferone           #+#    #+#             */
/*   Updated: 2026/01/27 14:58:55 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Quick read: Checks if *stack is pending for attention (unsorted)
bool	is_sorted(t_stack *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

// Quick read: Helper to count inversions for compute_disorder.
static void	count_inversions(t_stack *cursor, long *mistakes, long *pairs)
{
	t_stack	*compare;

	compare = cursor->next;
	while (compare)
	{
		(*pairs)++;
		if (cursor->value > compare->value)
			(*mistakes)++;
		compare = compare->next;
	}
}

// Quick read: Calculates disorder ratio according to subject rules.
void	compute_disorder(t_gcb *gcb)
{
	t_stack	*cursor;
	long	mistakes;
	long	pairs;

	if (!gcb->a || !gcb->a->next)
	{
		gcb->disorder = 0.0;
		return ;
	}
	mistakes = 0;
	pairs = 0;
	cursor = gcb->a;
	while (cursor)
	{
		count_inversions(cursor, &mistakes, &pairs);
		cursor = cursor->next;
	}
	if (pairs == 0)
		gcb->disorder = 0.0;
	else
		gcb->disorder = (double)mistakes / (double)pairs;
}
