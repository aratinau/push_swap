/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 17:31:22 by aratinau          #+#    #+#             */
/*   Updated: 2015/06/23 21:26:32 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		process_opt(t_dlist *list_a, t_dlist *list_b, t_opt *o)
{
	if (o->c == 1)
		o->count++;
	if (o->v == 1)
		dlist_state(list_a, list_b);
}

void		process_list_b(t_dlist *list_a, t_dlist *list_b, t_opt *o)
{
	if (verif_order(list_a))
		return ;
	if (list_b->length >= 2 && list_b->head->data < list_b->head->next->data)
	{
		list_b = rotate(list_b);
		ft_putstr("rrb ");
		process_opt(list_a, list_b, o);
	}
	if (list_b->length >= 2 && list_b->head->data < list_b->tail->data)
	{
		list_b = rotate_inverse(list_b);
		ft_putstr("rb ");
		process_opt(list_a, list_b, o);
	}
	if (list_b->length >= 2 && list_b->tail->data > list_b->tail->prev->data)
	{
		sa(list_b, 'b');
		process_opt(list_a, list_b, o);
	}
	else
	{
		push(list_a, list_b, *o);
		ft_putstr("pb ");
		process_opt(list_a, list_b, o);
	}
}

void		push_b(t_dlist *list_a, t_dlist *list_b, t_opt *o)
{
	t_node *tmp_b;

	tmp_b = list_b->head;
	while (tmp_b != NULL)
	{
		dlist_append(list_a, tmp_b->data);
		if (tmp_b->next != NULL)
			dlist_remove(list_b, tmp_b->data);
		else
		{
			list_b->tail = NULL;
			list_b->head = NULL;
			list_b->length--;
		}
		ft_putstr("pa ");
		process_opt(list_a, list_b, o);
		tmp_b = tmp_b->next;
	}
}

void		process_rra(t_dlist *lst_a, t_dlist *list_b, t_opt *o)
{
	if (lst_a->length >= 2 && lst_a->head->data < lst_a->head->next->data)
	{
		lst_a = rotate(lst_a);
		ft_putstr("rra ");
		process_opt(lst_a, list_b, o);
	}
}

void		push_swap(t_dlist *lst_a, t_dlist *list_b, t_opt *o)
{
	t_node *tmp_a;

	tmp_a = lst_a->head;
	while (!verif_order(lst_a))
	{
		process_rra(lst_a, list_b, o);
		if (lst_a->length >= 2 && lst_a->head->data < lst_a->tail->data)
		{
			lst_a = rotate_inverse(lst_a);
			ft_putstr("ra ");
			process_opt(lst_a, list_b, o);
		}
		if (lst_a->length >= 2 && lst_a->tail->data > lst_a->tail->prev->data)
		{
			sa(lst_a, 'a');
			process_opt(lst_a, list_b, o);
		}
		else
			process_list_b(lst_a, list_b, o);
	}
	push_b(lst_a, list_b, o);
	if (!verif_order(lst_a))
		push_swap(lst_a, list_b, o);
}
