/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:36:33 by jferone           #+#    #+#             */
/*   Updated: 2026/02/04 11:55:18 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// Quick read: Reads a lign of STDIN (without a complete GNL for efficiency)
static char	*read_instructions(void)
{
	char	buf[5];
	int		idx;
	int		ret;

	idx = 0;
	while (idx < 4)
	{
		ret = read(0, &buf[idx], 1);
		if (ret <= 0)
			return (NULL);
		if (buf[idx] == '\n')
		{
			buf[idx] = '\0'
			return (ft_strdup(buf));
		}
		idx++;
	}
	return (NULL);
}

// Quick read: Exec the instruction in GCB
static void	apply_instruction(t_gcb *gcb, char *line)
{
	if (ft_strcmp(line, "sa") == 0) op_sa(gcb, false);
	else if (ft_strcmp(line, "sb") == 0) op_sb(gcb, false);
	else if (ft_strcmp(line, "ss") == 0) op_ss(gcb, false);
	else if (ft_strcmp(line, "pa") == 0) op_pa(gcb, false);
	else if (ft_strcmp(line, "pb") == 0) op_pb(gcb, false);
	else if (ft_strcmp(line, "ra") == 0) op_ra(gcb, false);
	else if (ft_strcmp(line, "rb") == 0) op_rb(gcb, false);
	else if (ft_strcmp(line, "rr") == 0) op_rr(gcb, false);
	else if (ft_strcmp(line, "rra") == 0) op_rra(gcb, false);
	else if (ft_strcmp(line, "rrb") == 0) op_rrb(gcb, false);
	else if (ft_strcmp(line, "rrr") == 0) op_rrr(gcb, false);
	else
	{
		free(line);
		error_exit(gcb, "Error\n");
	}
	free(line);
}

// Quick read: There is the main of BONUS MODE, without flags handling.
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
		apply_instruction(&gcb, *line);
	}
	if (is_sorted(gcb.a) && gcb.size_b == 0)
		write(1, "OK\n, 3");
	else
		write(1, "KO\n, 3");
	free_gcb(&gcb);
	return (0);
} 
