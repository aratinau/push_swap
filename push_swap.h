/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 16:24:54 by aratinau          #+#    #+#             */
/*   Updated: 2015/06/24 14:31:01 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "includes/libft.h"

typedef struct		s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_dlist
{
	size_t			length;
	size_t			doublon;
	struct s_node	*tail;
	struct s_node	*head;
}					t_dlist;

typedef	struct		s_opt
{
	int				d;
	int				v;
	int				c;
	int				count;
	int				n;
}					t_opt;

void				color_str(char *s, char *opt);
void				color_nbr(int n, char *opt);
t_dlist				*dlist_new(void);
t_dlist				*dlist_append(t_dlist *p_list, int data);
t_dlist				*dlist_prepend(t_dlist *p_list, int data, t_opt o);
void				dlist_delete(t_dlist **p_list);
void				dlist_display(t_dlist *p_list);
t_dlist				*dlist_remove(t_dlist *p_list, int data);
t_dlist				*dlist_remove_id(t_dlist *p_list, int position);
size_t				dlist_length(t_dlist *p_list);
void				sa(t_dlist *p_list_a, char c);
t_dlist				*rotate(t_dlist *p_list);
t_dlist				*rotate_inverse(t_dlist *p_list);
void				push(t_dlist *list_a, t_dlist *list_b, t_opt o);
int					verif_order(t_dlist *p_list_a);
int					find_option(char *s, const char c);
int					ft_isstringalpha(char *s);
void				push_swap(t_dlist *list_a, t_dlist *list_b, t_opt *o);
void				dlist_state(t_dlist *list_a, t_dlist *list_b);
void				is_error_arg(int ac);
void				is_error_digit(void);
int					ft_ischarnbr(char *s);
void				is_n(t_dlist *list_a, t_opt *o);

#endif
