/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgr_checks_NoQuotedArgs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:01:54 by jferone           #+#    #+#             */
/*   Updated: 2026/02/04 14:34:59 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// NOT HANDLING QUOTED ARGUMENTS VERSION

// Quick read: Checks if argc contains numbers and can switch on quoted or not.
void	check_syntax(t_gcb *gcb, char *str)
{
	static bool	quoted_arg;
	int			idx;

	idx = 0;
	if (!str || !(str[0]))
		error_exit(gcb, "Error\n");
	if (str[idx] == '+' || str[idx] == '-')
	{
		idx++;
		if (!(str[idx] >= '0' && str[idx] <= '9'))
			error_exit(gcb, "Error\n");
	}
	while (str[idx])
	{
		if (!(str[idx] >= '0' && str[idx] <= '9'))
			error_exit(gcb, "Error\n");
		idx++;
	}
}

// Quick read: Checks duplications and eliminate them.
void	check_duplicates(t_gcb *gcb)
{
	t_stack	*current;
	t_stack	*runner;

	if (!gcb->a)
		return ;
	current = gcb->a;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->value == runner->value)
				error_exit(gcb, "Error\n");
			runner = runner->next;
		}
		current = current->next;
	}
}
