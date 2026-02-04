/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgr_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:01:54 by jferone           #+#    #+#             */
/*   Updated: 2026/02/04 14:34:56 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// HANDLING QUOTED ARGUMENTS VERSION

// Quick read: Validates a single numerical token (sign + digits)
static int	validate_number(t_gcb *gcb, char *str, int idx)
{
	if (str[idx] == '+' || str[idx] == '-')
	{
		idx++;
		if (str[idx] < '0' || str[idx] > '9')
			error_exit(gcb, "Error\n");
	}
	if (str[idx] < '0' || str[idx] > '9')
		error_exit(gcb, "Error\n");
	while (str[idx] >= '0' && str[idx] <= '9')
		idx++;
	return (idx);
}

// Quick read: Checks if string is a valid number OR a list of numbers
void	check_syntax(t_gcb *gcb, char *str)
{
	int	idx;

	idx = 0;
	if (!str || !str[idx])
		error_exit(gcb, "Error\n");
	while (str[idx])
	{
		while (str[idx] == ' ' || (str[idx] >= 9 && str[idx] <= 13))
			idx++;
		if (str[idx] == '\0')
			break ;
		idx = validate_number(gcb, str, idx);
		if (str[idx] != ' ' && str[idx] != '\0' &&
			!(str[idx] >= 9 && str[idx] <= 13))
			error_exit(gcb, "Error\n");
	}
}

// Quick read: Checks duplications in stack A
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
