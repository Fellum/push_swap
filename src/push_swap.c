/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:50:39 by jleann            #+#    #+#             */
/*   Updated: 2019/04/05 18:50:40 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_stack.h"
#include "raise_error.h"
#include "free_stack.h"
#include "execute_command.h"
#include "misc.h"
#include "insertion_sort.h"

#define VALUE(a) (*(int *)(a->content))

int		is_rec_sorted(t_list *lst)
{
	char		begin_found;
	int			prev;
	t_list_node	*cur;

	begin_found = 0;
	cur = lst->begin->next;
	prev = *(int *)(lst->begin->content);
	while (cur)
	{
		if (*(int *)(cur->content) < prev)
		{
			if (begin_found)
				return (0);
			else
				begin_found = 1;
		}
		prev = VALUE(cur);
		cur = cur->next;
	}
	if (VALUE(lst->begin) < VALUE(lst->end) && begin_found)
		return (0);
	else
		return (1);
}

void	prepare_stcks(t_list *st_a, t_list *st_b)
{
	t_list_node	*max;
	t_list_node	*min;
	t_list_node	*med;
	t_list_node	*cur;

	max = ft_lstmax(st_a, more);
	min = ft_lstmax(st_a, less);
	med = find_med(st_a);
	cur = st_a->begin;
	while (st_a->len != 3)
	{
		if (cur != max && cur != min && cur != med)
		{
			while (cur != st_a->begin)
				execute_command("ra", st_a, st_b, 1);
			execute_command("pb", st_a, st_b, 1);
			cur = st_a->begin;
		}
		else
			cur = cur->next;
	}
	if (!is_rec_sorted(st_a))
		execute_command("sa", st_a, st_b, 1);
}

void	rotate_till_sorted(t_list *lst)
{
	int pos;

	pos = find_min_pos(lst);
	if (pos >= (((int)(lst->len) + 1) / 2))
	{
		pos = (int)(lst->len) - pos;
		while (pos--)
			execute_command("rra", lst, NULL, 1);
	}
	else
		while (pos--)
			execute_command("ra", lst, NULL, 1);
}

void	sort_stack(t_list *st_a, t_list *st_b)
{
	if (!is_rec_sorted(st_a))
	{
		prepare_stcks(st_a, st_b);
		insertion_sort(st_a, st_b);
	}
	rotate_till_sorted(st_a);
}

int		main(int argc, char **argv)
{
	t_list	*st_a;
	t_list	*st_b;

	st_a = ft_lstinit();
	st_b = ft_lstinit();
	if (argc > 1)
	{
		if (read_stack(st_a, argc, argv) != 0)
			raise_error();
		sort_stack(st_a, st_b);
		free_stack(st_a);
		free_stack(st_b);
	}
	else
		raise_error();
	return (0);
}
