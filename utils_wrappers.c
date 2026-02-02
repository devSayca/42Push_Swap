/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_wrappers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:43:57 by jferone           #+#    #+#             */
/*   Updated: 2026/02/02 17:33:07 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Quick read: Absolute value used for cost calculation about complex algorithm
int	absol_val(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
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

// Quick read: Universal 64 bits sign parser, returns error if 32bits overflows.
long long	ft_atoll_strict(const char *str, t_gcb *gcb)
{
	long long	nbr;
	int			cursor;
	int			sign;

	nbr = 0;
	cursor = 0;
	sign = 1;
	if (str[cursor] == '+' || str[cursor] == '-')
		if (str[cursor++] == '-')
			sign = -1;
	if (!str[cursor])
		error_exit(gcb, "Error NO STRING ATOLL\n");
	while (str[cursor])
	{
		if (str[cursor] < '0' || str[cursor] > '9')
			error_exit(gcb, "Error IS NOT DIGIT ATOLL\n");
		if (nbr > (LLONG_MAX - (str[cursor] - '0')) / 10)
			error_exit(gcb, "Error INT OVERFLOW ALPHA\n");
		nbr = nbr * 10 + (str[cursor++] - '0');
		if ((sign == 1 && nbr > INT_MAX) || (sign == -1 && nbr > 2147483648LL))
			error_exit(gcb, "Error INT OVERFLOW BRAVO\n");
	}
	return (nbr * sign);
}
