/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:58:05 by jferone           #+#    #+#             */
/*   Updated: 2026/02/13 18:52:41 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Quick read: Internal reverse rotate logic (Bottom -> Top).
static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*penultimate;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	penultimate = last->prev;
	penultimate->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	op_rra(t_gcb *gcb)
{
	reverse_rotate(&(gcb->a));
	gcb->ops_total++;
	gcb->ops_stats[OP_RRA]++;
	if (gcb->print_ops == true)
		write(1, "rra\n", 4);
}

void	op_rrb(t_gcb *gcb)
{
	reverse_rotate(&(gcb->b));
	gcb->ops_total++;
	gcb->ops_stats[OP_RRB]++;
	if (gcb->print_ops == true)
		write(1, "rrb\n", 4);
}

void	op_rrr(t_gcb *gcb)
{
	reverse_rotate(&(gcb->a));
	reverse_rotate(&(gcb->b));
	gcb->ops_total++;
	gcb->ops_stats[OP_RRR]++;
	if (gcb->print_ops == true)
		write(1, "rrr\n", 4);
}
