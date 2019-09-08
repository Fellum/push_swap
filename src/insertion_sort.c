/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:50:39 by jleann            #+#    #+#             */
/*   Updated: 2019/04/05 18:50:40 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "execute_command.h"
#include "misc.h"
#include "free_stack.h"
#include "get_ops.h"

#define VALUE(a) (*(int *)(a->content))

void	free_lst_of_lsts(t_list *lst_opt)
{
	t_list_node	*cur_lst;
	t_list_node	*tmp;

	cur_lst = lst_opt->begin;
	while (cur_lst)
	{
		tmp = cur_lst->next;
		if (cur_lst->content)
			free_stack(cur_lst->content);
		free(cur_lst);
		cur_lst = tmp;
	}
	free(lst_opt);
}

t_list	*get_optimal_way(t_list *st_a, t_list *st_b)
{
	int			cur;
	t_list_node	*cur_node;
	t_list		*lst_opt;
	t_list		*tmp_list;

	cur = 0;
	cur_node = st_b->begin;
	lst_opt = ft_lstinit();
	while (cur_node)
	{
		tmp_list = get_ops(cur, VALUE(cur_node), st_a, st_b);
		ft_lstadd(lst_opt, ft_lstnew_node(tmp_list, sizeof(t_list)));
		free(tmp_list);
		cur_node = cur_node->next;
		cur++;
	}
	cur_node = ft_lstmax(lst_opt, comp_len);
	tmp_list = cur_node->content;
	cur_node->content = NULL;
	free_lst_of_lsts(lst_opt);
	return (tmp_list);
}

void	insertion_sort(t_list *st_a, t_list *st_b)
{
	t_list_node	*cur_node;
	t_list		*tmp_way;

	while (st_b->len)
	{
		tmp_way = get_optimal_way(st_a, st_b);
		cur_node = tmp_way->begin;
		while (cur_node)
		{
			execute_command(cur_node->content, st_a, st_b, 1);
			cur_node = cur_node->next;
		}
		free_stack(tmp_way);
	}
}
