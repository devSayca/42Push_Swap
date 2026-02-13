/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:34:17 by jferone           #+#    #+#             */
/*   Updated: 2026/02/13 13:33:17 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>
# include <limits.h>

/* ______ E N U M S  &  S T R U C T S _______ */

/* ENUM_OP: Ops codification for benchmark construction */
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

/* ENUM_MODE: Flags codification for dispatch_strategy.c */
typedef enum e_mode
{
	MODE_ADAPTIVE,
	MODE_SIMPLE,
	MODE_MEDIUM,
	MODE_COMPLEX,
	MODE_BENCH
}	t_mode;

/* STRUCT_STACK : Stacks meta-data for A & B */
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

/* STRUCT_GCB: Global Context Block super-structure */
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

/* __________ F U N C T I O N S ___________ */
// --------------- MANAGERS --------------- */
// mgr_initialization.c
void		init_gcb(t_gcb *gcb);
void		init_stack_a(t_gcb *gcb, char **argv, size_t start_index);
// mgr_checkers.c
void		check_syntax(t_gcb *gcb, char *str);
void		check_duplicates(t_gcb *gcb);
// mgr_flags.c
int			parse_flags(t_gcb *gcb, int argc, char **argv);
// mgr_metrics.c
bool		is_sorted(t_stack *stack);		
void		compute_disorder(t_gcb *gcb);
// mgr_strategy.c
void		dispatch_strategy(t_gcb *gcb);
// mgr_benchmark.c
void		print_benchmark(t_gcb *gcb);

// ----------- ALGORITHMS ----------- */
// algo_simple.c
void		solve_simple(t_gcb *gcb);
// algo_medium.c
void		solve_medium(t_gcb *gcb);
// algo_complex.c
void		solve_complex(t_gcb *gcb);

/* ----------- OPERATORS ----------- */
// ops_swap.c
void		op_sa(t_gcb *gcb, bool print);
void		op_sb(t_gcb *gcb, bool print);
void		op_ss(t_gcb *gcb, bool print);
// ops_push.c
void		op_pa(t_gcb *gcb, bool print);
void		op_pb(t_gcb *gcb, bool print);
// ops_rotate.c
void		op_ra(t_gcb *gcb, bool print);
void		op_rb(t_gcb *gcb, bool print);
void		op_rr(t_gcb *gcb, bool print);
// ops_rrotate.c
void		op_rra(t_gcb *gcb, bool print);
void		op_rrb(t_gcb *gcb, bool print);
void		op_rrr(t_gcb *gcb, bool print);

/* ----------- UTILITARIES ----------- */
// utils_cleanup.c
void		free_stack(t_stack **stack);
void		free_gcb(t_gcb *gcb);
void		error_exit(t_gcb *gcb, char *msg);
// utils_cost.c
void		set_target_positions(t_gcb *gcb);
void		calculate_move_cost(t_gcb *gcb);
t_stack		*get_cheapest_node(t_stack *stack);
// utils_wrappers.c
long long	ft_atoll_strict(const char *str, t_gcb *gcb);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(const char *s);
void		ft_putstr(char *str);
int			absol_val(int nbr);

/* ---------- ORCHESTRATOR ---------- */
int			main(int argc, char **argv);

#endif
