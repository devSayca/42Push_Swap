/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_wrappers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:43:57 by jferone           #+#    #+#             */
/*   Updated: 2026/02/03 16:32:45 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Quick read: Shows/cast an entire string of chars
void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	if (!str)
		return ;
	while (str[idx])
	{
		write(1, &str[idx], 1);
		idx++;
	}
}

// Quick read: Absolute value used for cost calculation about complex algorithm
int	absol_val(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}
// Quick read: 64bits parser, stops on non-digit, ERRORS on 32bit overflow.
long long	ft_atoll_strict(const char *str, t_gcb *gcb)
{
	long long	nbr;
	int			idx;
	int			sign;

	nbr = 0;
	idx = 0;
	sign = 1;
	if (str[idx] == '+' || str[idx] == '-')
		if (str[idx++] == '-')
			sign = -1;
	if (!str[idx])
		error_exit(gcb, "Error NO STRING ATOLL\n");
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		if (nbr > (LLONG_MAX - (str[idx] - '0')) / 10)
			error_exit(gcb, "Error INT OVERFLOW ALPHA\n");
		nbr = nbr * 10 + (str[idx++] - '0');
		if ((sign == 1 && nbr > INT_MAX) || (sign == -1 && nbr > 2147483648LL))
			error_exit(gcb, "Error INT OVERFLOW BRAVO\n");
	}
	return (nbr * sign);
}
