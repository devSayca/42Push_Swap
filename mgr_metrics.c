/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metrics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:58:09 by jferone           #+#    #+#             */
/*   Updated: 2026/01/15 23:58:09 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Quick read: 
bool	is_sorted(t_stack *stack);

// Quick read: Disorder evaluation of stack a.
void	compute_disorder(t_gcb *gcb)
{
	t_stack	*tmp;
	int		breaks;

    if (gcb->size_a < 2)
	{
		gcb->disorder = 0.0;
        return ;
    }
    tmp = gcb->a;
    breaks = 0;
    while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			 breaks++;
		tmp = tmp->next;
    }
	gcb->disorder = (double)breaks / (double)(gcb->size_a - 1);
}
