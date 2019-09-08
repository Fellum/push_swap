/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:50:39 by jleann            #+#    #+#             */
/*   Updated: 2019/04/05 18:50:40 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#define LSTLSTLEN(a) (((t_list *)(((t_list_node *)a)->content))->len)

int			more(void *a, void *b)
{
	return (*(int *)(((t_list_node *)a)->content) -
		*(int *)(((t_list_node *)b)->content));
}

int			less(void *a, void *b)
{
	return (*(int *)(((t_list_node *)b)->content) -
			*(int *)(((t_list_node *)a)->content));
}

t_list_node	*find_med(t_list *st)
{
	t_list_node	*cur;
	t_list_node	*another_cur;
	int			lesser;
	int			greater;

	cur = st->begin;
	while (cur)
	{
		lesser = 0;
		greater = 0;
		another_cur = st->begin;
		while (another_cur)
		{
			if (another_cur != cur)
				more(another_cur, cur) > 0 ? greater++ : lesser++;
			another_cur = another_cur->next;
		}
		if (greater - lesser < 2 && greater - lesser > -2)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

int			comp_len(void *a, void *b)
{
	return (LSTLSTLEN(b) - LSTLSTLEN(a));
}

int			find_min_pos(t_list *lst)
{
	int			prev;
	t_list_node	*cur;
	int			pos;
	int			min_pos;

	prev = (*(int *)(lst->begin->content));
	cur = lst->begin->next;
	pos = 1;
	min_pos = 0;
	while (cur)
	{
		if (prev > (*(int *)(cur->content)))
		{
			min_pos = pos;
			prev = (*(int *)(cur->content));
		}
		pos++;
		cur = cur->next;
	}
	return (min_pos);
}
