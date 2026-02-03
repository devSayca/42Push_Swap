/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgr_initialization_NoQuotedArgs.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:11:15 by jferone           #+#    #+#             */
/*   Updated: 2026/02/03 16:32:54 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// NOT HANDLING QUOTED ARGUMENTS VERSION

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

// Quick read: Parses argv, validates and builds the initial stack *a.
void	init_stack_a(t_gcb *gcb, char **argv, int start_index)
{
	t_stack		*new_node;
	long long	val;

	while (argv[start_index])
	{
		check_syntax(gcb, argv[start_index]);
		val = ft_atoll_strict(argv[start_index], gcb);
		new_node = stack_new_node((int)val);
		if (!new_node)
			error_exit(gcb, "Error NO NEW NODE\n");
		stack_add_back(&(gcb->a), new_node);
		gcb->size_a++;
		start_index++;
	}
	if (gcb->size_a == 0)
		return ;
	check_duplicates(gcb);
}
