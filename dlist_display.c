/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 18:02:46 by aratinau          #+#    #+#             */
/*   Updated: 2015/06/22 21:17:43 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		dlist_display(t_dlist *p_list)
{
	t_node *p_temp;

	if (p_list != NULL)
	{
		p_temp = p_list->head;
		while (p_temp != NULL)
		{
			ft_putnbr(p_temp->data);
			ft_putstr(" -> ");
			p_temp = p_temp->next;
		}
	}
	ft_putendl("NULL");
}

void		dlist_state(t_dlist *list_a, t_dlist *list_b)
{
	ft_putchar('\n');
	color_str("   liste a : ", "32");
	dlist_display(list_a);
	color_str("   liste b : ", "32");
	dlist_display(list_b);
}

size_t		dlist_length(t_dlist *p_list)
{
	size_t ret;

	ret = 0;
	if (p_list != NULL)
	{
		ret = p_list->length;
	}
	return (ret);
}
