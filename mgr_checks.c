/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgr_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:01:54 by jferone           #+#    #+#             */
/*   Updated: 2026/02/02 19:04:16 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Quick read: NULL to TRUE (init + activate), TRUE to FALSE, FALSE to TRUE.
static bool	switch_quote_indicator(bool is_quoted)
{
	if (!is_quoted)
		return (true);
	else if (is_quoted == true)
		return (false);
	return (true);
}
// Quick read: Handles quoted arguments (ex: "45 894 514" 21 42 84 168)
static void	quoted_arg_mode(t_gcb *gcb, char *str, bool is_quoted)
{
	// jferone: "I need to complete this part before next compilation."
}

// Quick read: Checks if argc contains numbers and can switch on quoted or not.
void	check_syntax(t_gcb *gcb, char *str)
{
	static bool	is_quoted;
	int			cursor;

	cursor = 0;
	if (!str || !(str[0]))
		error_exit(gcb, "Error NO STRING\n");
	if (str[cursor] == '+' || str[cursor] == '-')
	{
		cursor++;
		if (!(str[cursor] >= '0' && str[cursor] <= '9'))
			error_exit(gcb, "Error NO DIGIT AFTER SIGN\n");
	}
	if (str[cursor] == '"')
	{
		switch_quote_indicator(is_quoted);
		if (is_quoted == true)
			quoted_arg_mode(gcb, *str, is_quoted);
	}
	while (str[cursor])
	{
		if (!(str[cursor] >= '0' && str[cursor] <= '9'))
			error_exit(gcb, "Error NO DIGIT\n");
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
				error_exit(gcb, "Error ON check_duplicates\n");
			runner = runner->next;
		}
		current = current->next;
	}
}
