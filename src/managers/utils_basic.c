/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 09:49:29 by jferone           #+#    #+#             */
/*   Updated: 2026/01/13 09:49:29 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fast read: Shows/cast (with "write" function) an entire string of chars
void	ft_putstr(char *str)
{
	int	cursor;

	cursor = 0;
	while (str[cursor])
	{
		write(1, &str[cursor], 1);
		cursor++;
	}
}

// Fast read: Converts ASCII char numbers (from *str) to an integer "int number"
long int	ft_atoi(const char *str)
{
	long int	number;
	int			cursor;
	int			isneg;

	number = 0;
	cursor = 0;
	isneg = 1;
	if (str[cursor] == '+')
		cursor++;
	else if (str[cursor] == '-')
	{
		isneg *= -1;
		cursor++;
	}
	while (is_digit(str[cursor]))
	{
		number = (number * 10) + (str[cursor] - '0');
		cursor++;
	}
	return (number * isneg);
}
