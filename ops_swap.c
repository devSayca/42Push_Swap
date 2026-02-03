/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:57:58 by jferone           #+#    #+#             */
/*   Updated: 2026/02/03 15:31:15 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Quick read: Internal swap logic for doubly linked list.
static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	op_sa(t_gcb *gcb, bool print)
{
	swap(&(gcb->a));
	gcb->ops_total++;
	gcb->ops_stats[OP_SA]++;
	if (print)
		write(1, "sa\n", 3);
}

void	op_sb(t_gcb *gcb, bool print)
{
	swap(&(gcb->b));
	gcb->ops_total++;
	gcb->ops_stats[OP_SB]++;
	if (print)
		write(1, "sb\n", 3);
}

void	op_ss(t_gcb *gcb, bool print)
{
	swap(&(gcb->a));
	swap(&(gcb->b));
	gcb->ops_total++;
	gcb->ops_stats[OP_SS]++;
	if (print)
		write(1, "ss\n", 3);
}
