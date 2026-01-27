/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgr_strategy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:59:49 by jferone           #+#    #+#             */
/*   Updated: 2026/01/27 14:58:53 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Quick read: Compute disorder if adaptive, and/or selects 1 of the 3 methods.
void	dispatch_strategy(t_gcb *gcb)
{
	if (gcb->mode == MODE_ADAPTIVE)
	{
		compute_disorder(gcb);
		if (gcb->disorder < 0.2)
			gcb->mode = MODE_SIMPLE;
		else if (gcb->disorder <= 0.5)
			gcb->mode = MODE_MEDIUM;
		else
			gcb->mode = MODE_COMPLEX;
	}
	if (gcb->mode == MODE_SIMPLE)
		solve_simple(gcb);
	else if (gcb->mode == MODE_MEDIUM)
		solve_medium(gcb);
	else if (gcb->mode == MODE_COMPLEX)
		solve_complex(gcb);
}
