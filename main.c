/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:59:36 by jferone           #+#    #+#             */
/*   Updated: 2026/01/19 17:54:47 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Quick read: This is the highest orchestration function. */
int	main(int argc, char **argv)
{
	t_gcb	gcb;
	int		start_index;

	if (argc < 2)
		return (0);
	init_gcb(&gcb);
	start_index = parse_flags(&gcb, argc, argv);
	init_stack_a(&gcb, argv, start_index);
	if (is_sorted(gcb.a))
	{
		free_gcb(&gcb);
		return (0);
	}
	dispatch_strategy(&gcb);
	print_benchmark(&gcb);
	free_gcb(&gcb);
	return (0);
}
