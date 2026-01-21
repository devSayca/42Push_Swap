/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:43:13 by jferone           #+#    #+#             */
/*   Updated: 2026/01/19 18:08:38 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack *current;
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	current = *stack;
	while (current)
	{
		tmp = (current)->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

// Quick read: Free GCB stack memory
void	free_gcb(t_gcb *gcb)
{
	if (gcb->a)
		free_stack(&gcb->a);
	if (gcb->b)
		free_stack(&gcb->b);
}

// Quick read: Clears GCB memory, can write specific errors, exit with (1) code.
// NOTA BENE: The subject requires us to return a blind "Error" message.
void	error_exit(t_gcb *gcb, char *msg)
{
	int	msg_len;

	if (gcb)
		free_gcb(gcb);
	if (msg)
	{
		msg_len = 0;
		while (msg[msg_len])
		{
			write(2, &msg[msg_len], 1);
			msg_len++;
		}
	}
	else
		write(2, "Error\n", 6);
	exit (1);
}
