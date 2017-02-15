/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 19:40:27 by aratinau          #+#    #+#             */
/*   Updated: 2015/06/24 14:30:42 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		end(t_dlist *list_a, t_dlist *list_b, t_opt *o)
{
	if (o->n != 1)
		ft_putchar('\n');
	if (list_a->doublon != 0 && o->d == 1)
	{
		color_nbr(list_a->doublon, "33;1");
		if (list_a->doublon == 1)
			color_str(" doublon a ete fusionne\n", "33;1");
		else
			color_str(" doublons ont ete fusionnes\n", "33;1");
	}
	if (o->v == 1)
	{
		color_str("===========fin de push_swap==================", "36;7");
		dlist_state(list_a, list_b);
	}
	if (o->c == 1)
	{
		color_nbr(o->count, "40;7");
		if (o->count <= 1)
			color_str(" action\n", "40;7");
		else
			color_str(" actions\n", "40;7");
	}
}

void		init(int *i, t_opt *o)
{
	*i = 1;
	o->d = 0;
	o->v = 0;
	o->c = 0;
	o->count = 0;
	o->n = 0;
}

void		init_opt(char *av, int *i, t_opt *o)
{
	if (ft_isstringalpha(av))
	{
		if (find_option(av, 'd'))
			o->d = 1;
		if (find_option(av, 'v'))
			o->v = 1;
		if (find_option(av, 'c'))
			o->c = 1;
		*i = *i + 1;
	}
}

void		after_prepend(t_dlist *list_a, t_dlist *list_b)
{
	color_str("============apres enregistrement=============", "36;7");
	dlist_state(list_a, list_b);
}

int			main(int ac, char **av)
{
	int		i;
	t_dlist	*list_a;
	t_dlist	*list_b;
	t_opt	o;

	list_a = dlist_new();
	list_b = dlist_new();
	init(&i, &o);
	is_error_arg(ac);
	init_opt(av[i], &i, &o);
	while (i < ac)
	{
		if (ft_ischarnbr(av[i]))
			list_a = dlist_prepend(list_a, ft_atoi(av[i]), o);
		else
			is_error_digit();
		i++;
	}
	is_n(list_a, &o);
	if (o.v == 1)
		after_prepend(list_a, list_b);
	push_swap(list_a, list_b, &o);
	end(list_a, list_b, &o);
	dlist_delete(&list_a);
	dlist_delete(&list_b);
}
