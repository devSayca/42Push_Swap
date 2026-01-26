/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:10:47 by jferone           #+#    #+#             */
/*   Updated: 2026/01/19 17:58:47 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Quick read: Internal push logic (Source -> Dest).
static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = tmp->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dest;
	if (*dest)
		(*dest)->prev = tmp;
	*dest = tmp;
	tmp->prev = NULL;
}

void	op_pa(t_gcb *gcb, bool print)
{
	if (!gcb->b)
		return ;
	push(&(gcb->a), &(gcb->b));
	gcb->size_a++;
	gcb->size_b--;
	gcb->ops_total++;
	gcb->ops_stats[OP_PA]++;
	if (print)
		write(1, "pa\n", 3);
}

void	op_pb(t_gcb *gcb, bool print)
{
	if (!gcb->a)
		return ;
	push(&(gcb->b), &(gcb->a));
	gcb->size_a--;
	gcb->size_b++;
	gcb->ops_total++;
	gcb->ops_stats[OP_PB]++;
	if (print)
		write(1, "pb\n", 3);
}