/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:34:17 by jferone           #+#    #+#             */
/*   Updated: 2026/01/12 16:52:56 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>

/* CAUTION: ALL MY CODE BELOW IS ONLY FOR EXEMPLE ON OUR ARCH PROG DEFINITION */

/* ===== STRUCTURES ===== */

// Quick read: IDs for the statboard (benchmark)
typedef enum e_op {
	OP_SA, OP_SB, OP_SS,
	OP_PA, OP_PB,
	OP_RA, OP_RB, OP_RR,
	OP_RRA, OP_RRB, OP_RRR,
	OP_COUNT
}	t_op;

typedef struct s_stack {
	long			value;
	int				index;
	int				pos;
	

	int				cost_a;
	int				cost_b;
	struct s_stack	*target;
	
	struct s_stack	*next;
}	t_stack;

// Quick read: Global Context Brain structure
typedef struct s_app {
	t_stack	*a;
	t_stack	*b;
	int		size_a;
	int		size_b;

	bool	f_simple;
	bool	f_medium;
	bool	f_complex;
	bool	f_adaptive;
	bool	f_bench;

	double	disorder;
	long	ops_total;
	int		ops_stats[OP_COUNT];
}	t_app;

/* ===== PROTOTYPES ===== */

/* --- Managers --- */

// initialization.c
void	init_app(t_app *app);
void	init_stack_a(t_app *app, int argc, char **argv);

// checks.c
void	check_syntax(char *str);
void	check_duplicates(t_stack *a);

// flags.c
void	parse_flags(t_app *app, int *argc, char ***argv);

// metrics.c
bool	is_sorted(t_stack *stack);
void	compute_disorder(t_app *app); // [cite: 168-176]

// strategy.c
void	dispatch_strategy(t_app *app);

// benchmark.c
void	print_benchmark(t_app *app); // [cite: 279]

/* --- Algorithms --- */

void	solve_simple(t_app *app);   // O(n^2)
void	solve_medium(t_app *app);   // O(n√n)
void	solve_complex(t_app *app);  // Turk Sort

/* --- Operations --- */

void	op_sa(t_app *app, bool print);
void	op_sb(t_app *app, bool print);
void	op_ss(t_app *app, bool print);

void	op_pa(t_app *app, bool print);
void	op_pb(t_app *app, bool print);

void	op_ra(t_app *app, bool print);
void	op_rb(t_app *app, bool print);
void	op_rr(t_app *app, bool print);

void	op_rra(t_app *app, bool print);
void	op_rrb(t_app *app, bool print);
void	op_rrr(t_app *app, bool print);

/* --- Utils --- */

// cleanup.c
void	free_app(t_app *app);
void	error_exit(t_app *app, char *msg);

// cost.c (Helpers pour Turk Sort)
void	set_target_positions(t_app *app);
void	calculate_move_cost(t_app *app);
t_stack	*get_cheapest_node(t_stack *stack);

// wrappers.c
long	ft_atol_strict(const char *str, t_app *app);

#endif
