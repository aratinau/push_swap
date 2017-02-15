/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 18:22:35 by aratinau          #+#    #+#             */
/*   Updated: 2015/06/22 17:56:25 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sa(t_dlist *p_list_a, char c)
{
	t_dlist	*tmp;
	int		a;
	int		b;

	tmp = p_list_a;
	a = p_list_a->tail->data;
	b = p_list_a->tail->prev->data;
	if (p_list_a->tail->data > p_list_a->tail->prev->data)
	{
		tmp->tail->data = b;
		tmp->tail->prev->data = a;
	}
	if (c == 'a')
		ft_putstr("sa ");
	else
		ft_putstr("sb ");
}

t_dlist		*rotate(t_dlist *p_list)
{
	t_node	*tmp;
	int		data_head;

	data_head = p_list->head->data;
	tmp = p_list->head;
	while (tmp->next != NULL)
	{
		tmp->data = tmp->next->data;
		tmp = tmp->next;
	}
	p_list->tail->data = data_head;
	return (p_list);
}

t_dlist		*rotate_inverse(t_dlist *p_list)
{
	t_node	*tmp;
	int		data_tail;

	data_tail = p_list->tail->data;
	tmp = p_list->tail;
	while (tmp->prev != NULL)
	{
		tmp->data = tmp->prev->data;
		tmp = tmp->prev;
	}
	p_list->head->data = data_tail;
	return (p_list);
}

void		push(t_dlist *list_a, t_dlist *list_b, t_opt o)
{
	dlist_prepend(list_b, list_a->tail->data, o);
	if (list_a->head->next == NULL)
	{
		list_a->tail = NULL;
		list_a->head = NULL;
		list_a->length--;
		list_a = NULL;
	}
	else
	{
		dlist_remove_id(list_a, list_a->length);
	}
}
