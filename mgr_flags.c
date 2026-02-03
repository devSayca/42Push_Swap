/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgr_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:11:26 by jferone           #+#    #+#             */
/*   Updated: 2026/02/03 16:32:55 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Quick read: For "First -- scan process"
static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			iter;
	unsigned char	c1;
	unsigned char	c2;

	iter = 0;
	while ((iter < n) && s1[iter] && s2[iter] && (s1[iter] == s2[iter]))
		iter++;
	if (iter == n)
		return (0);
	c1 = (unsigned char)s1[iter];
	c2 = (unsigned char)s2[iter];
	return (c1 - c2);
}

// Quick read: For "Detailled flag --XXX scan process"
static int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-s2[0]);
	if (!s2)
		return (s1[0]);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

// Quick read: A flexible parser. Unix-like: the last flag wins except --bench.
int	parse_flags(t_gcb *gcb, int argc, char **argv)
{
	int	idx;

	idx = 1;
	while (idx < argc && ft_strncmp(argv[idx], "--", 2) == 0)
	{
		if (ft_strcmp(argv[idx], "--bench") == 0)
			gcb->f_bench = true;
		else if (ft_strcmp(argv[idx], "--simple") == 0)
			gcb->mode = MODE_SIMPLE;
		else if (ft_strcmp(argv[idx], "--medium") == 0)
			gcb->mode = MODE_MEDIUM;
		else if (ft_strcmp(argv[idx], "--complex") == 0)
			gcb->mode = MODE_COMPLEX;
		else if (ft_strcmp(argv[idx], "--adaptive") == 0)
			gcb->mode = MODE_ADAPTIVE;
		else
			error_exit(gcb, "Error BAD FLAG\n");
		idx++;
	}
	return (idx);
}
