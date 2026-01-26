/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgr_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:01:54 by jferone           #+#    #+#             */
/*   Updated: 2026/01/19 17:55:07 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool is_sign(char c)
{
    if (c == '+' || c == '-')
        return (true);
    return (false);    
}

static bool is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (true);
    return (false);    
}

// Quick read: Checks if argc contains numbers.
void	check_syntax(t_gcb *gcb, char *str)
{
	int	cursor;

	cursor = 0;
	if (!str || !(str[0]))
		error_exit(gcb, "Error\n");
	if (is_sign(str[cursor]))
	{
		cursor++;
		if (!is_digit(str[cursor]))
			error_exit(gcb, "Error\n");
	}
	while (str[cursor])
	{
		if (!is_digit(str[cursor]))
			error_exit(gcb, "Error\n");
		cursor++;
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