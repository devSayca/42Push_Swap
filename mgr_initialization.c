/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgr_initialization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:11:15 by jferone           #+#    #+#             */
/*   Updated: 2026/02/06 17:46:58 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// HANDLING QUOTED ARGUMENTS VERSION

// Quick read: Creates a new stack node with default values.
static t_stack	*stack_new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->pos = -1;
	node->cost_a = 0;
	node->cost_b = 0;
	node->target = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

// Quick read: Inits a node to the end of the doubly linked list.
static void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

// Quick read: Initializes GCB values to their default states.
void	init_gcb(t_gcb *gcb)
{
	int	idx;

	gcb->a = NULL;
	gcb->b = NULL;
	gcb->disorder = 0.0;
	gcb->ops_total = 0;
	gcb->size_a = 0;
	gcb->size_b = 0;
	gcb->mode = MODE_ADAPTIVE;
	gcb->f_bench = false;
	idx = 0;
	while (idx < OP_COUNT)
	{
		gcb->ops_stats[idx] = 0;
		idx++;
	}
}

// Quick read: Serves directly "void init_stack_a"
static int	skip_number(char *str, int idx)
{
	if (str[idx] == '-' || str[idx] == '+')
		idx++;
	while (str[idx] >= '0' && str[idx] <= '9')
		idx++;
	return (idx);
}

// Quick read: Parses argv, validates and builds the initial stack *a.
void	init_stack_a(t_gcb *gcb, char **argv, int start)
{
	t_stack	*new;
	int		idx;

	while (argv[start])
	{
		check_syntax(gcb, argv[start]);
		idx = 0;
		while (argv[start][idx])
		{
			while (argv[start][idx] == ' ' || (argv[start][idx] >= 9
				&& argv[start][idx] <= 13))
				idx++;
			if (argv[start][idx] == '\0')
				break ;
			new = stack_new_node((int)ft_atoll_strict(&argv[start][idx], gcb));
			if (!new)
				error_exit(gcb, "Error\n");
			stack_add_back(&(gcb->a), new);
			gcb->size_a++;
			idx = skip_number(argv[start], idx);
		}
		start++;
	}
	if (gcb->size_a > 0)
		check_duplicates(gcb);
}
