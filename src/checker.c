/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:50:39 by jleann            #+#    #+#             */
/*   Updated: 2019/04/05 18:50:40 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_stack.h"
#include "raise_error.h"
#include "execute_command.h"
#include "ft_printf.h"
#include "ft_get_next_line.h"
#include "free_stack.h"

int		check_result(t_list *st_a, t_list *st_b)
{
	t_list_node		*cur;
	int				tmp;

	if (st_b->len != 0)
		return (1);
	tmp = *(int *)(st_a->begin->content);
	cur = st_a->begin->next;
	while (cur)
	{
		if (tmp > *(int *)(cur->content))
			return (1);
		tmp = *(int *)(cur->content);
		cur = cur->next;
	}
	return (0);
}

int		is_command(char *cmd)
{
	if (strcmp(cmd, "sa") == 0 || strcmp(cmd, "sb") == 0 ||
		strcmp(cmd, "ss") == 0 || strcmp(cmd, "pa") == 0 ||
		strcmp(cmd, "pb") == 0 || strcmp(cmd, "ra") == 0 ||
		strcmp(cmd, "rb") == 0 || strcmp(cmd, "rr") == 0 ||
		strcmp(cmd, "rra") == 0 || strcmp(cmd, "rrb") == 0 ||
		strcmp(cmd, "rrr") == 0)
		return (1);
	else
		return (0);
}

int		read_commands(t_list *st_a, t_list *st_b)
{
	char *tmp;

	while (ft_get_next_line(STDIN_FILENO, &tmp) == GNL_SUCCESS)
	{
		if (is_command(tmp) != 1)
			return (1);
		execute_command(tmp, st_a, st_b, 0);
		free(tmp);
	}
	return (0);
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
		if (read_commands(st_a, st_b))
			raise_error();
		if (check_result(st_a, st_b) == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free_stack(st_a);
		free_stack(st_b);
	}
	return (0);
}
