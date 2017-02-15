/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 19:32:43 by aratinau          #+#    #+#             */
/*   Updated: 2015/06/24 14:30:38 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			verif_order(t_dlist *p_list_a)
{
	t_node *tmp;

	tmp = p_list_a->head;
	if (p_list_a->length == 0)
		return (1);
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

int			find_option(char *s, const char c)
{
	while (*s++ != '\0')
	{
		if (*s == c)
			return (1);
	}
	return (0);
}

int			ft_isstringalpha(char *s)
{
	int i;

	i = 0;
	if (s[i] == '-')
		i++;
	else
		return (0);
	while (s[i] != '\0')
	{
		if (!ft_isalpha(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int			ft_ischarnbr(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= 48 && s[i] <= 57)
			return (1);
		i++;
	}
	return (0);
}

void		is_n(t_dlist *list_a, t_opt *o)
{
	if (verif_order(list_a))
		o->n = 1;
}
