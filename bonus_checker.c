/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:36:33 by jferone           #+#    #+#             */
/*   Updated: 2026/02/04 14:28:06 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Quick read: Sub dispatcher (Handles rotation instructions only)
static int	apply_rot(t_gcb *gcb, char *line)
{
	if (ft_strcmp(line, "ra") == 0)
		op_ra(gcb, false);
	else if (ft_strcmp(line, "rb") == 0)
		op_rb(gcb, false);
	else if (ft_strcmp(line, "rr") == 0)
		op_rr(gcb, false);
	else if (ft_strcmp(line, "rra") == 0)
		op_rra(gcb, false);
	else if (ft_strcmp(line, "rrb") == 0)
		op_rrb(gcb, false);
	else if (ft_strcmp(line, "rrr") == 0)
		op_rrr(gcb, false);
	else
		return (0);
	return (1);
}

// Quick read: Main dispatcher (Handles sa, sb, ss, pa, pb + rotations)
static void	apply_instruction(t_gcb *gcb, char *line)
{
	int	res;

	res = 1;
	if (ft_strcmp(line, "sa") == 0)
		op_sa(gcb, false);
	else if (ft_strcmp(line, "sb") == 0)
		op_sb(gcb, false);
	else if (ft_strcmp(line, "ss") == 0)
		op_ss(gcb, false);
	else if (ft_strcmp(line, "pa") == 0)
		op_pa(gcb, false);
	else if (ft_strcmp(line, "pb") == 0)
		op_pb(gcb, false);
	else
		res = apply_rot(gcb, line);
	if (!res)
	{
		free(line);
		error_exit(gcb, "Error\n");
	}
	free(line);
}

// Quick read: Reader (with compact direct allocation)
static char	*read_instructions(void)
{
	char	*buf;
	int		idx;
	int		ret;
	char	c;

	idx = 0;
	buf = (char *)malloc(6);
	if (!buf)
		return (NULL);
	while (idx < 5)
	{
		ret = read(0, &c, 1);
		if (ret <= 0 || c == '\n')
			break ;
		buf[idx++] = c;
	}
	if (idx == 0 && ret <= 0)
		return (free(buf), NULL);
	buf[idx] = '\0';
	return (buf);
}

// Quick read: Used only when "make bonus" typed
int	main(int argc, char **argv)
{
	t_gcb	gcb;
	char	*line;

	if (argc < 2)
		return (0);
	init_gcb(&gcb);
	init_stack_a(&gcb, argv, 1);
	while (1)
	{
		line = read_instructions();
		if (!line)
			break ;
		apply_instruction(&gcb, line);
	}
	if (is_sorted(gcb.a) && gcb.size_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_gcb(&gcb);
	return (0);
}
