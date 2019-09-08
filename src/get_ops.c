/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:50:39 by jleann            #+#    #+#             */
/*   Updated: 2019/04/05 18:50:40 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <read_stack.h>
#include "libft.h"
#include "get_ops.h"

t_list	*create_list(t_rubbish *k)
{
	t_list		*res;

	res = ft_lstinit();
	while (k->numa--)
		ft_lstaddend(res, ft_lstnew_node(k->cmda, ft_strlen(k->cmda) + 1));
	while (k->numb--)
		ft_lstaddend(res, ft_lstnew_node(k->cmdb, ft_strlen(k->cmdb) + 1));
	while (k->nums--)
		ft_lstaddend(res, ft_lstnew_node(k->cmds, ft_strlen(k->cmds) + 1));
	ft_lstaddend(res, ft_lstnew_node("pa", 3));
	return (res);
}

int		get_position_in_a(int value, t_list *st_a)
{
	t_list_node	*cur_node;
	t_list_node	*prev;
	int			cur_pos;

	cur_pos = 0;
	cur_node = st_a->begin;
	while (cur_node)
	{
		prev = cur_node->prev ? cur_node->prev : st_a->end;
		if (*(int *)(prev->content) < value &&
			*(int *)(cur_node->content) > value)
			return (cur_pos);
		cur_node = cur_node->next;
		cur_pos++;
	}
	return (0);
}

t_list	*get_ops(int pos, int value, t_list *st_a, t_list *st_b)
{
	t_rubbish	k;
	int			tmp;

	k.cmdb = (pos >= ((int)(st_b->len) + 1) / 2) ? "rrb" : "rb";
	k.numb = (pos >= ((int)(st_b->len) + 1) / 2) ? ((int)(st_b->len) - pos) :
			(pos);
	tmp = get_position_in_a(value, st_a);
	k.cmda = (tmp >= (int)(st_a->len) / 2) ? "rra" : "ra";
	k.numa = (tmp >= (int)(st_a->len) / 2) ? ((int)(st_a->len) - tmp) : (tmp);
	k.nums = 0;
	if ((tmp >= (int)(st_a->len) / 2) == (pos >= ((int)(st_b->len) + 1) / 2))
	{
		k.nums = k.numa > k.numb ? k.numb : k.numa;
		k.numa -= k.nums;
		k.numb -= k.nums;
		k.cmds = (tmp >= (int)(st_a->len) / 2) ? "rrr" : "rr";
	}
	return (create_list(&k));
}
