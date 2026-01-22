/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_wrappers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:43:57 by jferone           #+#    #+#             */
/*   Updated: 2026/01/19 17:54:37 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Quick read: Compacted returner of digital numbers (jferone test prototype)
static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

// Quick read: Shows/cast an entire string of chars
void	ft_putstr(char *str)
{
	int	cursor;

	cursor = 0;
	if (!str)
		return ;
	while (str[cursor])
	{
		write(1, &str[cursor], 1);
		cursor++;
	}
}

// Quick read: Absolute value of a pos/neg Number (measures its distance from 0)
int		absol_val(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

// Quick read: Controls signs, Errors and Int-overflows (needs <limits.h>)
long	ft_atol_strict(const char *str, t_gcb *gcb)
{
	long	nbr;
	int		cursor;
	int		sign;

	nbr = 0;
	cursor = 0;
	sign = 1;
	if (str[cursor] == '+' || str[cursor] == '-')
	{
		if (str[cursor] == '-')
			sign = -1;
		cursor++;
	}
	if (!str[cursor])
		error_exit(gcb, "Error\n");
	while (str[cursor])
	{
		if (!is_digit(str[cursor]))
			error_exit(gcb, "Error\n");
		nbr = nbr * 10 + (str[cursor] - '0');
		if ((sign == 1 && nbr > INT_MAX) || (sign == -1 && (-nbr) < INT_MIN))
			error_exit(gcb, "Error\n");
		cursor++;
	}
	return (nbr * sign);
}
