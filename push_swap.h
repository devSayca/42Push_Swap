/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:34:17 by jferone           #+#    #+#             */
/*   Updated: 2026/01/20 17:56:05 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>
# include <limits.h>
// # include <stdio.h> (used for printf in extra-evaluation tests)

/* ===== ENUMERATIONS ===== */

/* --- OPERATIONS ENUM --- */
// Used for benchmark's statboard.
typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_op;

/* --- FLAG MODES ENUM --- */
// Default mode is --adaptive. The last flag wins. --bench is additional.
typedef enum e_mode
{
	MODE_ADAPTIVE,
	MODE_SIMPLE,
	MODE_MEDIUM,
	MODE_COMPLEX,
	MODE_BENCH
}	t_mode;

/* --- STACK NODE STRUCTURE --- */
typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;

	int				cost_a;
	int				cost_b;
	struct s_stack	*target;

	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* --- GLOBAL CONTEXT BRAIN (GCB) STRUCTURE ---*/
typedef struct s_gcb
{
	t_stack	*a;
	t_stack	*b;
	double	disorder;
	long	ops_total;

	int		size_a;
	int		size_b;
	int		ops_stats[OP_COUNT];

	t_mode	mode;
	bool	f_bench;
}	t_gcb;

/* ======================================== */
/* -------------- PROTOTYPES -------------- */
/* Managers, Algorithms, Operations, Utils. */
/* ======================================== */

// mgr_initialization.c
void	init_gcb(t_gcb *gcb);
void	init_stack_a(t_gcb *gcb, char **argv, int start_index);

// mgr_checks.c
void	check_syntax(char *str);
void	check_duplicates(t_stack *a);

// mgr_flags.c
int		parse_flags(t_gcb *gcb, int argc, char **argv);

// mgr_metrics.c
bool	is_sorted(t_stack *stack);
void	compute_disorder(t_gcb *gcb);

// mgr_strategy.c
void	dispatch_strategy(t_gcb *gcb);

// mgr_benchmark.c
void	print_benchmark(t_gcb *gcb);

// algo_simple.c
void	solve_simple(t_gcb *gcb);

// algo_medium.c
void	solve_medium(t_gcb *gcb);

// algo_complex.c
void	solve_complex(t_gcb *gcb);

// ops_swap.c
void	op_sa(t_gcb *gcb, bool print);
void	op_sb(t_gcb *gcb, bool print);
void	op_ss(t_gcb *gcb, bool print);

// ops_push.c
void	op_pa(t_gcb *gcb, bool print);
void	op_pb(t_gcb *gcb, bool print);

// ops_rotate.c
void	op_ra(t_gcb *gcb, bool print);
void	op_rb(t_gcb *gcb, bool print);
void	op_rr(t_gcb *gcb, bool print);

// ops_rrotate.c
void	op_rra(t_gcb *gcb, bool print);
void	op_rrb(t_gcb *gcb, bool print);
void	op_rrr(t_gcb *gcb, bool print);

// utils_cleanup.c
void	free_gcb(t_gcb *gcb);
void	error_exit(t_gcb *gcb, char *msg);

// utils_cost.c	(helpers for complex algorithm)
void	set_target_positions(t_gcb *gcb);
void	calculate_move_cost(t_gcb *gcb);
t_stack	*get_cheapest_node(t_stack *stack);

// utils_wrappers.c
long	ft_atol_strict(const char *str, t_gcb *gcb);

/* ===== MAIN FUNCTION ===== */
// main.c
int		main(int argc, char **argv);

#endif
