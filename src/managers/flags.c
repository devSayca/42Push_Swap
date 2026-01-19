/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferone <jferone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:11:26 by jferone           #+#    #+#             */
/*   Updated: 2026/01/16 00:11:26 by jferone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Quick read: Detects argv --bench, --simple, --medium, --complex, --adaptive.
int parse_flags(t_gcb *gcb, int argc, char **argv)
{
    int i = 1;

    while (i < argc)
    {
        if (ft_strncmp(argv[i], "--", 2) == 0)
        {
            if (ft_strcmp(argv[i], "--bench") == 0)
                gcb->f_bench = true;
            else if (ft_strcmp(argv[i], "--simple") == 0)
                gcb->mode = MODE_SIMPLE;
            else if (ft_strcmp(argv[i], "--medium") == 0)
                gcb->mode = MODE_MEDIUM;
            else if (ft_strcmp(argv[i], "--complex") == 0)
                gcb->mode = MODE_COMPLEX;
            else if (ft_strcmp(argv[i], "--adaptive") == 0)
                gcb->mode = MODE_ADAPTIVE;
            else
                error_exit(gcb, "Error\n");
            i++;
        }
        else
            break ;
    }
    return (i);
}
