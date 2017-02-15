/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 22:21:31 by aratinau          #+#    #+#             */
/*   Updated: 2015/06/23 22:21:43 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		is_error_arg(int ac)
{
	if (ac == 1)
	{
		color_str("ERROR manque les arguments\n", "31;7");
		exit (0);
	}
}

void		is_error_digit(void)
{
	color_str("ERROR digit\n", "31;7");
	exit (0);
}
