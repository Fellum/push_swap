/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:50:39 by jleann            #+#    #+#             */
/*   Updated: 2019/04/05 18:50:40 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_stack.h"
#include "read_stack.h"
#include "raise_error.h"
#include "ft_list.h"
#include "free_stack.h"

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
