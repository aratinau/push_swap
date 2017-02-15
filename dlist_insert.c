/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 18:02:54 by aratinau          #+#    #+#             */
/*   Updated: 2015/06/23 21:36:45 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist		*dlist_new(void)
{
	t_dlist *p_new;

	p_new = malloc(sizeof(*p_new));
	if (p_new != NULL)
	{
		p_new->length = 0;
		p_new->doublon = 0;
		p_new->head = NULL;
		p_new->tail = NULL;
	}
	return (p_new);
}

t_dlist		*dlist_append(t_dlist *p_list, int data)
{
	t_node *p_new;

	if (p_list != NULL)
	{
		p_new = malloc(sizeof(*p_new));
		if (p_new != NULL)
		{
			p_new->data = data;
			p_new->next = NULL;
			if (p_list->tail == NULL)
			{
				p_new->prev = NULL;
				p_list->head = p_new;
				p_list->tail = p_new;
			}
			else
			{
				p_list->tail->next = p_new;
				p_new->prev = p_list->tail;
				p_list->tail = p_new;
			}
			p_list->length++;
		}
	}
	return (p_list);
}

int			is_doublon(t_dlist *p_list, int data)
{
	t_dlist		*tmp;
	t_node		*node;

	tmp = p_list;
	node = tmp->head;
	while (node != NULL)
	{
		if (node->data == data)
		{
			tmp->doublon++;
			return (1);
		}
		node = node->next;
	}
	return (0);
}

void		process_prepend(t_dlist *p_list, t_node *p_new, int data)
{
	p_new->data = data;
	p_new->prev = NULL;
	if (p_list->tail == NULL)
	{
		p_new->next = NULL;
		p_list->head = p_new;
		p_list->tail = p_new;
	}
	else
	{
		p_list->head->prev = p_new;
		p_new->next = p_list->head;
		p_list->head = p_new;
	}
	p_list->length++;
}

t_dlist		*dlist_prepend(t_dlist *p_list, int data, t_opt o)
{
	t_node *p_new;

	if (o.d == 1)
	{
		if (is_doublon(p_list, data) || p_list == NULL)
			return (p_list);
	}
	if (o.d == 0)
	{
		if (is_doublon(p_list, data) || p_list == NULL)
		{
			color_str("ERROR doublon, utilisez option -d pour les fusionner\n",\
			"31;7");
			exit (0);
		}
	}
	p_new = malloc(sizeof(*p_new));
	if (p_new != NULL)
		process_prepend(p_list, p_new, data);
	return (p_list);
}
