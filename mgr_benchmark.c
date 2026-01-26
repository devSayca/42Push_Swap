/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgr_benchmark.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:03:20 by jferone           #+#    #+#             */
/*   Updated: 2026/01/19 17:54:57 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Helper: Writes a string to STDERR (fd 2)
static void	put_err(char *str)
{
	int	cursor;

	cursor = 0;
	if (!str)
		return ;
	while (str[cursor])
	{
		write(2, &str[cursor], 1);
		cursor++;
	}
}

// Helper: Writes a number to STDERR (fd 2)
static void	put_nbr_err(long n)
{
	char	c;

	if (n < 0)
	{
		write(2, "-", 1);
		n = -n;
	}
	if (n >= 10)
		put_nbr_err(n / 10);
	c = (n % 10) + '0';
	write(2, &c, 1);
}

// Helper: Prints the strategy name based on the mode enum.
static void	print_strategy_name(t_mode mode)
{
	put_err("[bench] strategy:\n");
	if (mode == MODE_SIMPLE)
		put_err("Simple / O(n^2)\n");
	else if (mode == MODE_MEDIUM)
		put_err("Medium / O(n sqrt(n))\n");
	else if (mode == MODE_COMPLEX)
		put_err("Complex / O(n log n)\n");
	else
		put_err("Adaptive (Hybrid)\n");
}

// Helper: Prints the operation breakdown.
static void	print_ops_breakdown(t_gcb *gcb)
{
	put_err("[bench] sa: ");
	put_nbr_err(gcb->ops_stats[OP_SA]);
	put_err(" sb: ");
	put_nbr_err(gcb->ops_stats[OP_SB]);
	put_err(" ss: ");
	put_nbr_err(gcb->ops_stats[OP_SS]);
	put_err("\n[bench] pa: ");
	put_nbr_err(gcb->ops_stats[OP_PA]);
	put_err(" pb: ");
	put_nbr_err(gcb->ops_stats[OP_PB]);
	put_err("\n[bench] ra: ");
	put_nbr_err(gcb->ops_stats[OP_RA]);
	put_err(" rb: ");
	put_nbr_err(gcb->ops_stats[OP_RB]);
	put_err(" rr: ");
	put_nbr_err(gcb->ops_stats[OP_RR]);
	put_err("\n[bench] rra: ");
	put_nbr_err(gcb->ops_stats[OP_RRA]);
	put_err(" rrb: ");
	put_nbr_err(gcb->ops_stats[OP_RRB]);
	put_err(" rrr: ");
	put_nbr_err(gcb->ops_stats[OP_RRR]);
	put_err("\n");
}

// Quick read: Writes the bench report in STDERR if --bench flag is on.
void	print_benchmark(t_gcb *gcb)
{
	long	percent_int;
	long	percent_dec;

	if (!gcb->f_bench)
		return ;
	put_err("\n=== BENCHMARK REPORT ===\n");
	put_err("[bench] disorder:\n");
	percent_int = (long)(gcb->disorder * 100);
	percent_dec = (long)(gcb->disorder * 10000) % 100;
	put_nbr_err(percent_int);
	put_err(".");
	if (percent_dec < 10)
		put_err("0");
	put_nbr_err(percent_dec);
	put_err("%\n");
	print_strategy_name(gcb->mode);
	put_err("[bench] total_ops:\n");
	put_nbr_err(gcb->ops_total);
	put_err("\n");
	print_ops_breakdown(gcb);
	put_err("========================\n\n");
}
