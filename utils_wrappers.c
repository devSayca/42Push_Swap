/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_wrappers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:43:57 by jferone           #+#    #+#             */
/*   Updated: 2026/02/12 16:21:08 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Quick read: Basic utilitary for flags parser and bonus checker.
int	ft_strcmp(char *s1, char *s2)
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

// Quick read: Basic utilitary for bonus checker.
char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	idx;
	int		len;

	len = 0;
	while (s[len])
		len++;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	idx = 0;
	while (s[idx])
	{
		str[idx] = s[idx];
		idx++;
	}
	str[idx] = '\0';
	return (str);
}

// Quick read: Shows/cast an entire string of chars
void	ft_putstr(char *str)
{
	size_t	idx;

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
	size_t		idx;
	int			sign;

	nbr = 0;
	idx = 0;
	sign = 1;
	if (str[idx] == '+' || str[idx] == '-')
		if (str[idx++] == '-')
			sign = -1;
	if (!str[idx])
		error_exit(gcb, "Error\n");
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		if (nbr > (LLONG_MAX - (str[idx] - '0')) / 10)
			error_exit(gcb, "Error\n");
		nbr = nbr * 10 + (str[idx++] - '0');
		if ((sign == 1 && nbr > INT_MAX) || (sign == -1 && nbr > 2147483648LL))
			error_exit(gcb, "Error\n");
	}
	return (nbr * sign);
}
