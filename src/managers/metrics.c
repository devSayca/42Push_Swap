/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metrics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:58:09 by jferone           #+#    #+#             */
/*   Updated: 2026/01/15 23:58:09 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Quick read: 
int		is_sorted();

// Quick read: Disorder evaluation of stack a.
void	compute_disorder(t_gcb *gcb)
{
	t_stack	*tmp;
	int		breaks;

    if (gcb->size_a < 2)
	{
		gcb->disorder = 0.0;
        return ;
    }
    tmp = gcb->a;
    breaks = 0;
    while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			 breaks++;
		tmp = tmp->next;
    }
	gcb->disorder = (double)breaks / (double)(gcb->size_a - 1);
}

/* LEGACY @jferone's FUNCTIONS TO REWORK */
// Reminder: Signs 0/1 condition verification
int	ft_issign(char c)
{
	if (c == '+' || c <= '-')
		return (1);
	return (0);
}

// Reminder: Digits 0/1 condition verification
int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// Reminder: Adapted ft_strcmp for numbers
int	number_cmp(char *s1, char *s2)
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
