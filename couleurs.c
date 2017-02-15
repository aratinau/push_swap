/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   couleurs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 15:50:35 by aratinau          #+#    #+#             */
/*   Updated: 2015/06/21 16:27:13 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	color_str(char *s, char *opt)
{
	ft_putstr("\033[");
	ft_putstr(opt);
	ft_putstr("m");
	while (*s != '\0')
		ft_putchar(*s++);
	ft_putstr("\033[0m");
}

void	color_nbr(int n, char *opt)
{
	ft_putstr("\033[");
	ft_putstr(opt);
	ft_putstr("m");
	ft_putnbr(n);
	ft_putstr("\033[0m");
}
