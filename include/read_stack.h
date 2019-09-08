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

#ifndef READ_STACK_H
# define READ_STACK_H

# include "ft_list.h"

typedef struct	s_rubbish
{
	int		numa;
	int		numb;
	int		nums;
	char	*cmda;
	char	*cmdb;
	char	*cmds;
}				t_rubbish;

int				read_stack(t_list *stack, int argc, char **argv);

#endif
