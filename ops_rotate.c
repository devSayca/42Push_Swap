/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:10:40 by jferone           #+#    #+#             */
/*   Updated: 2026/02/13 18:52:32 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Quick read: Internal rotate logic (Top -> Bottom).
static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	op_ra(t_gcb *gcb)
{
	rotate(&(gcb->a));
	gcb->ops_total++;
	gcb->ops_stats[OP_RA]++;
	if (gcb->print_ops == true)
		write(1, "ra\n", 3);
}

void	op_rb(t_gcb *gcb)
{
	rotate(&(gcb->b));
	gcb->ops_total++;
	gcb->ops_stats[OP_RB]++;
	if (gcb->print_ops == true)
		write(1, "rb\n", 3);
}

void	op_rr(t_gcb *gcb)
{
	rotate(&(gcb->a));
	rotate(&(gcb->b));
	gcb->ops_total++;
	gcb->ops_stats[OP_RR]++;
	if (gcb->print_ops == true)
		write(1, "rr\n", 3);
}
