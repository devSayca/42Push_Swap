/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:34:17 by jferone           #+#    #+#             */
/*   Updated: 2025/12/22 19:23:38 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				v;
	int				idx;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}	t_stack;

typedef struct s_ps
{
	t_stack			a;
	t_stack			b;
}	t_ps;

/* ===== ALGO (src/algo/..) ===== */
void				sort_dispatch(t_ps *ps);
void				sort_radix(t_ps *ps);
void				sort_3(t_ps *ps);
void				sort_4(t_ps *ps);
void				sort_5(t_ps *ps);

/* ===== PARSE (src/parse/..)===== */
int					atoi_checked(const char *s, t_ps *ps);
void				parse_args(int argc, char **argv, t_stack *a, t_ps *ps);
void				parse_tokens(char **tokens, t_stack *a, t_ps *ps);
void				free_tokens(char **toks);
void				check_duplicates_stack(t_stack *a, t_ps *ps);

/* ===== STACK CORE (src/stack/..) ===== */
void				stack_init(t_stack *s);
t_node				*node_new(int v, t_ps *ps);
void				stack_push_bottom(t_stack *s, t_node *n);
void				stack_clear(t_stack *s);
int					stack_is_sorted(t_stack *s);

/* ===== STACK UTILS (src/stack/..) ===== */
void				stack_index(t_stack *a, t_ps *ps);
int					stack_min_idx_pos(t_stack *s);
int					stack_max_idx_pos(t_stack *s);
int					rot_cost(int pos, int size);

/* ===== OPS (src/algo/..) ===== */
void				op_sa(t_ps *ps);
void				op_sb(t_ps *ps);
void				op_ss(t_ps *ps);

void				op_pa(t_ps *ps);
void				op_pb(t_ps *ps);

void				op_ra(t_ps *ps);
void				op_rb(t_ps *ps);
void				op_rr(t_ps *ps);

/* jferone: "See if necessary." */
void				bring_pos_to_top_a(t_ps *ps, int pos);

/* ===== ERROR / FREE (src/..) ===== */
void				ps_error(t_ps *ps);
void				ps_free_all(t_ps *ps);
void				*xmalloc(size_t n, t_ps *ps);

/* Main location (src/main.c) */

#endif