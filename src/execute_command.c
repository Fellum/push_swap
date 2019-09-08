/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:50:39 by jleann            #+#    #+#             */
/*   Updated: 2019/04/05 18:50:40 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_command.h"
#include "ft_printf.h"

void	s_command(t_list *stack)
{
	t_list_node	*first;
	t_list_node	*second;

	if (stack->len < 2)
		return ;
	first = ft_lsttake(stack);
	second = ft_lsttake(stack);
	ft_lstadd(stack, first);
	ft_lstadd(stack, second);
}

void	p_command(t_list *from, t_list *to)
{
	t_list_node	*tmp;

	if (from->len == 0)
		return ;
	tmp = ft_lsttake(from);
	ft_lstadd(to, tmp);
}

void	r_command(t_list *lst)
{
	t_list_node	*tmp;

	if (lst->len < 2)
		return ;
	tmp = ft_lsttake(lst);
	ft_lstaddend(lst, tmp);
}

void	rr_command(t_list *lst)
{
	t_list_node	*tmp;

	if (lst->len < 2)
		return ;
	tmp = ft_lsttakeend(lst);
	ft_lstadd(lst, tmp);
}

void	execute_command(char *cmd, t_list *st_a, t_list *st_b, char p)
{
	if (p)
		ft_printf("%s\n", cmd);
	if (strcmp(cmd, "sa") == 0 || strcmp(cmd, "ss") == 0)
		s_command(st_a);
	if (strcmp(cmd, "sb") == 0 || strcmp(cmd, "ss") == 0)
		s_command(st_b);
	if (strcmp(cmd, "pa") == 0)
		p_command(st_b, st_a);
	else if (strcmp(cmd, "pb") == 0)
		p_command(st_a, st_b);
	else if (strcmp(cmd, "ra") == 0 || strcmp(cmd, "rr") == 0)
		r_command(st_a);
	if (strcmp(cmd, "rb") == 0 || strcmp(cmd, "rr") == 0)
		r_command(st_b);
	if (strcmp(cmd, "rra") == 0 || strcmp(cmd, "rrr") == 0)
		rr_command(st_a);
	if (strcmp(cmd, "rrb") == 0 || strcmp(cmd, "rrr") == 0)
		rr_command(st_b);
}
