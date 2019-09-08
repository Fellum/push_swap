/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:50:39 by jleann            #+#    #+#             */
/*   Updated: 2019/04/05 18:50:40 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "raise_error.h"

int		read_int(char *str, int *tmp)
{
	long			res;
	int				sign;
	int				treshold_dig;

	while (*str && *str == '0')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	treshold_dig = sign == 1 ? 2147483647 % 10 : (-2147483648 % 10) * -1;
	res = 0;
	while (*str && ft_isdigit(*str))
	{
		if (res > 2147483647 / 10 || (res == 2147483647 / 10 &&
		(*str - '0') > treshold_dig))
			return (1);
		res = res * 10 + (*str - '0');
		str++;
	}
	*tmp = (int)res * sign;
	return (*str != 0);
}

int		is_unique(int value, t_list *lst)
{
	t_list_node	*cur;

	cur = lst->begin;
	while (cur)
	{
		if (value == *(int *)(cur->content))
			return (0);
		cur = cur->next;
	}
	return (1);
}

int		is_string_correct(char *str)
{
	while (*str)
	{
		if ((*str < '0' || *str > '9') && *str != ' ' && *str != '-' &&
			*str != '+')
			return (0);
		if (*str == '-' || *str == '+')
		{
			if (*(str + 1) < '0' || *(str + 1) > '9')
				return (0);
		}
		str++;
	}
	return (1);
}

void	free_string_arr(char **arr)
{
	int cur;

	cur = 0;
	while (arr[cur])
	{
		free(arr[cur]);
		cur++;
	}
	free(arr);
}

int		read_stack(t_list *stack, int argc, char **argv)
{
	char	**nums;
	int		cur;
	int		tmp;
	int		cur_arg;

	cur_arg = 1;
	while (cur_arg < argc)
	{
		if (!is_string_correct(argv[cur_arg]))
			raise_error();
		cur = 0;
		nums = ft_strsplit(argv[cur_arg++], ' ');
		while (nums[cur])
		{
			if (read_int(nums[cur++], &tmp) != 0)
				raise_error();
			if (is_unique(tmp, stack) == 0)
				raise_error();
			ft_lstaddend(stack, ft_lstnew_node(&tmp, sizeof(int)));
		}
		free_string_arr(nums);
	}
	return (0);
}
