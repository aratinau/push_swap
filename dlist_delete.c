/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 18:02:59 by aratinau          #+#    #+#             */
/*   Updated: 2015/06/21 21:06:25 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		dlist_delete(t_dlist **p_list)
{
	t_node *p_temp;
	t_node *p_del;

	if (*p_list == NULL)
		return ;
	p_temp = (*p_list)->head;
	while (p_temp != NULL)
	{
		p_del = p_temp;
		p_temp = p_temp->next;
		free(p_del);
	}
	free (*p_list);
	*p_list = NULL;
}

void		remove_node(t_dlist *p_list, t_node *p_temp)
{
	if (p_temp->next == NULL)
	{
		p_list->tail = p_temp->prev;
		p_list->tail->next = NULL;
	}
	else if (p_temp->prev == NULL)
	{
		p_list->head = p_temp->next;
		p_list->head->prev = NULL;
	}
	else
	{
		p_temp->next->prev = p_temp->prev;
		p_temp->prev->next = p_temp->next;
	}
}

t_dlist		*dlist_remove(t_dlist *p_list, int data)
{
	t_node	*p_temp;
	int		found;

	found = 0;
	p_temp = p_list->head;
	if (p_list != NULL)
	{
		while (p_temp != NULL && !found)
		{
			if (p_temp->data == data)
			{
				remove_node(p_list, p_temp);
				free(p_temp);
				p_list->length--;
				found = 1;
			}
			else
			{
				p_temp = p_temp->next;
			}
		}
	}
	return (p_list);
}

t_dlist		*dlist_remove_id(t_dlist *p_list, int position)
{
	t_node	*p_temp;
	int		i;

	i = 1;
	if (p_list != NULL)
	{
		p_temp = p_list->head;
		while (p_temp != NULL && i <= position)
		{
			if (position == i)
			{
				remove_node(p_list, p_temp);
				free(p_temp);
				p_list->length--;
			}
			else
			{
				p_temp = p_temp->next;
			}
			i++;
		}
	}
	return (p_list);
}
