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
void		ft_putstr(char *str)
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

// Quick read: Universal 64 bits sign parser, returns error if 32bits overflows.
long long	ft_atoll_strict32(const char *str, t_gcb *gcb)
{
	long long	nbr;
	int			cursor;
	int			sign;

	nbr = 0;
	cursor = 0;
	sign = 1;
	if (str[cursor] == '+' || str[i] == '-')
		if (str[cursor++] == '-')
			sign = -1;
	if (!str[cursor])
		error_exit(gcb, "Error\n");
	while (str[cursor])
	{
		if (str[cursor] < '0' || str[cursor] > '9')
			error_exit(gcb, "Error\n");
		if (nbr > (LLONG_MAX - (str[cursor] - '0')) / 10)
			error_exit(gcb, "Error\n");
		nbr = nbr * 10 + (str[cursor++] - '0');
		if ((sign == 1 && nbr > INT_MAX) || (sign == -1 && nbr > 2147483648ULL))
			error_exit(gcb, "Error\n");
	}
	return (nbr * sign);
}
